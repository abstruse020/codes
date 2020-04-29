#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,count2=0;
        cin>>n;
        vector<long long> arr(n,0);
        for(long long i=0; i<n; i++)
        {
            cin>>arr[i];
            if(abs(arr[i])%2 !=0)
                arr[i]= 1;//odd * odd
            else if(abs(arr[i])%4 ==0)
                arr[i] = 0;//even * even
            else
            {
                arr[i]=2;// even * odd
                count2++;
            }
        }
        vector< pair<long long,long long> > rem(count2,make_pair(0,0));
        long long j=0;
        long long conti=0,right=0,left=0;
        unsigned long long sum=0;
        sum = n*(n+1)/2;
        for(long long i=0; i<n; i++)
        {
            if(arr[i]==1)
                left++;
            else if(arr[i]==0)
                left =0;
            else if(arr[i]==2)
            {
                rem[j]= make_pair(left,0);
                j++;
                left =0;
            }
        }
        j= count2-1;
        for(long long i=n-1; i>=0; i--)
        {
            if(arr[i]==1)
            {
                right++;
            }
            if(arr[i]==0)
                right=0;
            else if(arr[i]==2)
            {
                rem[j].second = right;
                right=0;
                j--;
            }
        }

        for(long long i=0; i<count2; i++)
        {
            sum = sum - (rem[i].first+1)*(rem[i].second+1);
        }
        cout<<sum<<"\n";
    }
    return 0;
}