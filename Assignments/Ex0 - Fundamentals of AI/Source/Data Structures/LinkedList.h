

// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
	template <typename T>

	class Node {
	public:
		Node(data) {
			this->data = data;
			prev = nullptr;
			next = nullptr;
		}

		setPrev(Node* prev) {
			this->prev = prev
		}

		setNext(Node* next) {
			this->next = next
		}
	private:
		T data;
		Node* prev;
		Node* next;

		friend class LinkedList<T>;
	};


	template <typename T>
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
					front.prev = nullptr;
			}
		}
		void pop() {
			if (back) {
				newBack = back.prev;
				deleteBac
			}
		}
		void clear();
		bool contains(T element) const;
		void remove(T element);

	private:
		Node<T>* front;
		Node<T>* back;
	};
} }  // namespace ufl_cap4053::fundamentals
