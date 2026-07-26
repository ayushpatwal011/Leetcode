class Solution {
    int diameter = 0;
    
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        diameter = max(diameter, l + r);
        
        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        height(root);
        return diameter;
    }
};