class Solution {
public:
    vector<string> str;
    
    void height(TreeNode* root, string& s) {
        if (root == NULL) return;
        
        int originalLen = s.size();  
        
        if (s != "") {
            s += "->";
        }
        s += to_string(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            str.push_back(s);
        } else {
            height(root->left, s);
            height(root->right, s);
        }
        
        s.resize(originalLen);     
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        height(root, s);
        return str;
    }
};