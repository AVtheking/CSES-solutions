#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e7 + 7;
int f(int n)
{
    if(n==0)
        return 0;
    
    int temp=n;
    // cout<<temp%10;
int ministeps=N;
    while(temp>0)
    {
        int digi=temp%10;
        // dig.push_back(digi);
        temp=temp/10;
        // cout<<temp;
        // cout<<digi<<endl;
        if(digi!=0)
        ministeps=min(ministeps,1+f(n-digi));
        cout<<ministeps<<endl;
        // cout<<digi<<endl;
    }
    
    
    return ministeps;
}
 
int findways(int n) {
    vector<int>dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int temp=i;
    // cout<<temp%10;
      int ministeps=N;
       while(temp>0)
    {
        int digi=temp%10;
        // dig.push_back(digi);
        temp=temp/10;
        // cout<<temp;
        // cout<<digi<<endl;
        if(digi!=0)
        ministeps=min(ministeps,1+dp[i-digi]);
        // cout<<ministeps<<endl;
        // cout<<digi<<endl;
    }
    
    
    dp[i]= ministeps;
    }
    return dp[n];
}
 
int main() {
    int n;
    cin >> n;
    int ans = findways(n);
    cout << ans << endl;
    return 0;
}