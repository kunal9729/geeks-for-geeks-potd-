/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        pre = suc = nullptr;

        function<void(Node*)> dfs = [&](Node* current) {
            if (current == nullptr)
                return;

            if (current->key < key) {
                pre = current;
                dfs(current->right);
            } else if (current->key > key) {
                suc = current;
                dfs(current->left);
            } else {
                dfs(current->left);
                dfs(current->right);
            }
        };

        dfs(root);
    }
};
