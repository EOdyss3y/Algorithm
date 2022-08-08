/*
46.全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp_res;
        recursion(nums, temp_res);
        return res;
    }

    void recursion(vector<int>& nums, vector<int>& temp_res) {
        if (nums.empty()) {
            res.push_back(temp_res);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto new_res = temp_res;
            new_res.push_back(nums[i]);
            vector<int> new_nums = nums;
            new_nums.erase(new_nums.begin() + i); //已处理过的元素从当前待处理数组中删除
            recursion(new_nums, new_res);
        }
    }
};
