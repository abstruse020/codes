#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,tem=0,query=0,ans=0,left=0,right=0;
        cin>>n;
        vector<long long> arr(n+1,0);
        for(int i=0; i<n ; i++)
        {
            cin>>tem;
            arr[tem]++;
        }
        right=n;
        left = 1;
        while (left +1 != right && left < right)
        {
            // cout<<"left = "<<left<<" right = "<<right<<endl;
            if(arr[left]>1 && arr[right]>1)
            {
                query += min(arr[left],arr[right])-1;
                if(arr[left]>arr[right])
                {
                    arr[left]= arr[left] - (arr[right]-1);
                    arr[right]=1;
                }
                else
                {
                    arr[right] = arr[right] - (arr[left]-1);
                    arr[left]=1;
                }
                
            }
            if(arr[right]<=1)
                right--;
            if(arr[left]<=1)
                left++;
        }
        // cout<<"query = "<<query<<endl;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>1)
            {
                ans += arr[i]-1;
            }
        }
        ans = n - ans*2 - query*2;
        if(ans<0) ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}