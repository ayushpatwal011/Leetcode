class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtracking(int n, int k,  int start){
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for(int i=start; i<=n; i++){
            curr.push_back(i);
            backtracking(n,k,i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};