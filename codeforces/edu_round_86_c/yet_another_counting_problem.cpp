#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll gcd(ll a, ll b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin>>test;
    while(test--){
        ll a,b,q,gcd_ab=0,lcm_ab=0,ans=0,times=0,max_ab=0;
        cin>>a>>b>>q;
        gcd_ab = gcd(max(a,b),min(a,b));
        lcm_ab = a*b/gcd_ab;
        for(ll quer=0; quer<q; quer++)
        {
            ll l,r;
            cin>>l>>r;

            times = (r-l+1);
            times = times/lcm_ab;
            max_ab = max(a,b);
            ans = times* max_ab;
            ll dif=0;
            if(lcm_ab *times < (r-l+1) )
            {
                dif = (r-l+1)%lcm_ab;
                for(ll i=r; i> r-dif; i--)
                {
                    if( (i%a)%b == (i%b)%a )
                    {
                        // cout<<i<<" ";
                        ans++;
                    }    
                }
            }
            // cout<<" \n";
            ans = (r-l+1) - ans;
            cout<<ans<<" ";

        }
        cout<<"\n";

    }
    return 0;
}