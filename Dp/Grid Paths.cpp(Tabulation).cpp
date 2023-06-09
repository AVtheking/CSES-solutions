#include<bits/stdc++.h>
using namespace std;
 
const int N=1e9+7;
 
// long long int f(int i, int j, vector<vector<char>>& grid, vector<vector<long long int>>& dp) {
//     if (i>=0 && j>=0 && grid[i][j]=='*') {
//         return 0;
//     }
//     if (i==0 && j==0) {
//         return 1;
//     }
//     if (i<0 || j<0) {
//         return 0;
//     }
//     if (dp[i][j] != -1) {
//         return dp[i][j];
//     }
//     long long int up = f(i-1, j, grid, dp);
//     long long int left = f(i, j-1, grid, dp);
//     return dp[i][j] = (up + left)%N;
// }
 
long long int TotalPaths(int n, vector<vector<char>>& grid) {
    vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]=='*')
                dp[i][j]=0;
            else if(i==0&&j==0)
            {
                dp[i][j]=1;
            }
            else
            {
                long long int up=0,left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0)  left = dp[i][j-1];
                dp[i][j] = (up + left)%N;
            }
        }
    }
 
    return dp[n-1][n-1];
}
 
 
int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    long long int ans = TotalPaths(n, grid);
    cout << ans << endl;
    return 0;
}