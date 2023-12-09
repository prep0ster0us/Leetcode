/********************************************************
// 1716. Calculate Money in Leetcode Bank

Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

*********************************************************/

class Solution {
public:
    int totalMoney(int n) {
        int sum=0, temp=1;
        // i -> for Monday
        // j -> for following days of the week (increasing every week)
        // k -> for each day in the week
        for(int i=1, j=1; i <= n; i+=7, j++) {
            for(int k=j; k <= j+6; k++) {
                // keep count of total days calculated for; break when all days covered
                if(temp > n) {
                    break;
                }
                sum += k;
                temp++;
            }
        }
        return sum;
    }
};