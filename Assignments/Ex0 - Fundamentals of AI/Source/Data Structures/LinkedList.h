

// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
	template <class T>
	class Node {
	private:
		T data;
		Node<T>* prev;
		Node<T>* next;
	public:
		Node<T>(data) {
			this->data = data;
			prev = nullptr;
			next = nullptr;
		}
		friend class LinkedList<T>;
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

		class Iterator {

		};
	};

	
}}  // namespace ufl_cap4053::fundamentals
