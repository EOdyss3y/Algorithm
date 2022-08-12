/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        TreeNode* prev = nullptr;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root); //入栈
                root = root->left;
            }
            root = s.top();//待判断的元素
            if (root->right == nullptr || root->right == prev) {//右侧子节点要么为空，要么已经处理完毕。
                ret.push_back(root->val);
                prev = root;
                root = nullptr; //置为空，防止后面继续入栈。
                s.pop(); //处理完元素，出栈
            } else {
                root = root->right; //换方向准备继续入栈
            }
        }
        return ret;
    }
};
