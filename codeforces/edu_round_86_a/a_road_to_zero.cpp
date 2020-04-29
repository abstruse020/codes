#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long test;
    cin>>test;
    while (test--)
    {
        /* code */
        long long x,y,a,b,tem,ans=0;
        cin>>x>>y>>a>>b;
        tem = max(x,y);
        y = min(x,y);
        x = tem;
    
        if(b>2*a)
        {
            ans = (x+y)*a;
        }
        else
        {
            ans = (x-y)*a;
            ans = ans + y*b;
        }
        cout<<ans<<endl;
        
    }
    return 0;
    
}