#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "pushpop.h"
#include "list.h"
#include "exceptions.h"

namespace DataStructures {

	template<class T> class Queue: public PushPop<T> {
		List<T> content;

		/**
		 * @brief actually adds an element into the data type (called from push())
		 * @param data the content to push
		 */
		virtual void pushElement (const T &data) override {
			content.append (data);
		}
	public:
		/**
		 * @brief creates an empty queue
		 */
		Queue() : content (List<T>()) {}

		/**
		 * @brief checks if the queue is empty
		 * @return true if the queue is empty
		 */
		bool empty() const {
			return content.empty();
		}

		/**
		 * @brief returns the size of the queue
		 * @return the size of the queue
		 */
		int size() const {
			return content.size();
		}

		/**
		 * @brief gets the head of the queue
		 * @return the head of the queue
		 */
		virtual T pop() override {
			if (empty()) {
				throw Empty();
			}
			T ret = * (*this);
			content.erase (content.begin());
			return ret;
		}

		/**
		 * @brief clears the content of the queue
		 * @return *this
		 */
		Queue &clear() {
			content.clear();
			return *this;
		}

		/**
		 * @brief reference to the head of the queue
		 * @return a reference to the head of the queue
		 */
		virtual T &operator*() override {
			return *content.begin();
		}

		/**
		 * @brief compares the current queue with another
		 * @param other the queue to compare with
		 * @return true if both queues contain the same elements at the same order
		 */
		bool operator== (const Queue &other) const {
			return this->content == other.content;
		}

		/**
		 * @brief compares the current queue with another
		 * @param other the queue to compare with
		 * @return false if both queues contain the same elements at the same order
		 */
		bool operator!= (const Queue &other) const {
			return ! (*this == other);
		}
	};

}

#endif
