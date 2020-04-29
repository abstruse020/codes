#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int t=0; t<test; t++)
    {
        int stk=0;
        string str,ans="";
        cin>>str;
        str = '0'+str+'0';
        int len = str.length();
        for(int i=1; i<len-1; i++)
        {
            int diff = int(str[i]) - int(str[i-1]);
            if(diff>0)
            {
                for(int d=0; d<diff; d++)
                {
                    ans+="(";
                    stk++;
                }
            }
            else if(diff<0)
            {
                for(int d=0; d<(-diff); d++)
                {
                    ans+=")";
                    stk--;
                }
            }
            ans+= str[i];
        }
        for(int i=0; i<stk; i++)
        {
            ans+=")";
        }
        cout<<"Case #"<<t+1<<": "<<ans;
        cout<<"\n";
    }

    return 0;
}