#ifndef _BASE_ITERATOR_H_
#define _BASE_ITERATOR_H_

#include <typeinfo>

namespace DataStructures {

	/**
	 * @brief a base class of an iterator
	 * in order to be valid, the iterator also has to implement increment, decrement, +=, -=, + and -
	 */
	template<class T, class Overriden> class BaseIterator {
	protected:
	public:
		BaseIterator() = default;

		virtual ~BaseIterator() {}

		/**
		 * @brief dereference
		 * @return a reference to the value at the iterator's position
		 */
		virtual T &operator*() = 0;

		/**
		 * @brief const dereference
		 * @return a const reference to the value
		 */
		virtual const T &operator*() const {
			return * (*this);
		}

		/**
		 * @brief iterators comparison
		 * @param other iterator to compare with
		 * @return true if both iterators are equal
		 */
		virtual bool operator== (const Overriden &other) const = 0;

		/**
		 * @brief iterators comparison
		 * @param other iterator to compare with
		 * @return true if !(*this == other)
		 */
		virtual bool operator!= (const Overriden &other) const {
			return ! (*this == other);
		}

		virtual Overriden &operator++() = 0;

		virtual Overriden &operator++ (int) = 0;

		virtual Overriden &operator--() = 0;

		virtual Overriden &operator-- (int) = 0;

		virtual Overriden &operator+= (const int) = 0;

		virtual Overriden &operator-= (const int offset) {
			return *this += (-offset);
		}

		virtual Overriden operator+ (const int) const = 0;

		virtual Overriden operator- (const int offset) const {
			return *this + (-offset);
		}
	};

}

#endif
