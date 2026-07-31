class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void df(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(path);
            return;
        }

        // push
        path.push_back(nums[index]);
        df(nums, index + 1);
        path.pop_back();

        // Skip  — skip ALL duplicates
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[index])
            next++;
        df(nums, next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        df(nums, 0);
        return ans;
    }
};