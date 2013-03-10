#ifndef _CONST_ITERATOR_H_
#define _CONST_ITERATOR_H_

#include <typeinfo>
#include "comparable.h"

namespace DataStructures {

	/**
	 * @brief a base class of a const iterator (doesn't allow modifications)
	 * @param T type of the contents
	 * @param Overriden type of the data type (usually the type containing the iterator)
	 */
	template<class T, class Overriden> class ConstIterator: public Comparable<Overriden> {
	public:
		/**
		 * @brief const dereference
		 * @return a const reference to the value
		 */
		virtual const T &operator*() const = 0;

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
