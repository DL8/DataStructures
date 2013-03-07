#include <iostream>

namespace DataStructures  {
 
  template <class T> class Stack {
    // subtypes definitions
    struct Node
    {
      T value;
      Node *prev;
    };
    
		/**
		 * @brief creates a new single node without initializing value
		 * @return a pointer to the new node
		 */
		Node *nodeCreate () const {
			Node *ret = new Node;
			ret->prev = nullptr;
			return ret;
		}
		/**
		 * @brief creates a new single node with the given value
		 * @param value value for the node
		 * @return a pointer to the new node
		 */
		Node *nodeCreate (const T &value) const {
			Node *ret = nodeCreate();
			ret->value = value;
			return ret;
		}
		
		/**
		 * @brief forward-destroys the given Stack
		 * @param head the head of the list
		 */
		void nodeDestroy (Node *&head) const {
			if (head == nullptr) {
				return;
			}
			
			else{
			  
			Node *current = head;

			while (current != nullptr) {
				Node *tmp = current;
				current = current->prev;
				delete tmp;
				tmp = nullptr;
			}
			head = nullptr;
			}
		}
		
	public:
		class Iterator {
			Node *current;

			Iterator() : current (nullptr) {}
		public:
			/**
			 * @brief creates a new iterator that points at the given position
			 * @param pos position to point at
			 */
			Iterator (Node *pos) : Iterator() {
				current = pos;
			}

			/**
			 * @brief dereference
			 * @return reference to the value at the current position
			 */
			T &operator*() {
				return current->value;
			}

			/**
			 * @brief dereference
			 * @return const reference to the value at the current position
			 */
			const T &operator*() const {
				return * (*this);
			}

			/**
			 * @brief suffix increment
			 * @return *this
			 */
			
			
			   /*
			Iterator &operator++() {
				current = current->next;
				return *this;
			}  */


			/**
			 * @brief prefix increment
			 * @return *this
			 */
/*
			Iterator &operator++ (int) {
				return (*this) ++;
			}
*/

			/**
			 * @brief suffix decrement
			 * @return *this
			 */
			Iterator &operator--() {
				current = current->prev;
				return *this;
			}

			/**
			 * @brief prefix decrement
			 * @return *this
			 */
			Iterator &operator-- (int) {
				return (*this) ++;
			}

			/**
			 * @brief compares two iterators
			 * @param other iterator to compare with
			 * @return true if iterators point at the same element
			 */
			bool operator== (const Iterator &other) const {
				return this->current == other.current;
			}

			/**
			 * @brief compares two iterators
			 * @param other iterator to compare with
			 * @return false if iterators point at the same element
			 */
			bool operator!= (const Iterator &other) const {
				return ! (*this == other);
			}

		
			/**
			 * @brief adds offset to the iterator
			 * @param offset
			 * @return *this
			 */
			
/*
			Iterator &operator+= (int offset) {
				bool add = (offset >= 0);
				offset = abs (offset);
				while (offset > 0) {
					current = add ? (current->next) : (current->prev);
					offset--;
				}
				return *this;
			}
*/

			/**
			 * @brief substracts offset from the iterator
			 * @param offset
			 * @return *this
			 */
			
/*
			Iterator &operator-= (const int offset) {
				*this += (-offset);
				return *this;
			}
*/

			/**
			 * @brief adds offset to an iterator
			 * @param offset
			 * @return the new iterator
			 */
/*
			Iterator operator+ (const int offset) const {
				Iterator ret = *this;
				ret += offset;
				return ret;
			}
*/

			/**
			 * @brief substracts offset from an iterator
			 * @param offset
			 * @return the new iterator
			 */
/*
			Iterator operator- (const int offset) const {
				return *this + (-offset);
			}
*/

			friend class Stack;
		};
	private:
		Node *head;

		/**
		 * @brief appends the given linked chain to the list
		 * @param src the head of the list
		 * @param hasDummy omits the last item of the list if true (treated as a dummy last element)
		 * @return *this
		 */
		
/*
		Stack &append (Node *src, bool hasDummy = true) {
			Iterator addPos = end();
			while ( (src != nullptr) && (!hasDummy || (src->next != nullptr))) {
				insert (addPos, src->value);
				src = src->next;
			}
			return *this;
		}
		
*/

		/**
		 * @brief deletes the Stack content
		 */
		void deallocate() {
			while ( (head != nullptr)) {
				Node *tmp = head;
				head = head->prev;
				delete tmp;
				tmp = nullptr;
			}
		}
	public:
		/**
		 * @brief creates an empty Stack
		 */
		Stack() : head (nodeCreate()) {
			static_assert (std::is_copy_assignable<T>::value, "T must be copy-assignable (i.e T a = b)");
			static_assert (std::is_default_constructible<T>::value, "T must have an accessible default constructor");
		}

		/**
		 * @brief creates a new Stack with a single element
		 * @param data the element to create the Stack with
		 */
		Stack (const T &data) : Stack() {
			insert (begin(), data);
		}

		/**
		 * @brief copy c-tor
		 * @param src the original Stack
		 */
		Stack (const Stack &src) : Stack() {
			append (src.head);
		}

		/**
		 * @brief d-tor
		 */
		virtual ~Stack() {
			deallocate();
			nodeDestroy (head);
		}

		/**
		 * @brief returns an iterator to the beginning of the Stack
		 * @return an iterator to the beginning of the Stack
		 */
		Iterator begin() const {
			return Iterator (head);
		}

		/**
		 * @brief returns an iterator to after the last element
		 * @return an iterator to after the last element
		 */
/*
 * 
		Iterator end() const {
			return Iterator (tail);
		}
*/

		/**
		 * @brief inserts a new item before the given iterator
		 * @param before an iterator before which the item will be inserted
		 * @param data the data that shall be added
		 * @return *this
		 */
		
/*
		List &insert (const Iterator &before, const T &value) {
			Node *newNode = nodeCreate (value);
			Node *newPrev = before.current->prev;
			Node *newNext = before.current;
			newNode->next = newNext;
			newNode->prev = newPrev;
			newNext->prev = newNode;
			if (newPrev == nullptr) {
				head = newNode;
			} else {
				newPrev->next = newNode;
			}

			return *this;
		}
*/

		/**
		 * @brief appends a new item to the end of the list
		 * @param data the data that shall be appended
		 * @return *this
		 */
		List &append (const T &data) {
			return insert (end(), data);
		}

		/**
		 * @brief removes the element at the iterator's position
		 * removing invalidates the given iterator and every iterator that points to the same location
		 * an invalid iterator (e.g out of range) will cause an undefined behavior
		 * @param position the element that will be removed
		 * @return *this
		 */
		
/*
		List &erase (const Iterator &position) {
			Node *next = position.current->next;
			Node *prev = position.current->prev;
			Node *erased = position.current;

			if (prev != nullptr) {
				prev->next = next;
			} else {
				head = next;
			}
			next->prev = prev;
			erased->next = nullptr;
			erased->prev = nullptr;
			nodeDestroy (erased);
			return *this;
		}
*/

		/**
		 * @brief assignment operator
		 * @param other Stack to assign from
		 * @return *this
		 */

		List &operator= (const Stack &other) {
			if (this == &other) {
				return *this;
			}
			deallocate();
			this.head = (other.head);
			return *this;
		}
  };
}