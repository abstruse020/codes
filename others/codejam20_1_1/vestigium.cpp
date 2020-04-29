#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int t=0; t<test; t++)
    {
        int n,tem,ansc=0,ansr=0,trace=0;
        cin>>n;
        vector<int> mat[n];
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>tem;
                mat[i].push_back(tem);
            }
        }
        vector<int> uniq(n,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {   
                // cout<<mat[i][j]<<" ";
                uniq[mat[i][j]-1] += 1;
            }
            // cout<<"\n";
            int flag=0;
            // cout<<"uinque array \n";
            for(int j=0; j<n; j++)
            {
                // cout<<uniq[j]<<" ";
                if(uniq[j] != 1 )
                    flag=1;
                uniq[j]=0;
            }
            if(flag==1)
                ansr++;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                uniq[mat[j][i]-1]++;
                if(i==j)
                {
                    trace+=mat[i][j];
                }
            }
            int flag=0;
            for(int j=0; j<n; j++)
            {
                if(uniq[j]!=1)
                    flag=1;
                uniq[j]=0;
            }
            if(flag==1)
                ansc++;
        }
        cout<<"Case #"<<t+1<<": "<<trace<<" "<<ansr<<" "<<ansc<<"\n";
    }

    return 0;
}