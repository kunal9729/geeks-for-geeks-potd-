/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
public:
    int ladoos(Node* root, int home, int k) {
        if (!root) 
            return 0;
        
        unordered_map<Node*, Node*> parent;
        Node* target_node = NULL;

        // Find target node and construct parent map
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            if (p->data == home) target_node = p;

            if (p->left) {
                parent[p->left] = p;
                q.push(p->left);
            }

            if (p->right) {
                parent[p->right] = p;
                q.push(p->right);
            }
        }
        
        // Traverse k levels and sum values
        queue<Node*> level_q;
        unordered_set<Node*> visited;
        level_q.push(target_node);
        visited.insert(target_node);
        int sum = target_node->data, curr_lvl = 0;

        while (!level_q.empty() && curr_lvl < k) {
            int n = level_q.size();
            for (int i = 0; i < n; i++) {
                auto p = level_q.front();
                level_q.pop();

                if (p->left && !visited.count(p->left)) {
                    sum += p->left->data;
                    level_q.push(p->left);
                    visited.insert(p->left);
                }

                if (p->right && !visited.count(p->right)) {
                    sum += p->right->data;
                    level_q.push(p->right);
                    visited.insert(p->right);
                }

                if (parent[p] && !visited.count(parent[p])) {
                    sum += parent[p]->data;
                    level_q.push(parent[p]);
                    visited.insert(parent[p]);
                }
            }
            curr_lvl++;
        }
        return sum;
    }   
};
