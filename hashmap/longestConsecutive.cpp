class longestConsecutive {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); i++) {
            hashset.insert(nums[i]);
        }
        int max_count = 0;
        for (int x : hashset) {
            if ((hashset.find(x - 1) != hashset.end())) {
                continue;
            }
            int y = 0;
            while(hashset.find(x + y) != hashset.end()) {
                y++;
            }
            max_count = max(max_count, y);
        }
        return max_count;
    }
};