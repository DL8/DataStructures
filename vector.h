#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "list.h"
#include "exceptions.h"
#include "indexable.h"
#include "comparable.h"
#include "base_iterator.h"

namespace DataStructures {

	/**
	 * @brief vector: a dynamic array
	 */
	template<class T> class Vector: public Indexable<T>, public Comparable<Vector<T>> {
	private:
		typedef typename List<T>::Iterator ListIterator;
	public:
		class Iterator: public BaseIterator<T, Iterator> {
			ListIterator current;
		public:
			/**
			 * @brief creates a new iterator that points at the given position
			 * @param pos position to point at
			 */
			Iterator (const ListIterator &pos) : current (pos) {}

			/**
			 * @brief dereference
			 * trying to access the end of list will throw OutOfBounds
			 * trying to access invalid iterators will cause an undefined behavior
			 * @return reference to the value at the current position
			 */
			T &operator*() override {
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

			friend class Vector;
		};
	private:
		List<T> content;
	public:
		Vector() {}

		Vector (const Vector &src) : content (src.content) {}

		T &at (const int index) override {
			if ( (index < 0) || (index >= content.size())) {
				throw OutOfBounds();
			}
			return (*this) [index];
		}

		T &operator[] (const int index) override {
			return * (content.begin() + index);
		}

		Iterator begin() {
			return Iterator (content.begin());
		}

		Iterator end() {
			return Iterator (content.end());
		}

		bool empty() const {
			return content.empty();
		}

		int size() const {
			return content.size();
		}

		Vector &clear() {
			content.clear();
			return *this;
		}

		Vector &insert (const Iterator &before, const T &data) {
			content.insert (before.current, data);
			return *this;
		}

		Vector &append (const T &data) {
			content.append (data);
			return *this;
		}

		Vector &erase (const Iterator &position) {
			content.erase (position.current);
			return *this;
		}

		bool operator== (const Vector &other) const override {
		    return this->content == other.content;
		}
	};
}

#endif
