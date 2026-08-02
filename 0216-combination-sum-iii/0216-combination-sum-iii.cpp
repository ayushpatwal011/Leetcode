class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    int limit = 9;

    void backtrack(int k ,int n ,int sum, int start){
        if(curr.size() == k && sum == n){
            ans.push_back(curr);
            return ;
        }
        if(curr.size() == k || sum > n ){ return ;}

        for(int i = start; i<=limit; i++){
            curr.push_back(i);
            backtrack( k, n , sum+i, i+1 );
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack( k ,n , 0, 1);
        return ans;
    }
};