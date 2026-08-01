class Solution {
public:
    int ans = 0;

    void backtrack(vector<int>& nums, int index, int sum, int target) {

        if (index == nums.size()) {
            if (sum == target)
                ans++;
            return;
        }

        backtrack(nums, index + 1, sum + nums[index], target);

        backtrack(nums, index + 1, sum - nums[index], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, 0, 0, target);
        return ans;
    }
};