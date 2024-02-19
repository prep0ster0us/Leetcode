/********************************************************
// 231. Power of two

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

TAG: Math, Bit Manipulation, Recursion
*********************************************************/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        bitset<32> bn(n);
        return bn.count()==1;
    }
};

/*** ALTERNATE APPROACH ***/
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        return (n & (n-1)) == 0;
    }
};
*/