class Solution {
public:
    int maxSum = INT_MIN;
    int  solve(TreeNode* root){
        if(root==NULL) return 0;
        int leftSum = max(0, solve(root->left));
        int rightSum = max(0, solve(root->right));
        
        int currSum = root->val + leftSum + rightSum;
        maxSum = max(currSum, maxSum);

        return root->val + max(leftSum, rightSum);      

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};