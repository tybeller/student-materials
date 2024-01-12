#include <vector>

// TreeNode class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
	
	
	template <typename T>
	class TreeNode {
	private:
		T data;
		std::vector<TreeNode<T>*> children;

	public:
		TreeNode<T>() {
			data = NULL;
		}
		TreeNode<T>(T data) {
			this->data = data;
		}
		const T& getData() const {
			return data;
		}
		size_t getChildCount() const {
			return children.size();
		}
		TreeNode<T>* getChild(size_t index) const {
			return children[index];
		}
		void addChild(TreeNode<T>* child) {
			children.push_back(child);
		}
		TreeNode<T>* removeChild(size_t index) {
			TreeNode<T>* child = children[index];
			children.erase(children.begin() + index);
			return child;
		}
		void breadthFirstTraverse(void (*dataFunction)(const T)) const {
			std::vector<TreeNode<T>*> queue;
			queue.push_back(const_cast<TreeNode<T>*>(this));
			while (!queue.empty()) {
				TreeNode<T>* node = queue[0];
				queue.erase(queue.begin());
				dataFunction(node->getData());
				for (size_t i = 0; i < node->getChildCount(); i++) {
					queue.push_back(node->getChild(i));
				}
			}
			return;
		}
		void preOrderTraverse(void (*dataFunction)(const T)) const {
			dataFunction(this->getData());
			for (size_t i = 0; i < this->getChildCount(); i++) {
				this->getChild(i)->preOrderTraverse(dataFunction);
			}
			return;
		}
		void postOrderTraverse(void (*dataFunction)(const T)) const {
			for (size_t i = 0; i < this->getChildCount(); i++) {
				this->getChild(i)->postOrderTraverse(dataFunction);
			}
			dataFunction(this->getData());
			return;
		}
	};

}}  // namespace ufl_cap4053::fundamentals
