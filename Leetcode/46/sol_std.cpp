class Solution {
public:
    vector<vector<int>> res;
    int len;

    void backtrack(vector<int>& nums, int cur) {
        if (cur == len) {
            res.push_back(nums);
            return;
        }

        for (int i = cur; i < len; i++) {
            swap(nums[i], nums[cur]);
            backtrack(nums, cur+1);
            swap(nums[i], nums[cur]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        backtrack(nums, 0);
        return res;
    }
};
