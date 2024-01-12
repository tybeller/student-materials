

// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
	template <class T>
	class Node {
	private:
		T data;
		Node<T>* prev;
		Node<T>* next;
	public:
		Node<T>(T data) {
			this->data = data;
			prev = nullptr;
			next = nullptr;
		}
		template <class T>
		friend class LinkedList;
	};
	

	template <class T>
	class LinkedList {
	private:
		Node<T>* front;
		Node<T>* back;
	public:
		LinkedList<T>() {
			front = nullptr;
			back = nullptr;
		}
		~LinkedList<T>() {
			clear();
		}
		bool isEmpty() const {
			return front == nullptr;
		}
		T getFront() const {
			return front->data;
		}
		T getBack() const {
			return back->data;
		}
		void enqueue(T element) {
			Node<T>* newNode = new Node<T>(element);
			if (isEmpty()) {
				front = newNode;
				back = newNode;
			}
			else {
				back->next = newNode;
				newNode->prev = back;
				back = newNode;
			}
		}
		void dequeue() {
			Node <T>* newFront = front->next;
			delete front;
			if (newFront) {
				newFront->prev = nullptr;
				front = newFront;
			}
			else {
				front = nullptr;
				back = nullptr;
			}
		}
		void pop() {
			Node<T>* newBack = back->prev;
			delete back;
			if (newBack) {
				newBack->next = nullptr;
				back = newBack;
			}
			else {
				front = nullptr;
				back = nullptr;
			}
		}
		void clear() {
			Node<T>* curr = front;
			while (curr != nullptr) {
				Node<T>* temp = curr;
				curr = curr->next;
				delete temp;
			}
			front = nullptr;
			back = nullptr;
		}
		bool contains(T element) const {
			Node<T>* curr = front;
			while (curr != nullptr) {
				if (curr->data == element) {
					return true;
				}
				curr = curr->next;
			}
			return false;
		}
		void remove(T element) {
			Node<T>* curr = front;
			while (curr != nullptr) {
				if (curr->data == element) {
					if (curr == front) {
						dequeue();
					}
					else if (curr == back) {
						pop();
					}
					else {
						curr->prev->next = curr->next;
						curr->next->prev = curr->prev;
						delete curr;
					}
					return;
				}
				curr = curr->next;
			}
		}

		class Iterator {
		private:
			Node<T>* curr;

		public:
			Iterator(Node<T>* node) : curr(node) {}

			T operator*() const {
				return curr->data;
			}
			Iterator& operator++() {
				curr = curr->next;
				return *this;
			}
			bool operator==(Iterator const& rhs) {
				return curr == rhs.curr;
			}
			bool operator!=(Iterator const& rhs) {
				return !(curr == rhs.curr);
			}

			friend class LinkedList;

		};

		Iterator begin() const {
			return Iterator(front);
		}
		Iterator end() const {
			return Iterator(nullptr);
		}

		friend class Iterator;
	};

	
}}  // namespace ufl_cap4053::fundamentals
