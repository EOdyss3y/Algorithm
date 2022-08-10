//time/space complexity: O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ret = 0, max = 0;
        for (int n: nums) {
            umap[n]++;
            if (umap[n] > max) {
                max = umap[n];
                ret = n;
            }
        }
        return ret;
    }
};
