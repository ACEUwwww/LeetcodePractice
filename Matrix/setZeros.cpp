class setZeroes {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> pairs;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    pairs.push_back(make_pair(i, j));
                }
            }
        }
        for (pair<int,int> pair:pairs) {
            for (int i = 0; i < m; i++) {
                matrix[i][pair.second] = 0;
            }
            for (int i = 0; i < n; i++) {
                matrix[pair.first][i] = 0;
            }
        }
        return;
    }
};