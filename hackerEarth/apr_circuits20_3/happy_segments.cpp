#include<bits/stdc++.h>
using namespace std;
const int max_int = 5e5+10;
int n,m,q,curL=0,curR=0,L=0,R=0,unq_count=0,prev_correct=0;
int arr[max_int],freq[max_int],count_m[max_int];

int ans[max_int];

int sqrt_n =0;
struct qr
{
    int x,y,index;
};
qr query[max_int];

bool comp(qr a, qr b)
{
    if((a.x)/sqrt_n != (b.x)/sqrt_n)
        return (a.x)/sqrt_n < (b.x)/sqrt_n;
    else
    {
        return a.y < b.y;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    sqrt_n = sqrt(n);
    // vector<long> arr(n),freq(m),count_m(m,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<m; i++)
        cin>>freq[i];
    cin>>q;
    // vector<qr> query(q);
    // vector<long> ans(q,0);
    for(int i=0; i<q; i++){
        cin>>query[i].x>>query[i].y;
        query[i].x--;
        query[i].y--;
        query[i].index = i;
        ans[i]=0;
    }
    sort(query, query + q, comp);
    // int ind=0;
    for(int i=0; i<q; ++i)
    {
        
        // set<long long> my_set;
        L = query[i].x;
        R = query[i].y;
        // int deleted=0;

        while (curL<L)
        {
            count_m[arr[curL]-1]--;
            curL++;
        }
        while (curL>L)
        {
            curL--;
            count_m[arr[curL]-1]++;
        }
        while (curR < R+1)
        {
            
            count_m[arr[curR]-1]++;
            curR++;
        }
        while (curR > R+1)
        {
            
            curR--;
            count_m[arr[curR]-1]--;
        }
        
        for(int j=L; j<=R; j++)
        {
            // cout<<"Compairing the numbers"<<arr[j]<<" its freq = "<<freq[arr[j]-1]<<endl;
            if(count_m[arr[j]-1] != freq[arr[j]-1])
                ans[query[i].index]=-1;
        }

    }
    for(int i=0; i<q; i++)
        printf("%d\n",ans[i]+1);
    
    return 0;
}