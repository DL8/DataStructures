#ifndef _CONTAINER_H_
#define _CONTAINER_H_

namespace DataStructures {

	/**
	 * @brief interface of a container (ordered/unordered)
	 * @param Overriden the type of the container (so clear() returns the correct type)
	 */
	template<class Overriden> class Container {
	public:
		/**
		 * @brief size of the container
		 * @return the size of the container
		 */
		virtual int size() const = 0;

		/**
		 * @brief clears the contents of the container
		 * @return should be *this
		 */
		virtual Overriden &clear() = 0;

		/**
		 * @brief checks if the container is empty
		 * @return true if the container is empty
		 */
		virtual bool empty() const {
			return (size() == 0);
		}
	};

}

#endif