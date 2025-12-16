class subarraySum {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum;
        int count = 0;
        vector<int> pre(n);
        unordered_map<int, int> hmp;
        hmp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) 
                pre[i] = nums[i];
            else
                pre[i] = pre[i-1] + nums[i];
            count += hmp[pre[i] - k];
            hmp[pre[i]] += 1; 

        }
        return count;
    }
};