/********************************************************
// 2264. Largest 3-Same-Digit Number in String

You are given a string num representing a large integer. An integer is good if it meets the following conditions:
    It is a substring of num with length 3.
    It consists of only one unique digit.

Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:
    A substring is a contiguous sequence of characters within a string.
    There may be leading zeroes in num or a good integer.

*********************************************************/

class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> temp;
        for(int i=9; i>0; i--) {
            temp.push_back(to_string(i*111));
        }
        temp.push_back("000");

        for(int i=0; i<10; i++) {
            if (num.find(temp[i]) != string::npos) {
                return temp[i];
            }
        }
        return "";
    }
};
