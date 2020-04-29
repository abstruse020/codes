#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define PRIME 1000000007
using namespace std;

ull modulo_exp(ull a, ull n)
{
    ull result=1;
    while(n>0)
    {
        if(n & 1)
        {    
            result = (result*a)%PRIME;
            // cout<<"result updated = "<<result<<" ";
        }
        n=n>>1;
        a = (a*a)%PRIME;
    }
    return result;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        ull n,ans=0;
        cin>>n;
        // cout<<"Input taken\n";
        ans = modulo_exp(2,n);
        // cout<<"modulo computed = "<<ans;
        ans = (ans -1)%PRIME;
        cout<<ans<<endl;
    }
    return 0;
}