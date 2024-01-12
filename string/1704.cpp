/********************************************************
// 1704. Determine if String Halves Are Alike

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

TAG: String, Counting
*********************************************************/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        unordered_set<int> hash{97, 101, 105, 111, 117, 65, 69, 73, 79, 85};

        int count=0;
        for(int i=0; i<n; i++) {
            if(hash.find(int(s[i])) != hash.end()) {
                if(i < n/2) count++;
                else count--;
            }
        }
        return count==0;
    }
};