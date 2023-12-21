
/********************************************************
// 1637. Widest Vertical Area Between Two Points Containing No Points

Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.

*********************************************************/

class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(), points.end(), comp);

        for(int i=1; i<points.size(); i++) {
            ans = max(ans, points[i][0]-points[i-1][0]);
        }
        return ans;
    }
};