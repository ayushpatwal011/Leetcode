class Solution {
public:
    vector<vector<int>> ans;
    void path(TreeNode* root, int targetSum, vector<int> arr) {
        if (root == NULL)
            return;
        arr.push_back(root->val);
        if (root->left == NULL && root->right == NULL && targetSum == root->val) {
            ans.push_back(arr);
            return;
        }
        int rem = targetSum - root->val;
        path(root->left, rem, arr);
        path(root->right, rem, arr);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> arr;
        path(root, targetSum, arr);
        return ans;
    }
};