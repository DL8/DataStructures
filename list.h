#ifndef _LIST_H_
#define _LIST_H_

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
		public:
			Iterator (Node *position) : current (position) {}

			Iterator &operator++() {
				current = current->next;
				return *this;
			}

			Iterator &operator++ (int) {
				return operator++();
			}

			Iterator &operator--() {
				current = current->prev;
				return *this;
			}

			Iterator &operator-- (int) {
				return operator--();
			}

			T &operator*() {
				return current->value;
			}

			const T &operator*() const {
				return current->value;
			}

			bool operator== (const Iterator &other) const {
				return this->current == other.current;
			}

			bool operator!= (const Iterator &other) const {
				return ! (*this == other);
			}
		};
	private:
		Node *head;
	public:
		List() : head (nullptr) {}

		List (const T &data) : List() {
			head = nodeCreate (data);
		}

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
			return Iterator (head);
		}

		Iterator end() const {
			return Iterator (nullptr);
		}
	};
}

#endif
