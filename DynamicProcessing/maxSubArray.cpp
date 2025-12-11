class maxSubArray {
    public:
    /*  Brute Force
        int maxSubArray(vector<int>& nums) {
            int maxsum = nums[0];
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i; j < nums.size(); j++) {
                    int cursum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
                     if (cursum > maxsum) {         
                        maxsum = cursum;
                    }
                }
            }
            return maxsum;
        }
    */
    //  Dynamic Processing
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int cur = nums[0];
            int maxsum = nums[0];
            int pre = cur;
            for (int i = 1; i < n; i++) {
                cur = max(pre + nums[i], nums[i]);
                if (maxsum < cur) {
                    maxsum = cur;
                }
                pre = cur;
            }
            return maxsum;
        }
    
    };