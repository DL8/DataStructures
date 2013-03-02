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
	public:
		class Iterator {
			Node *current;
		public:
			Iterator (Node *position) : current (position) {}

			Iterator &operator++() {
				current = current->next;
				return *this;
			}

			Iterator &operator--() {
				current = current->prev;
				return *this;
			}

			T &operator*() {
				return current->value;
			}

			const T &operator*() const {
				return *this;
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

		List() {}

		List (const T &data) : List() {
			head = new Node;
			head->prev = nullptr;
			head->next = nullptr;
			head->value = data;
		}

		List (const List &src) : List() {
			Node *current = nullptr;
for (auto & i: src) {
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
			// TODO (in the meantime we shall be leaking)
		}

		Iterator begin() {
			return Iterator (head);
		}

		Iterator begin() const {
			return begin();
		}

		Iterator end() {
			// TODO: is that a good idea?
			// (prevents the ability to reverse-iteration)
			return Iterator (nullptr);
		}

		Iterator end() const {
			return end();
		}
	};
}

#endif
