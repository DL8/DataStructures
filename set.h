#ifndef _SET_H_
#define _SET_H_

#include "comparable.h"
#include "container.h"
#include "list.h"
#include "exceptions.h"
#include "const_iterator.h"

namespace DataStructures {

	/**
	 * @brief an unrordered collection of elements
	 * elements in the set must support comparison, assignment and copy
	 * @param T the type of the elements
	 */
	template<class T> class Set: public Container<Set<T>>, public Comparable<Set<T>> {
	private:
		typedef typename List<T>::Iterator ListIterator;
	public:
		class Iterator: public ConstIterator<T, Iterator> {
			ListIterator current;
		public:
			/**
			 * @brief creates a new iterator that points at the given position
			 * @param pos position to point at
			 */
			Iterator (const ListIterator &pos) : current (pos) {}

			/**
			 * @brief const dereference
			 * trying to access the end of list will throw OutOfBounds
			 * trying to access invalid iterators will cause an undefined behavior
			 * @return reference to the value at the current position
			 */
			const T &operator*() const override {
			    return *current;
			}

			/**
			 * @brief prefix increment
			 * invalid increment will cause an undefined behavior
			 * @return *this
			 */
			Iterator &operator++() override {
				++current;
				return *this;
			}

			/**
			 * @brief suffix increment
			 * @return *this
			 */
			Iterator &operator++ (int) override {
				current++;
				return *this;
			}

			/**
			 * @brief prefix decrement
			 * invalid decrement will cause an undefined behavior
			 * @return *this
			 */
			Iterator &operator--() override {
				--current;
				return *this;
			}

			/**
			 * @brief suffix decrement
			 * @return *this
			 */
			Iterator &operator-- (int) override {
				current--;
				return *this;
			}

			/**
			 * @brief adds offset to the iterator
			 * invalid addition will cause an undefined behavior
			 * @param offset
			 * @return *this
			 */
			Iterator &operator+= (int offset) override {
				current += offset;
				return *this;
			}

			/**
			 * @brief comparison
			 * @param other iterator to compare with
			 * @return true if both iterators point at the same element
			 */
			bool operator== (const Iterator &other) const override {
			    return this->current == other.current;
			}

			/**
			 * @brief adds offset to an iterator
			 * invalid addition will cause an undefined behavior
			 * @param offset the offset to add
			 * @return the new iterator
			 */
			Iterator operator+ (const int offset) const override {
			    Iterator ret = *this;
			    ret += offset;
			    return ret;
			}

			friend class Set;
		};
	private:
		List<T> content;

		/**
		 * @brief gets an iterator to the given element
		 * @param data element to look for
		 * @return an iterator to the given element, or to the end of the list if doesn't exist
		 */
		typename List<T>::Iterator getPosition (const T &data) const {
			auto pos = content.begin();
			while (pos != content.end()) {
				if (*pos == data) {
					return pos;
				}
				pos++;
			}
			return pos;
		}
	public:
		int size() const override {
		    return content.size();
		}

		bool empty() const override {
		    return content.empty();
		}

		Set &clear() override {
			content.clear();
			return *this;
		}

		/**
		 * @brief checks if the given element is in the set
		 * @param data element to check
		 * @return true if the set contains the element
		 */
		bool contains (const T &data) const {
			return (getPosition (data) != content.end());
		}

		/**
		 * @brief adds an element to the set
		 * if the element exists, nothing is done
		 * @param data the element to insert
		 * @return *this
		 */
		Set &insert (const T &data) {
			if (contains (data)) {
				return *this;
			}
			content.append (data);
			return *this;
		}

		/**
		 * @brief removes the given element from the set
		 * @param data the element to remove
		 * @return *this
		 */
		Set &erase (const T &data) {
			auto pos = getPosition (data);
			if (pos != content.end()) {
				content.erase (pos);
			} else {
				throw ElementDoesNotExist();
			}
			return *this;
		}
		
		/**
		 * @brief iterator to the beginning
		 * @return an iterator to the beginning of the set (pseudo-random order)
		 */
		Iterator begin() const {
			return Iterator(content.begin());
		}
		
		/**
		 * @brief iterator to the end
		 * @return an iterator to the after end of the set
		 */
		Iterator end() const {
			return Iterator(content.end());
		}

		/**
		 * @brief intersect the set with the given set
		 * @param other the set to intersect with
		 * @return a new set which is the intersection of the two sets
		 */
		Set intersect (const Set &other) const {
			Set ret;
for (auto & i: content) {
				if (other.contains (i)) {
					ret.insert (i);
				}
			}
			return ret;
		}

		/**
		 * @brief unites the set with the given set
		 * @param other the set to unite
		 * @return a new set which is the union of the two sets
		 */
		Set unite (const Set &other) const {
			Set ret;
for (auto & i: content) {
				ret.insert (i);
			}
for (auto & i: other.content) {
				ret.insert (i);
			}
			return ret;
		}

		/**
		 * @brief checks if the set is a subset of the given set
		 * @param other set to compare with
		 * @return true if the set is a subset of the given set
		 */
		bool operator<= (const Set &other) const {
for (auto & i: content) {
				if (!other.contains (i)) {
					return false;
				}
			}
			return true;
		}

		/**
		 * @brief checks if the set is a superset of the given set
		 * @param other set to compare with
		 * @return true if the set is a superset of the given set
		 */
		bool operator>= (const Set &other) const {
			return (other <= *this);
		}

		/**
		 * @brief checks if the set is aproper  subset of the given set
		 * @param other set to compare with
		 * @return true if the set is a proper subset of the given set
		 */
		bool operator< (const Set &other) const {
			return ( (*this <= other) && (*this != other));
		}

		/**
		 * @brief checks if the set is a proper superset of the given set
		 * @param other set to compare with
		 * @return true if the set is a proper superset of the given set
		 */
		bool operator> (const Set &other) const {
			return (other < *this);
		}

		/**
		 * @brief checks if the set is equal to the given set
		 * @param other set to compare with
		 * @return true if both sets are equal
		 */
		bool operator== (const Set &other) const override {
		    return ( (*this <= other) && (other <= *this));
		}

		bool operator!= (const Set &other) const override {
		    return ! (*this == other);
		}
	};

}

#endif
