#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
int f(int ind,int target,vector<int>&coin,vector<vector<int>>&dp)
{
    if(target==0)
        return 1;
    if(ind==0)
    {
        if(target%coin[0]==0)
            return 1;
        else return 0;
    }
    // int n=coin.size();
    // long long int sum=0;
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    int nottake=f(ind-1,target,coin,dp);
    int take=0;
    if(target>=coin[ind])
        take=f(ind,target-coin[ind],coin,dp);
    return dp[ind][target]= (take+nottake)%N;
    
}
int totalways(int n,int k,vector<int>&coin)
{
    // long long int sum=0;
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    // return f(n-1,k,coin,dp);
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    
    for(int target=0;target<=k;target++)
    {
        if(target%coin[0]==0)
            dp[0][target]=1;
 
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
            int nottake=dp[ind-1][target];
            int take=0;
            if(target>=coin[ind])
                take=dp[ind][target-coin[ind]];
             dp[ind][target]= (take+nottake)%N;
 
        }
    }
 
 
 
    return dp[n-1][k];
}
int main() {
    int n,k;
    cin >> n>>k;
    vector<int>coin(n);
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
     int ans=0;
     ans=totalways(n,k,coin);
    cout<<ans<<endl;
   }