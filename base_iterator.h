#ifndef _BASE_ITERATOR_H_
#define _BASE_ITERATOR_H_

#include <typeinfo>
#include "comparable.h"
#include "const_iterator.h"

namespace DataStructures {

	/**
	 * @brief a base class of an iterator (allows modification)
	 * @param T type of the contents
	 * @param Overriden type of the data type (usually the type containing the iterator)
	 * in order to be valid, the iterator also has to implement increment, decrement, +=, -=, + and -
	 */
	template<class T, class Overriden> class BaseIterator: public ConstIterator<T, Overriden> {
	public:
		/**
		 * @brief dereference
		 * @return a reference to the value at the iterator's position
		 */
		virtual T &operator*() = 0;

		/**
		 * @brief const dereference
		 * @return a const reference to the value
		 */
		virtual const T &operator*() const override {
			return * (*this);
		}
	};

}

#endif
