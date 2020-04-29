#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,tem=0;
        cin>>n;
        string str;
        cin>>str;
        vector<int> a(n+1),b(n+1);
        a[0]=0;
        for(int i=1; i<n+1; i++)
        {
            if(str[i-1]!='A')
                tem++;
            a[i]=tem;
        }
        tem=0;
        b[n]=0;
        for(int i=n-1; i>=0; i--)
        {
            if(str[i]!='B')
                tem++;
            b[i]=tem;
        }
        for(int i=0; i<n+1; i++)
            a[i]=a[i]+b[i];

        cout<<*min_element(a.begin(),a.end())<<endl;
    }
    return 0;
}