#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "pushpop.h"
#include "list.h"
#include "exceptions.h"
#include "container.h"

namespace DataStructures {

	template<class T> class Queue: public Container<Queue<T>>, public PushPop<T, Queue<T>>, public Comparable<Queue<T>> {
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
		 * @brief returns the size of the queue
		 * @return the size of the queue
		 */
		int size() const override {
			return content.size();
		}
		
		/**
		 * @brief checks if the container is empty
		 * @return true if the container is empty
		 */
		bool empty() const override {
			return (size() == 0);
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
		Queue &clear() override {
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
		bool operator== (const Queue &other) const override {
		    return this->content == other.content;
		}
	};

}

#endif
