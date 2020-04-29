#include<bits/stdc++.h>

using namespace std;

bool orderby(int a, int b)
{
    return a>b;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,sum=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n ; i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0; i<n; i++)
        {
            if((arr[i] - i) > 0)
            {
                sum = (sum + arr[i] - i)%1000000007;
            }
            else
            {
                continue;
            }
            
        }

        cout<<sum<<"\n";
    }
    return 0;
}