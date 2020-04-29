#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ans=0;
ll calculate(ll n)
{
    if(n > 0)
    {
        return max(n,calculate(n/2)+ calculate(n/3) + calculate(n/4));
    }
    else{
        return 0;
    }

}

int main()
{
    int test=10;
    ll n;
    while(cin>>n && test--)
        cout<<calculate(n)<<endl;
    return 0;
}