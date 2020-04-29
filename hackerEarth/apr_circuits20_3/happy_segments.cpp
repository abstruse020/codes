#include<bits/stdc++.h>

using namespace std;
long sqrt_n =0;
struct qr
{
    long x,y,index;
};

bool comp(qr a, qr b)
{
    if((a.x-1)/sqrt_n != (b.x-1)/sqrt_n)
        return (a.x-1)/sqrt_n < (b.x-1)/sqrt_n;
    else
    {
        return a.y < b.y;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,m,q,curL=0,curR=0,L=0,R=0,unq_count=0,prev_correct=0;
    cin>>n>>m;
    sqrt_n = sqrt(n)-1;
    vector<long> arr(n),freq(m),count_m(m,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<m; i++)
        cin>>freq[i];
    cin>>q;
    vector<qr> query(q);
    vector<long> ans(q,0);
    for(int i=0; i<q; i++){
        cin>>query[i].x>>query[i].y;
        query[i].index = i;
    }
    sort(query.begin(), query.end(), comp);
    int ind=0;
    for(int i=0; i<q; ++i)
    {
        
        // set<long long> my_set;
        L = query[i].x-1;
        R = query[i].y-1;
        // int deleted=0;

        while (curL<L)
        {
            ind = arr[curL]-1;
            --count_m[ind];

            if(count_m[ind] == 0)
                --unq_count;

            if(count_m[ind]==freq[ind])
            {
                ++ans[query[i].index];
            }
            else if(count_m[ ind] == freq[ind]-1)
            {
                --ans[query[i].index];
            }
            ++curL;
        }
        while (curL>L)
        {
            --curL;
            ind =arr[curL]-1;
            
            // my_set.insert(arr[curL]);

            ++count_m[ind];

            if(count_m[ind] == 1)
                ++unq_count;

            if(count_m[ind]==freq[ind])
            {
                ++ans[query[i].index];
            }
            else if(count_m[ind] == freq[ind]+1 )
            {
                --ans[query[i].index];
            }
        }
        while (curR < R+1)
        {
            ind = arr[curR]-1;

            ++count_m[ind];

            if(count_m[ind] == 1)
                ++unq_count;

            // if(count_m[ arr[curR]-1 ]== 0 || count_m[arr[curR]-1]==freq[arr[curR]-1])
            if(count_m[ind]==freq[ind])
            {
                ++ans[query[i].index];
            }
            else if(count_m[ind]==freq[ind]+1)
            {
                --ans[query[i].index];
            }
            ++curR;
        }
        while (curR > R+1)
        {
            --curR;
            ind =arr[curR]-1;
            --count_m[ind];

            if(count_m[ind] ==0)
                --unq_count;

            if(count_m[ind] == freq[ind])
            {
                ++ans[query[i].index];
            }
            else if(count_m[ind] == freq[ind]-1)
            {
                --ans[query[i].index];
            }
        }
        // ans[query[i].index]+=my_set.size();
        prev_correct = ans[query[i].index]+prev_correct;
        if(prev_correct== unq_count)
        {
            // prev_correct = ans[query[i].index]+prev_correct;
            ans[query[i].index]=1;
        }
        else {
            // prev_correct = ans[query[i].index]+prev_correct;
            ans[query[i].index]=0;
        }
    }
    for(int i=0; i<q; i++)
        printf("%ld\n",ans[i]);
    
    return 0;
}