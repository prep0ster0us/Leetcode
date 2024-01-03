/********************************************************
// 2125.  Number of Laser Beams in a Bank

Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:
    The two devices are located on two different rows: r1 and r2, where r1 < r2.
    For each row i where r1 < i < r2, there are no security devices in the ith row.

Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.

*********************************************************/

// OPTIMIZED
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int curr=0, prev=0, ans=0;
        int n=(int)bank.size();

        // prev keeps track of last row with non-zero security device
        // with curr, we check count of security device and save lasers with 'prev' rows
        for(int i=0; i<n; i++) {
            int curr = getCount(bank[i]);
            if(curr != 0) {
                ans += (prev * curr);
                prev = curr;
            }
        }
        return ans;
    }
    int getCount(string s) {
        int count=0;
        for(char ch: s) {
            if(ch=='1') count++;
        }
        return count;
    }
};

// INITIAL CODE (with hash table)
/*
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        map<int, int> hash;
        int row=0, ans=0;
        for(string line : bank) {
            for(char ch: line) {
                if(ch == '1') hash[row]++;
            }
            row++;
        }
        map<int, int>::iterator i,j;
        for(i=hash.begin(); i!=hash.end(); i++) {
            if(i->second!=0) {
                for(j=next(i); j!=hash.end(); j++) {
                    if(j->second != 0) break;
                }
                ans += i->second*j->second;
            }
        }
        return ans;
    }
};
*/