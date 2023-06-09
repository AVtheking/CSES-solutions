    #include <bits/stdc++.h>
    #include<cmath>
    using namespace std;
    // typedef pair<int, int> pii;
    // typedef pair<long long, long long> pll;
    // typedef vector<pair<long long, long long>> vpll;


    #define range(i,n) for(int i= 0; i < (n); i++) 
    #define rep(a,n)  for(int i=0;i<(n);i++) cin>>a[i];
    #define pb push_back
    #define mp make_pair
    #define F first
    #define S second
    #define all(x)  x.begin(), x.end()
    #define ll long long
    #define in insert
    #define endl '\n'
    const int mod=1e9+7;
    const int N=1e7+7;

    //Number theory functions
    int gcdExtended(int a, int b, int* x, int* y)
    {
        // Base Case
        if (a == 0) {
            *x = 0, *y = 1;
            return b;
        }
     
        int x1, y1; // To store results of recursive call
        int gcd = gcdExtended(b % a, a, &x1, &y1);
     
        // Update x and y using results of recursive call
        *x = y1 - (b / a) * x1;
        *y = x1;
     
        return gcd;
    }
     
    ll modInverse(ll a, ll m)
    {
        int x, y;
        int g = gcdExtended(a, m, &x, &y);
        if (g != 1)
            return 0;
        else {
            // m is added to handle negative x
            ll res = (x % m + m) % m;
            return res;
        }
    }
     
    ll nCr(int n, int r){
        if(r>n)
            return 0;
        
        if(r>n-r)
            r = n-r;
        
        ll ans = 1;
        for(int i = 1; i<=r ; i++){
            ans *= (n-i+1);
            ans%= mod;
            ans *= modInverse(i, mod);
            ans %= mod;    
        }
        return ans;
    }
    ll binpow(ll a, ll b) {
        if (b == 0)
            return 1;
        long long res = binpow(a, b / 2);
        if (b % 2)
            return (res * res)%mod * a % mod;
        else
            return (res * res) %mod;
    } 
    ll sqroot(ll n)
    {
           ll left = 0,right = 2000000123;
     
        while(left < right){
            ll mid = (left + right)>>1;
            if(mid*mid > n){
                right = mid;
            }else{
                left = mid+1;
            }
        }
     
        return left-1;
     
    }


   

int main() {
      int n;
      cin>>n;
      vector<int>arr(n);
      ll sum=0;
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
        sum+=arr[i];
      }
      vector<int>possiblesums(sum+1,0);
      possiblesums[0]=1;
      for(int i=0;i<n;i++)
      {
        for(int values=sum;values>=arr[i];values--)
        {
            if(possiblesums[values-arr[i]])
                possiblesums[values]=1;
        }
      }
      int cnt=0;
      for(int i=1;i<=sum;i++)
      {
        if(possiblesums[i])
          cnt++;
      }
      cout<<cnt<<endl;
      for(int i=1;i<=sum;i++)
      {
        if(possiblesums[i])
            cout<<i<<" ";
      }
      
        
}








  






