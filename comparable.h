#ifndef _COMPARABLE_H_
#define _COMPARABLE_H_

namespace DataStructures {

	/**
	 * @brief an interface for a comparable (== and !=) object
	 * @param Overriden the type to compare with (usually the same type as the inheriting class)
	 */
	template<class Overriden> class Comparable {
	public:
		/**
		 * @brief comparison
		 * @param other object to compare with
		 * @return true if equal
		 */
		virtual bool operator== (const Overriden &) const = 0;

		/**
		 * @brief comparison
		 * @param other object to compare with
		 * @return false if equal
		 */
		virtual bool operator!= (const Overriden &other) const {
			return ! (*this == other);
		}
	};

}

#endif
