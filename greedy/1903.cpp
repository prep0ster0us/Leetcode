/********************************************************
// 1903. Largest Odd Number in String

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

*********************************************************/

class Solution {
public:
    string largestOddNumber(string num) {
        char lastDigit;
        do {
            // check from back of string
            // the first odd digit encountered would result in the longest (hence the largest) number
            lastDigit = num.back()-'0';
            if(lastDigit%2!=0) {
                return num;
            }
            // if not, pop out the last digit
            num.pop_back();
        } while(num.length()>0);
        return "";
    }
};