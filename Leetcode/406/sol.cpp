class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ret;
        sort(people.begin(), people.end(), [](vector<int>& u, vector<int>& v){
            return (u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]));
        });
        for (auto person: people) ret.insert(ret.begin() + person[1], person);
        return ret;
    }
};
