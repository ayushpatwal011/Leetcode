class Solution {
public:
    int minDepth(TreeNode* root) {
        int ans = 0;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s= q.size();
            ans++;
            while(s--){
                TreeNode* x = q.front();
                if(x->left == NULL && x->right ==NULL) return ans;
                q.pop();
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
            }
        }
        return ans;

    }
};