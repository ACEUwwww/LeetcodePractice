class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res = intervals;

        for (int i = 0; i < (int)res.size(); ++i) {
            for (int j = i + 1; j < (int)res.size(); ++j) {
                if (res[i][1] >= res[j][0] && res[j][1] >= res[i][0]) {
                    vector<int> merged = {
                        min(res[i][0], res[j][0]),
                        max(res[i][1], res[j][1])
                    };
                    res.erase(res.begin() + j);
                    res.erase(res.begin() + i);
                    res.push_back(merged);
                    i = -1;
                    break;
                }
            }
        }
        return res;
    }
};
