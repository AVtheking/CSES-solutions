#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e9 + 7;
int f(int sum,vector<int>&dp)
{
    if(sum==0)
        return 1;
    long long int take=0;
    if(dp[sum]!=-1)
        return dp[sum];
    for(int i=1;i<=6;i++)
    {
        
        
        if(sum>=i)
        {
            take+=f(sum-i,dp)%N;
        }
    }
    return dp[sum]= take%N;
}
int findways(int n)
{
    vector<int>dp(n+1,-1);
    return f(n,dp);
}
int main()
{
    int n;
    cin>>n;
    int ans=findways(n);
    cout<<ans;
 
 
}
 