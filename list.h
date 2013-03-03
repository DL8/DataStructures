#ifndef _LIST_H_
#define _LIST_H_

#include <cstdlib>
using std::abs;

namespace DataStructures {

	template<class T> class List {
		// subtypes definitions
		struct Node {
			T value;
			Node *prev;
			Node *next;
		};
		Node *nodeCreate (const T &value) {
			Node *ret = new Node;
			ret->prev = nullptr;
			ret->next = nullptr;
			ret->value = value;
			return ret;
		}

		void nodeDestroy (Node *head) {
			if (head == nullptr) {
				return;
			}

			while (head != nullptr) {
				Node *tmp = head;
				head = head->next;
				delete tmp;
				tmp = nullptr;
			}
		}
	public:
		class Iterator {
			Node *current;
			Node *last;
		public:
			/**
			 * @brief creates a new iterator with the given position
			 * nullptr is treated as one after the last element
			 * @param position the initial position
			 */
			Iterator (Node *position, Node *head) : current (position), last (head) {
				while ( (last != nullptr) && (last->next != nullptr)) {
					last = last->next;
				}
			}

			/**
			 * @brief suffix increment
			 * @return *this
			 */
			Iterator &operator++() {
				current = current->next;
				return *this;
			}

			/**
			 * @brief prefix increment
			 * @return *this
			 */
			Iterator &operator++ (int) {
				return operator++();
			}

			/**
			 * @brief suffix decrement
			 * @return *this
			 */
			Iterator &operator--() {
				if (current == nullptr) {
					current = last;
				} else {
					current = current->prev;
				}
				return *this;
			}

			/**
			 * @brief prefix decrement
			 * @return *this
			 */
			Iterator &operator-- (int) {
				return operator--();
			}

			/**
			 * @brief iterator dereference
			 * @return a reference to the value at the iterator's position
			 */
			T &operator*() {
				return current->value;
			}

			/**
			 * @brief iterator const dereference
			 * @return a const reference to the value at the iterator's position
			 */
			const T &operator*() const {
				return current->value;
			}

			/**
			 * @brief iterator comparison
			 * @param other the iterator to compare with
			 * @return true if both iterators point to the same element of the same list
			 */
			bool operator== (const Iterator &other) const {
				return this->current == other.current;
			}

			/**
			 * @brief iterator comparison
			 * @param other the iterator to compare with
			 * @return false if both iterators point to the same element of the same list
			 */
			bool operator!= (const Iterator &other) const {
				return ! (*this == other);
			}

			/**
			 * @brief iterator +=
			 * @param offset offset to shift the current iterator
			 * @return *this
			 */
			Iterator &operator+= (int offset) {
				bool add = (offset > 0);
				offset = abs (offset);
				if ( (offset > 0) && (current == nullptr)) {
					current = last;
					offset--;
				}
				while (offset > 0) {
					current = add ? (current->next) : (current->prev);
					offset--;
				}
				return *this;
			}

			/**
			 * @brief iterator -=
			 * @param offset offset to shift the current iterator
			 * @return *this
			 */
			Iterator &operator-= (int offset) {
				return *this += -offset;
			}

			Iterator operator+ (const int offset) const {
				Iterator ret = *this;
				ret += offset;
				return ret;
			}

			Iterator operator- (int offset) const {
				Iterator ret = *this;
				ret -= offset;
				return ret;
			}

			friend class List;
		};
	private:
		Node *head;
	public:
		/**
		 * @brief creates an empty list
		 */
		List() : head (nullptr) {}

		List (const T &data) : List() {
			head = nodeCreate (data);
		}

		/**
		 * @brief copy c-tor
		 * @param src the original list
		 */
		List (const List &src) : List() {
			Node *current = nullptr;
			for (Iterator i = src.begin(); i != src.end(); ++i) {
				if (head == nullptr) {
					head = nodeCreate (*i);
					current = head;
				} else {
					current->next = nodeCreate (*i);
					current->next->prev = current;
					current = current->next;
				}
			}
		}

		virtual ~List() {
			nodeDestroy (head);
		}

		Iterator begin() const {
			return Iterator (head, head);
		}

		Iterator end() const {
			return Iterator (nullptr, head);
		}

		/**
		 * @brief inserts a new item before the given iterator
		 * @param before an iterator before which the item will be inserted
		 * @param data the data that shall be added
		 * @return *this
		 */
		List &insert (Iterator &before, const T &data) {
			// TODO
			return *this;
		}
	};
}

#endif






