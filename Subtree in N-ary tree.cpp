class Solution {
public:
    string f(Node* root, unordered_map<string, int>& mp) {
        if (!root) return "";
        
        string curr = "#";
        curr += to_string(root->data) + "$";
        
        for (Node* child : root->children) {
            curr += f(child, mp);
        }
        
        mp[curr]++;
        return curr;
    }
    
    int duplicateSubtreeNaryTree(Node* root) {
        unordered_map<string, int> mp;
        f(root, mp);
        
        int count = 0;
        for (auto it : mp) {
            if (it.second > 1) count++;
        }
        
        return count;
    }
};
