class permute {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track = {};
        int n = nums.size();
        vector<bool> used(n, false);
        backtrack_permute(res, nums, used, track, n);
        return res;
    }

    void backtrack_permute(vector<vector<int>>& res,
                                vector<int>& nums,
                                vector<bool>& used, 
                                vector<int>& track,
                                int n) {
        if (track.size() == n) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            else {
                track.push_back(nums[i]);
                used[i] = true;
                backtrack_permute(res, nums, used, track, n);
                track.pop_back();
                used[i] = false;
            }
        }
        return;
    }
};