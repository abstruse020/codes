#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>grp(n),planes(m);
    for(int i=0; i<n; i++)cin>>grp[i];
    for(int i=0; i<m;i++)cin>>planes[i];
    sort(grp.begin(), grp.end(), greater<int>());
    sort(planes.begin(),planes.end(),greater<int>());

    if(grp[0]>planes[0])
    {
        cout<<"-1\n";
        return 0;
    }
    vector<int> stk,tme(m,0);

    int i,j=1;
    
    for(i=0; i<n-1; i++)
    {
        tme[0]++;
        if(grp[i+1]<=planes[1])
        {
            break;
        }
    }
    if(tme[0]!=0)
        tme[0] = (tme[0]-1)*2 +1;
    else
    {
        tme[0]=1;
    }
    
    i++;
    int fill_fron=0,max_till_now=tme[0];
    //j=1, i is continued
    stk.push_back(0);
    for(; i<n; i++)
    {
        if(tme[j]==max_till_now)
        {
            // cout<<" equal to max, j="<<j<<", max="<<max_till_now<<endl;
            j = (j+1)%m;
            if(grp[i]<=planes[j])
            {
                if(tme[j]==0)
                    tme[j]++;
                else tme[j] +=2;
                
            }
            else
            {
                j=0;
                if(tme[j]==0)
                    tme[j]++;
                else tme[j] +=2;
                // max_till_now++;
            }
            // cout<<"so now  j="<<j<<" max="<<max_till_now<<endl;
            max_till_now = tme[0];
        }
        else
        {
            if(tme[j]==0)
                tme[j]++;
            else tme[j] +=2;
        }
    }
    cout<<max_till_now<<endl;
    
}