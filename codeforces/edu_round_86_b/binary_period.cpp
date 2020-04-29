#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long test;
    cin>>test;
    while(test--)
    {
        string str;
        cin>>str;
        string ans="";
        long long n = str.size(),i=0;
        //all are same or not
        for(i=0; i<n-1; i++)
        {
            if(str[i]==str[i+1])
            {
                continue;
            }
            else
                break;
        }
        if(i==n-1)
        {
            cout<<str<<endl;
            continue;
        }
        
        for(i=0; i< n-1; i++)
        {
            ans = ans + str[i];
            if(str[i] == str[i+1])
            {
                if(str[i]=='0')
                    ans = ans + '1';
                else
                    ans = ans + '0';
            }
        }
        ans = ans + str[n-1];

        cout<<ans<<endl;
    }

    return 0;
}