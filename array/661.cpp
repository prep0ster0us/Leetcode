/********************************************************
// 2353. Image Smoother

An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image 
by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). 
If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).

Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

*********************************************************/

class Solution {
private:
    int m;
    int n;
public:
    int calcAvg(vector<vector<int>>& img, int row, int col) {
        int sum=0;
        int count=0;
        for(int i= row-1; i <= row+1; i++) {
            for(int j= col-1; j <= col+1; j++) {
                if(0 <= i && i < m && 0 <= j && j < n) {
                    sum += img[i][j];
                    count++;
                }
            }
        }
        return sum/count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        m = img.size();
        n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans[i][j]=calcAvg(img, i, j);
            }
        }
        return ans;
    }
};