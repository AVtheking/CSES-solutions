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
const int mod=1e9+7;
using namespace std;
 
int solve(int A,int B)
{
    vector<vector<int>>dp(A+1,vector<int>(B+1,0));
    for(int a=1;a<=A;a++)
    {
        for(int b=1;b<=B;b++)
        {
            if(a==b)
                dp[a][b]=0;
            else
            {
                int mini=INT_MAX;
                int ver=0,hori=0;
                for(int i=1;i<b;i++)
                {
                    ver=1+dp[a][b-i]+dp[a][i];
                    mini=min(mini,ver);
                }
                for(int i=1;i<a;i++)
                {
                    hori=1+dp[a-i][b]+dp[i][b];
                    mini=min(mini,hori);
                }
                dp[a][b] = mini;
            }
        }
 
    }
        return dp[A][B];
}
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=solve(a,b);
    cout<<ans<<endl;
}