class Solution {
public:
    int helper(TreeNode* root, long targetSum) {
        if (root == NULL) return 0;
        int count = 0;
        long rem = targetSum - root->val;
        if (rem == 0) count = 1;

        count += helper(root->left, rem);
        count += helper(root->right, rem);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;  

        int ans = 0;
        ans += helper(root, targetSum);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
    }
};