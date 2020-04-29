#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int t=0; t<test; t++)
    {
        long long x,y;
        cin>>x>>y;
        long long check= abs(x) + abs(y);
        if(check & 1 ==0)
        {
            cout<<"Case #"<<t+1<<": IMPOSSIBLE\n";
            continue;
        }
        long long x1 = max(abs(x),abs(y));
        long long y1 = min(abs(x),abs(y));
    }
    
}