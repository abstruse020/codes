#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,k;
        cin>>n>>k;
        vector<long long> mount(n);
        for (int i = 0; i < n; i++)
            cin>>mount[i];
        vector<long long> peeks(n,0);
        for(int i=1; i<n-1; i++)
        {
            if(mount[i-1]<mount[i] && mount[i]>mount[i+1])
                peeks[i] = peeks[i-1]+1;
            else
            {
                peeks[i] = peeks[i-1];
            }
            
        }
        peeks[n-1] = peeks[n-2];
        // for(int i=0; i<n; i++)cout<<peeks[i]<<" ";
        // cout<<"\n";
        long long max_peek=0,peek_index=0;
        for(int i=n-1; i-k+1 >= 0; i--)
        {
            if(max_peek<=peeks[i-1]-peeks[i-k+1])
            {
                max_peek = peeks[i-1] - peeks[i-k+1];
                peek_index= i-k+1;
            }
        }
        cout<<max_peek+1<<" "<<peek_index+1<<endl;
        
    }
    return 0;
}