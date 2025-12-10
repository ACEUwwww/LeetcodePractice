class dailyTemperatures {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int length = temperatures.size();
        vector<int> answer(temperatures.size(), 0);
        stack<int> a_stack;
        int record = 0;
        for (int i = 0; i < length; i++) {
            while (!a_stack.empty() && temperatures[i] > temperatures[a_stack.top()]) {
                answer[a_stack.top()] = i - a_stack.top();
                a_stack.pop();
            }
            a_stack.push(i);
        }
        return answer;
    }
};