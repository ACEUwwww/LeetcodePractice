class maxArea {
public:
/*  Brute Force
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = 0;
        int n = height.size();
        int max = 0;
        // to find max(min(height[left], height[right]) * (left - right));
        for (int left = 0; left < n; left ++) {
            for (int right = left + 1; right < n; right ++) {
                int water = min(height[left], height[right]) * (right - left);
                if (water > max) {
                    max = water;
                }
            }
        }
        return max;
    }
*/

    int maxArea(vector<int>& height) {
        int n = height.size();
        int max = 0;
        int left = 0, right = n - 1;
        int water;
        while (left < right) {
            water = min(height[left], height[right]) * (right - left);
            max = water > max ? water : max;
            if (height[left] < height[right]) 
                left ++;
            else 
                right --;
        }
        return max;
    }
};