#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll test;
    cin>>test;
    while (test--)
    {
        ll n,x;
        int flag=0;
        cin>>n;
        cin>>x;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        sort(arr.begin(),arr.end(), greater<ll>());
        // for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        vector<ll> days(arr[0],0);
        for(int i=0; i<n; i++)
        {
            days[ arr[i] -1 ]++;
        }
        for(int i=days.size()-1; i>0; i--)
        {
            if(days[i]>x)
            {
                days[i-1] += days[i]-x;
                days[i]=x;
            }
        }
        for(int i=0; i<days.size(); i++)
        {
            // cout<<days[i]<<" ";
            if(days[i]>x)
                flag=1;
        }
        if(days[0]>0)
            flag=1;
        if(flag==1)
            cout<<"Impossible\n";
        else
            cout<<"Possible\n";
    }
    return 0;
    
}