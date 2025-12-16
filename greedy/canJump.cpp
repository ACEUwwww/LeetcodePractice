class canJump {
public:
    bool canJump(vector<int>& nums) {
        bool flag = false;
        vector<bool> visited(nums.size(), false);
        canJumpRecursive(0, nums, flag, visited);
        return flag;
    }
    
    void canJumpRecursive(int start, vector<int>& nums, bool& flag, vector<bool>& visited) {
        if (start + nums[start] >= nums.size() - 1) {
            flag = true;
            return;
        } else if (flag) {
            return;
        } else {
            visited[start] = true;
            for (int i = 1; i <= nums[start]; i++) {
                if (!visited[start + i])
                    canJumpRecursive(start + i, nums, flag, visited);
            }
            return;
        }
    }
};