#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,n_cpy,i=0;
        cin>>n;
        n_cpy = n;
        if(n==1)
        {
            cout<<"1\n1 1\n";
            continue;
        }
        cout<<n/2<<"\n";
        if(n==2)
        {
            cout<<"2 1 2\n";
            continue;
        }
        cout<<"3 1 2 3\n";
        for(int i=4; i<n; i+=2)
        {
            cout<<"2 "<<i<<" "<<i+1<<"\n";
        }
        if(n%2 ==0)
        {
            cout<<"1 "<<n<<"\n";
        }

    }
    return 0;
}