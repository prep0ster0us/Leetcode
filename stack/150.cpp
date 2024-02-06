/********************************************************
// 150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation (http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

TAG: Array, Math, Stack
*********************************************************/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        unordered_set<string> op({"+", "-", "/", "*"});
        int ans=0;
        for(string token: tokens) {
            if(op.find(token) != op.end()){
                int n2 = stack.back();
                stack.pop_back();
                int n1 = stack.back();
                stack.pop_back();
                if(token == "+") ans = n1 + n2;
                else if(token == "-") ans = n1-n2;
                else if(token == "*") ans = n1*n2;
                else ans = n1/n2;
                stack.push_back(ans);
            } else {
                stack.push_back(stoi(token));
            }
        }
        return stack.back();
    }
};