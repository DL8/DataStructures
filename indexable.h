#ifndef _INDEXABLE_H_
#define _INDEXABLE_H_

namespace DataStructures {

	/**
	 * @brief an interface of a data type whose elements can be accessed via index
	 */
	template<class T> class Indexable {
	public:
		/**
		 * @brief index-safe element access
		 * @param index the index
		 * @return a reference to the element at index
		 */
		virtual T &at (const int) = 0;

		/**
		 * @brief index-unsafe element access
		 * @param index the index
		 * @return a reference to the element at index
		 */
		virtual T &operator[] (const int) = 0;

		/**
		 * @brief const index-unsafe element access
		 * @param index the index
		 * @return a const reference to the element at index
		 */
		virtual const T &operator[] (const int index) const {
			return *this[index];
		}
	};

}

#endif
