#include <bits/stdc++.h>
#define range(i,n) for(int i= 0; i < (n); i++) 
#define arr(a,n)  for(int i=0;i<(n);i++) cin>>a[i];
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x)  x.begin(), x.end()
#define ll long long
#define in insert
#define endl '\n'
using namespace std;
ll int f(ll int i,ll int j,string &s,string &t,vector<vector<ll int>>&dp)
{
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i-1]==t[j-1])
        return 0+f(i-1,j-1,s,t,dp);
    ll int ins=1+f(i,j-1,s,t,dp);
    ll int del=1+f(i-1,j,s,t,dp);
    ll int rep=1+f(i-1,j-1,s,t,dp);
    return dp[i][j]= min(min(ins,del),rep);
}
 int EditDistance(string &s,string &t)
 {
    ll int n=s.size();
    ll int m=t.size();
    vector<vector<ll int>>dp(n+1,vector<ll int>(m+1,-1));
    return f(n,m,s,t,dp);
 }
int main() 
{
    string s,t;
    cin>>s>>t;
    ll int ans=EditDistance(s,t);
    cout<<ans<<endl;
}