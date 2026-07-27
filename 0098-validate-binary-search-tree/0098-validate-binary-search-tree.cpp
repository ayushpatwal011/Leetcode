class Solution {
public:
    bool Rec(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;

        bool left = Rec(root->left , minVal, root->val);
        bool right = Rec(root->right, root->val, maxVal);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return Rec(root, LONG_MIN, LONG_MAX);
    }
};
