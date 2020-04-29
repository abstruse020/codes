#include<bits/stdc++.h>

using namespace std;

long long recur(vector<long long> &arr, long long index)
{
    
}

int main()
{
    long long test;
    cin>>test;
    while(test--)
    {
        long long n;
        cin>>n;
        vector<long long> arr(n);
        vector<pair<long long, long long>> arr_sort;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        long long prev=0;
        for(int i=0,j=0; i<n; i++)
        {
            if(arr[i]==prev)
            {
                arr_sort[j].second++;
            }
            else
            {
                j++;
                arr_sort.push_back({arr[i],1});
            }
        }

        
        

    }
    return 0;
}