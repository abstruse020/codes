#include<bits/stdc++.h>

using namespace std;

long long bstrToInt(string str)
{
    
    long long ans=0;
    for(int i=0; i<=15; i++)
    {
        ans *=2;
        ans = ans+ int(str[i])-int('0');
        // cout<<ans<<" ";
    }
    return ans;
}

int  main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int num,m;
        char c;
        cin>>num>>m>>c;
        m = m%16;
        string bi="";
        for(int i=0; i<16; i++)
            bi=bi+'0';
        int i=0;
        while(num>0)
        {
            if( num & 1)
                bi[i] = '1';
            else
                bi[i] = '0';
            i++;
            num = num>>1;
        }
        string bians="";
        if(c=='L')
        {
            int start = 15-m;
            for(int i=start; i>=0; i--)
                bians += bi[i];
            for(int i=15; i > start ; i--)
                bians += bi[i];
        }
        else
        {
            int start = m-1;
            for(int i=start; i>=0; i--)
                bians+=bi[i];
            for(int i=15; i>start; i--)
                bians+=bi[i];
        }
        // cout<<bians<<endl;
        long long ans = bstrToInt(bians);
        cout<<ans<<endl;
    }
    return 0;
}