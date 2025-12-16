class groupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int strs_size = strs.size();
        vector<unordered_map<char,int>> hashmap_set(strs_size);
        for (int i = 0; i < strs_size; i++) {
            for (int j = 0; j < strs[i].length(); j++) {
                hashmap_set[i][strs[i][j]] += 1;
            }
        }
        vector<vector<string>> res;
        int res_ptr = 0;
        vector<bool> visited(strs_size, false);
        for (int i = 0; i < strs_size; i++) {
            if (visited[i]) continue;
            res.push_back({});
            res[res_ptr].push_back(strs[i]);
            for (int j = i + 1; j < strs_size; j++) {
                if (visited[j]) continue;
                if (hashmap_set[i] == hashmap_set[j]) {
                   res[res_ptr].push_back(strs[j]);
                   visited[j] = true;
                }
            }
            res_ptr++;
        }
        return res;
    }
};