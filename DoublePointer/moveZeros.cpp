class moveZeroes {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j]) {
                std::swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }

        return;
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};