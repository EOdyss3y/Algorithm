//backtrack

class Solution {
public:
    vector<string> ret;
    string t;
    void dfs(int n, int left, int right) {
        if (t.size() == 2*n) {
            ret.push_back(t);
            return;
        }
        if (left < n) {
            t.push_back('(');
            dfs(n, left + 1, right);
            t.pop_back();
        }
        if (right < left) {
            t.push_back(')');
            dfs(n, left, right + 1);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ret;
    }
};
