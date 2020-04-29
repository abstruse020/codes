#include<bits/stdc++.h>
#define ll long long
#define PRIME 1000000007
using namespace std;

long long dp[52][1002];
vector<pair<ll,ll>> lim;
ll mod_exp(ll x,ll y)
{
    ll result=1;
    x= x%PRIME;
    if(x==0) return 0;
    while (y>0)
    {
        if(y & 1)
            result = (result*x)%PRIME;
        y = y>>1;
        x = (x*x)%PRIME;
    }
    return result;
}

ll modinv_fermats(ll a, ll m=PRIME)
{
    ll tem;
    tem = mod_exp(a,m-2);
    return tem;
}

ll fact(ll a)
{
    ll fact_a=1;
    for(int i=2; i<=a; i++)
        fact_a = (fact_a*i)%PRIME;
    return fact_a;
}

ll compute_ncr(ll n, ll r)
{
    ll result=1;
    result = fact(n);
    result = (result*modinv_fermats( fact(r) ))%PRIME;
    result = (result*modinv_fermats( fact(n-r) ))%PRIME;
    return result;
}
long long rec(int n,int k)
{
    long long sum=0;
    // cout<<"n = "<<n<<" k = "<<k<<endl;
    if(n==0 && k==0)
    {
        sum =1;
    }
    else if(n<0 || k<0)
    {
        return 0;
    }
    else if(n>0 && k>0)
    {
        // cout<<"in else if\n";
        if( dp[k][n] != -1)
            sum = dp[k][n];
        else{
            // cout<<"in else\n";
            for(int i=lim[k-1].first; i<=lim[k-1].second; i++)
            {
                // cout<<"entered for\n";
                sum = (sum + rec(n-i, k-1))%PRIME;
            }
        }
    }
    // cout<<"sum = "<<sum<<endl;
    dp[k][n]=sum;
    return sum;
}
int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        ll n,k,a,b;
        lim.clear();
        cin>>k>>n;
        // vector<pair<ll,ll>> lim(k);
        for(int i=0; i<k ; i++)
        {
            cin>>a>>b;
            lim.push_back({a,b});
            // cin>>lim[i].first>>lim[i].second;
        } 
        for(int i=0; i<k+1; i++)
            for(int j=0; j<n+1; j++)
                dp[i][j]=-1;

        long long ans=rec(n,k);
        // for(int i=0; i<k; i++){
        //     for(int j=0; j<n; j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        cout<<ans<<endl;

        // for(int i=0; i<k ;i++)
        // {
        //     n = n - lim[i].first;
        // }
        // ll ans=0,r=0,sub=0;        
        // for(int i=0; i<k; i++)
        // {
        //     long long space= lim[i].second-lim[i].first;
        //     for(int j=1; j< n-space ; j++)
        //     {
        //         sub =(sub + compute_ncr(n-(space +j) +(k-2), (k-2)))%PRIME;
        //         // cout<<sub<<" ";
        //     }
        // }
        // vector<long long> extras;
        // long long add_ext=0;
        // for(int i=0; i<k ; i++)
        // {
        //     long long space=lim[i].second - lim[i].first;
        //     if( space <n)
        //         extras.push_back(n-space);
        // }
        // for(int i=0; i<extras.size(); i++)
        // {
        //     for(int j=i+1; j<extras.size(); j++)
        //     {
        //         add_ext = (add_ext+ (extras[i]*extras[j])%PRIME)%PRIME;
        //     }
        // }
        // ans = compute_ncr(n+(k-1),k-1);
        // // cout<<"(n+r-i)C(r-1) ="<<ans<<"\n and sub ="<<sub<<endl;
        // ans = (PRIME+ans - sub)%PRIME;
        // ans = (ans+add_ext)%PRIME;
        // cout<<ans<<endl;
    }
    return 0;
}