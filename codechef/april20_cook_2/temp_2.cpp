#include<bits/stdc++.h>
#define ll long long
#define PRIME 1000000007
using namespace std;

struct trip
{
    long long t,x,a,index;
};
bool boolfn(trip t1, trip t2)
{
    return t1.x < t2.x;
}
int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        ll h,n;
        double slope=0,upview=1000000001,dwnview;
        cin>>h>>n;
        vector<trip> poles(n);
        vector<long long> ans(n,0);
        for(int i=0; i<n;i++)
        {
            cin>>poles[i].t>>poles[i].x>>poles[i].a;
            poles[i].index=i;
        }

        sort(poles.begin(),poles.end(), boolfn);
        
        for(int i=0; i<n; i++)
        {
            upview=1000000001;
            dwnview=-1000000001;
            for(int j=i+1; j<n; j++)
            {
                if(poles[i].x==poles[j].x)
                {
                    ans[poles[i].index]++;
                    ans[poles[j].index]++;
                    continue;
                }
                slope = poles[j].a - poles[i].a;
                slope = slope/(poles[j].x - poles[i].x);
                if(poles[j].t==0)
                {
                    if(upview > slope && slope > dwnview)
                    {
                        ans[poles[i].index]++;
                        ans[poles[j].index]++;
                        
                    }
                    if(slope > dwnview)
                        dwnview = slope;
                }
                else
                {
                    if(upview > slope && slope > dwnview) 
                    {
                        ans[poles[i].index]++;
                        ans[poles[j].index]++;
                        upview = slope;
                    }
                    if(slope < upview)
                        upview = slope;
                }

            }
            
        }
        // vector<long long> new_ans(n);
        // for(int i=0; i<n; i++)
        // {
        //     new_ans[poles[i].index]=ans[i];
        // }
        for(int i=0; i<n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
    
}