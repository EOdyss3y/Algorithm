/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。

https://leetcode.cn/problems/single-number-iii
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_ret = 0;
        int num1 = 0, num2 = 0;
        for (int n: nums) xor_ret ^= n;  //ret => a ^ b;
        //要找的两个元素在这个最低有效位上的值一个是1一个是0.
        //INT_MIN的二进制表示就是符号位是1，其余都为0，所以其最低位1代表的整数就是它自己。
        int lsb_mask = (xor_ret == INT_MIN) ? xor_ret : xor_ret & (~xor_ret + 1);
        //xor_ret & (~xor_ret + 1) 和 xor_ret & (-xor_ret) 是一样的效果。
        //用最低有效位mask将数组划分成两个子数组，要求的两个数分别在两个子数组中。
        for (int n: nums) {
            if (n & lsb_mask) { //最低有效位上的值为1
                num1 ^= n;
            } else { //最低有效位上的值为0
                num2 ^= n;
            }
        }
        return {num1, num2};
    }
};
