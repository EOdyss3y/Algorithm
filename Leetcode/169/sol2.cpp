//Boyer–Moore投票算法, Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = -1, vote = 0;
        for (int n: nums) {
            if (major == n) vote++;
            else if (vote == 0) major = n;
            else vote--;
        }
        return major;
    }
};
