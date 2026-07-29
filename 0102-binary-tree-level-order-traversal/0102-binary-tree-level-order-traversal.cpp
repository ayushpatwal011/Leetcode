class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result; // empty tree
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s=q.size();
            vector<int> curr;
            while(s--){
                TreeNode* x = q.front();
                q.pop();
                curr.push_back(x->val);
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);

            }
            result.push_back({curr});
        }

        return result;
    }
};
