#include <bits/stdc++.h>
using namespace std;
int f(int ind,vector<int>&coins,int target,vector<vector<int>>&dp)
{
 
    if(ind==0)
    {
        if(target%coins[0]==0)
        return target/coins[0];
        else return 1e9;
 
    }
    if(dp[ind][target]!=-1)
    return dp[ind][target];
    int nottake=f(ind-1,coins,target,dp);
    int take=1e9;
    if(target>=coins[ind])
    take=1+f(ind,coins,target-coins[ind],dp);
    return dp[ind][target]= min(take,nottake);
 
 
}
int findways(int n,vector<int>&coins,int k)
{
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for(int target=0;target<=k;target++)
    {
        if(target%coins[0]==0)
        dp[0][target]=target/coins[0];
        else dp[0][target]=1e9;
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int target=0;target<=k;target++)
        {
            int nottake=dp[ind-1][target];
            int take=1e9;
            if(target>=coins[ind])
            take=1+dp[ind][target-coins[ind]];
             dp[ind][target]= min(take,nottake);
        }
    }
    
 
    return dp[n-1][k];
}
 
int main(){
 
  int n,k;
  cin>>n>>k;
  vector<int>coins(n);
  for(int i=0;i<n;i++)
  {
    cin>>coins[i];
 
  }
 
   int ans=findways(n,coins,k);
  if(ans==1e9)
  cout<<-1<<endl;
  else
  cout<<ans<<endl;
}