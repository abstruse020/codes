#include<bits/stdc++.h>
#define ll long long
#define PRIME 1000000007
using namespace std;

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
    // cout<<"Mod inv of "<<a<<" , = ";
    tem = mod_exp(a,m-2);
    // cout<<tem<<endl;
    return tem;
}
ll fact(ll a)
{
    ll fact_a=1;
    for(int i=2; i<=a; i++)
        fact_a = (fact_a*i)%PRIME;
    return fact_a;
}

int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        string s,r;
        cin>>s;
        cin>>r;
        ll n = s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i]==r[i])
                s[i]='0';
            else
                s[i]='1';
        }
        ll diff=0,might_diff=0;
        ll times_changed=0,cost=0;
        int first_1=1;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='1')
            {
                // times_changed++;
                
                might_diff++;
                times_changed++;
                // cout<<"Might Differ = "<<might_diff<<endl;
                if(first_1)
                {
                    diff++;
                    first_1=0;
                    might_diff=0;
                }
                else if( (diff+1)*(times_changed) < (times_changed-1)*(diff + might_diff) )
                {
                    diff += 1;
                    // times_changed++;

                    might_diff=0;
                }
                else
                {
                    diff = diff + might_diff;
                    might_diff=0;
                    times_changed--;
                }
                // cout<<"1 found => diff="<<diff<<" times changed = "<<times_changed<<endl;
                
            }
            if(s[i]=='0')
            {
                might_diff++;
            }
        }
        cost = diff*times_changed;
        cout<<cost<<endl;
    }
    return 0;
    
}