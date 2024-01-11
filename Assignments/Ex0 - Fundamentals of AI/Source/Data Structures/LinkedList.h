

// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
	template <class T>
	class Node {
	public:
		Node<T>(d) {
			data = d;
			prev = nullptr;
			next = nullptr;
		};
	private:
		T data;
		Node* prev;
		Node* next;

		friend class LinkedList;
	};


	template <class T>
	class LinkedList {
	public:
		class Iterator {
		public:
			T operator*() const {
				return curr->data
			}
			Iterator& operator++() {
				if (curr != end()) {
					curr = curr->next;
				}
				return curr;
			}
			bool operator==(Iterator const& rhs) {
				return rhs == curr
			}
			bool operator!=(Iterator const& rhs) {
				return rhs != curr
			}

		private:
			Node<T>* curr;

			friend class LinkedList<T>;
		};

		LinkedList{
			front = nullptr
			back = nullptr
		}
		Iterator begin() const {
			return front;
		}
		Iterator end() const {
			return iterator(nullptr);
		}
		bool isEmpty() const {
			return front != nullptr;
		}
		T getFront() const {
			return front;
		}
		T getBack() const {
			return back;
		}
		void enqueue(T element) {
			queuedNode = new Node<T>(element);
			if (back) {
				oldBack = back;
				back->next = queuedNode;
				queuedNode->prev = back;
				back = queuedNode;
			}
			else {
				front = queuedNode;
				back = queuedNode;
			}
		}
		void dequeue() {
			if (front) {
				newFront = front.next;
				delete front;
				front = newFront;
				if (front)
					front->prev = nullptr;
			}
		}
		void pop() {
			if (back) {
				newBack = back.prev;
				delete back;
				back = newBack;
				if (back)
					back->next = nullptr;
			}
		}
		void clear() {
			Node* curr = front;
			while (curr != nullptr) {
				Node* temp = curr->next;
				delete curr;
				curr = temp;
			}
			front = nullptr;
			back = nullptr;
		}
		bool contains(T element) const {
			Node* curr = front;
			while (curr != nullptr) {
				if (curr->data == element) {
					return true;
				}
			}
			return false;
		}
		void remove(T element) {
			Node* curr = front;
			while (curr != nullptr) {
				if (curr->data == element) {
					deletedPrev = curr->prev;
					deletedNext = curr->next;
					delete curr

					if (deletedPrev) {
						deletedPrev->next = deletedNext;
					}
					if (deletedNext) {
						deletedNext->prev = deletedPrev;
					}
					return
				}
			}
			return
		}

	private:
		Node<T>* front;
		Node<T>* back;
	};
} };  // namespace ufl_cap4053::fundamentals
