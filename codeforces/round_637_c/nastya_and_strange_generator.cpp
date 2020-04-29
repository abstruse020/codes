#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        long long n,i=0;
        int possible=1,count=0;
        cin>>n;
        vector<long long> arr(n);
        vector<int> mat(n+1,0),pos(n+1);
        for(int i=0; i<n; i++){
            cin>>arr[i];
            mat[arr[i]]++;
            pos[arr[i]]=i+1;
        }
        int start = pos[1];
        int prev = -1;
        // for(int i=0 ; i<n-1; i++)
        // {
        //     if(start<n)
        //     {
        //         arr[start-1 +1]== 1 + arr[start-1];
        //         start++;
        //     }
        // }
        int upto=1,from=arr[n-1];
        int tem_num=from;
        int last_dist=0;
        for(int i=n-1; i>0; i--)
        {
            if(arr[i]==tem_num)
            {
                last_dist++;
                count++;
                tem_num--;
            }
            if(arr[i]==upto)
            {
                last_dist=0;
                upto = from+1;
                from = arr[i-1];
                tem_num=from;
            }
        }
        if(upto + last_dist == from)
        {
            count++;
        }
        if(count==n)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    
    return 0;

}