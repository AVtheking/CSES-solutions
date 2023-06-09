#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e7 + 7;
int f(int ind,int price,vector<int>&a,vector<int>&b,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(price>=a[0])
            return b[0];
        else return 0;
    }
    if(dp[ind][price]!=-1)
        return dp[ind][price];
    int nottake=f(ind-1,price,a,b,dp);
    int take=INT_MIN;
    if(price>=a[ind])
        take=b[ind]+f(ind-1,price-a[ind],a,b,dp);
    return dp[ind][price] = max(take,nottake);
}
int maxpages(int n,int x,vector<int>&a,vector<int>&b){
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int price=0;price<=x;price++)
    {
          if(price>=a[0])
            dp[0][price]=b[0];
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int price=0;price<=x;price++)
        {
            int nottake=dp[ind-1][price];
            int take=0;
            if(price>=a[ind])
                take=b[ind]+dp[ind-1][price-a[ind]];
            dp[ind][price] = max(take,nottake);
        }
    }
 
  return dp[n-1][x];
}
int main()
{ 
   int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
     for(int i=0;i<n;i++)
        cin>>b[i];
    int ans=maxpages(n,x,a,b);
    cout<<ans<<end
}