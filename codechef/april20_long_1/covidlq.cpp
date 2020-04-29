#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int curr,val, prev=-6;
        string ans = "YES";
        for(int i=0; i<n; i++)
        {
            cin>>val;
            if(val==1)
            {
                if(i-prev <6)
                {
                    ans="NO";
                }
                prev = i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}