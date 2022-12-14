/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

class Solution {
public:
    vector<vector<int>> ret;        //store results
    vector<int> t;                  //dynamic array
    void dfs(vector<int>& nums, int cur) {
        if (cur == nums.size()) {
            ret.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(nums, cur+1);
        t.pop_back();
        dfs(nums, cur+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
};
