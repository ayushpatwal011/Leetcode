class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path ; 

    void df(vector<int>& nums,  int i){
        if(i==nums.size()){
            ans.push_back(path);
            return;
        }
        df(nums, i+1); //skip
        path.push_back(nums[i]);    // push
        df(nums, i+1);
        path.pop_back();
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        df(nums, 0);
        return ans;
    }
};