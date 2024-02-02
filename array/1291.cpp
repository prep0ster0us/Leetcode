/********************************************************
// 1291. Sequential Digits

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

TAG: Enumeration
*********************************************************/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string mp = "123456789";
        vector<int> nums, ans;
        for (int i=0; i<9; i++) {
            string temp = "";
            for (int j=i; j<9; j++) {
                temp += mp[j];
                int num = stoi(temp);
                if (low <= num && num <= high) ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};