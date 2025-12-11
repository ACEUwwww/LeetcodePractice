class lengthOfLongestSubString {
    public:
    int lengthOfLongestSubstring(string s) {
        int left = 0; 
        int right = 0;
        int window_size = 0;
        int max_window_size = 0;
        unordered_map<char,int> hashmap;
        while (right < s.size()) {
            if (hashmap[s[right]] == 1 && right != left) {
                while (s[left] != s[right]) {
                    hashmap[s[left]] = 0;
                    left ++;
                    window_size --;
                }
                left ++;
                window_size --;
                hashmap[s[right]] = 0;
                continue;
            }
            hashmap[s[right]] = 1;
            right ++;
            window_size ++;
            max_window_size = max(window_size, max_window_size);
        }
        return max_window_size;
    }
};