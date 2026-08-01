class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtracking(vector<int>& candidates, int target, int sum,int start){
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(sum > target) return;

        for(int i=start; i<candidates.size(); i++){
            // use same
            curr.push_back(candidates[i]);
            backtracking(candidates, target, sum + candidates[i], i);
            curr.pop_back();
        }


     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};