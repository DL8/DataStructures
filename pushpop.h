#ifndef _PUSHPOP_H_
#define _PUSHPOP_H_

namespace DataStructures {

	/**
	 * @brief an interface for a data structure with the ability to push and pop an item (e.g queue or stack)
	 * contains methods to push(), pop() and dereference (const and non-const)
	 */
	template<class T> class PushPop {
		/**
		 * @brief actually adds an element into the data type (called from push())
		 * @param data the content to push
		 */
		virtual void pushElement (const T &data) = 0;
	public:
		PushPop() {}
		virtual ~PushPop() {}

		/**
		 * @brief adds an element into the data type
		 * @param data the content to push
		 * @return *this
		 */
		virtual PushPop &push (const T &data) {
			pushElement (data);
			return *this;
		}

		/**
		 * @brief returns the element from top the data type and removes it
		 * @return the element at the top of the data type
		 */
		virtual T pop() = 0;

		/**
		 * @brief dereference
		 * @return a reference to the head of the data type
		 */
		virtual T &operator*() = 0;

		/**
		 * @brief const dereference
		 * @return a const reference to the head of the data type
		 */
		virtual const T &operator*() const {
			return * (*this);
		}
	};

}

#endif
