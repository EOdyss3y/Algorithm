//use a dynamic array to temporarily store a single result.

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> t;              //dynamic array
    vector<bool> used;          //indicate which elements have been used.
    void dfs(vector<int>& nums) {           //current depth is not needed in args.
        if (t.size() == nums.size()) {
            ret.push_back(t);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                //trackdown
                t.push_back(nums[i]);
                used[i] = true;
                dfs(nums);
                //backtrack
                t.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        dfs(nums);
        return ret;
    }
};
