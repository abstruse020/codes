#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int t=0; t<test; t++)
    {
        int n,c=0,j=0,impossible=0;
        string ans="";
        cin>>n;
        vector<pair<int, int>> times(n);
        for(int i=0; i<n; i++)
        {
            cin>>times[i].first>>times[i].second;
        }
        vector<pair<int, int>> times_cpy(times);
        sort(times.begin(), times.end());
        for(int i=0; i<n ; i++)
        {
            if(j<c)
            {
                if(j<=times[i].first)
                {
                    j = times[i].second;
                    ans = ans + 'J';
                }
                // else if(c<=times[i].first)
                // {
                //     c = times[i].second;
                //     ans = ans + 'C';
                // }
                else
                {
                    impossible=1;
                    break;
                }
            }
            else
            {
                if(c<= times[i].first)
                {
                    c = times[i].second;
                    ans = ans + 'C';
                }
                // else if(j<=times[i].first)
                // {
                //     j = times[i].second;
                //     ans = ans + 'J';
                // }
                else
                {
                    impossible=1;
                    break;
                }
                
            }
        }
        if(impossible==1)
        {
            cout<<"Case #"<<t+1<<": "<<"IMPOSSIBLE\n";
        }
        else
        {
            string finalans="";
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(times[j].first == times_cpy[i].first && times[j].second == times_cpy[i].second)
                    {
                        // cout<<" i = "<<i<<", j = "<<j;
                        finalans = finalans + ans[j];
                        if(ans[j]=='C')
                            ans[j] = 'J';
                        else
                        {
                            ans[j] = 'C';
                        }
                        
                        break;
                    }
                }
            }
            cout<<"Case #"<<t+1<<": "<<finalans<<"\n";
        }
        
    }
    return 0;
}