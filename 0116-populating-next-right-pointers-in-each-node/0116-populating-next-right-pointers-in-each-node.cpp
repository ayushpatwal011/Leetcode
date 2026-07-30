class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            Node* prev = NULL;
            while (s--) {
                Node* cur = q.front();
                q.pop();
                if (prev)
                    prev->next = cur;
                prev = cur;
                if (cur->left)
                    q.push(cur->left);

                if (cur->right)
                    q.push(cur->right);
            }

            prev->next = NULL;
        }

        return root;
    }
};