#ifndef _ITERABLE_H_
#define _ITERABLE_H_

#include "base_iterator.h"

namespace DataStructures {

	/**
	 * @brief interface of an iterable data type
	 */
	template<class Overidden> class Iterable {
	public:
		Iterable() = default;

		virtual ~Iterable() {}

		/**
		 * @brief returns an iterator to the beginning
		 * @return an iterator to the beginning of the data type
		 */
		virtual Overidden begin() const = 0;

		/**
		 * @brief return and iterator to after the end
		 * @return an iterator to after the end of the data type
		 */
		virtual Overidden end() const = 0;
	};

}

#endif
