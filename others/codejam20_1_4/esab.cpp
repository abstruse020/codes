#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int i=0; i<test; i++)
    {
        int b;
        cin>>b;
        string a="";
        char t;
        for(int j=0; j<10; j++)
        {
            cout<<j+1<<endl;
            fflush(stdout);
            cin>>t;
            a = a+t;
        }
        cout<<a<<endl;
        fflush(stdout);
        char y;
        cin>>y;
        if(y == 'Y')
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}