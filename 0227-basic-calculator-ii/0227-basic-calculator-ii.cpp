class Solution {
    int calc(int num1, int num2, char op) {
        if (op == '+') return num1 + num2;
        if (op == '-') return num1 - num2;
        if (op == '*') return num1 * num2;
        if (op == '/') return num1 / num2;
        return 0;
    }

public:
    int calculate(string s) {
        stack<int> nums;    
        stack<char> ops;    
        int num = 0;
        char prevOp = '+';  

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
     
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
                if (prevOp == '+') nums.push(num);
                else if (prevOp == '-') nums.push(-num);
                else if (prevOp == '*') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * num);
                } else if (prevOp == '/') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / num);
                }
                prevOp = c;  
                num = 0;    
            }
        }

        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};
