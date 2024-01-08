/********************************************************
// 1235. Maximum Profit in Job Scheduling

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

*********************************************************/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        // save details of each jobs collectively
        vector<pair<int, pair<int,int>>> jobs;
        for(int i=0; i<n; i++) {
            jobs.push_back({endTime[i], {startTime[i], profit[i]}});
        }
        // sort, based on end time of jobs
        // since concurrent jobs can only be performed when start time of job2 >= end time of job1
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, 0);
        dp[0] = jobs[0].second.second;

        for(int i=1; i<n; i++) {
            int curr = jobs[i].second.second;
            // previous selected job
            int prev = binarySearch(jobs, i);
            if(prev != -1) {
                curr += dp[prev];
            }
            // max profit till current job
            dp[i] = max( dp[i-1], curr);
        }
        return dp[n-1];
    }
    static int binarySearch(vector<pair<int, pair<int,int>>>& jobs, int index) {
        int left=0, right=index-1;
        while(left <= right) {
            int mid = (left+right)/2;
            if(jobs[mid].first <= jobs[index].second.first) {
                if(jobs[mid+1].first <= jobs[index].second.first) {
                    left = mid+1;
                } else {
                    return mid;
                }
            } else {
                right = mid-1;
            }
        }
        return -1;
    }
};