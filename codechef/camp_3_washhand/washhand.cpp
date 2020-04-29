#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,d,ans=0,i=0;
        cin>>n;
        string bstr2;
        cin>>bstr2;
        vector<int> bstr(n);
        for(i=0; i<n; i++)
        {
            bstr[i] = int(bstr2[i]) - int('0') -1;
        }
        cin>>d;
        vector<int> darr(d);
        for(i=0; i<d ; i++)
            cin>>darr[i];

        for(i=1; i<n; i++)
        {
            if(bstr[i]==0)
                continue;
            if(bstr[i-1]!=-1)
            {
                bstr[i]= bstr[i-1]+1;
            }
        }
        for(i=n-2; i>=0; i--)
        {
            if((bstr[i]>bstr[i+1]+1) && bstr[i+1]!= -1)
                bstr[i] = bstr[i+1]+1;
            if(bstr[i]==-1 && bstr[i+1]!=-1)
                bstr[i] = bstr[i+1]+1;
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     cout<<bstr[i];
        //     if(bstr[i]==-1)
        //         cout<<"Error -1 in string \n";
        // }
        vector<int> change(n,0);
        for(i=0; i<d; i++)
        {
            if(bstr[darr[i]-1]==bstr[darr[i]-2])
            {
                continue;
            }
            else if(bstr[darr[i]-1] == 1 + bstr[darr[i]-2] && i < bstr[darr[i]-1])
            {
                bstr[darr[i]-1] = -1;
                change[darr[i]-2] = 1;
            }
            else if(bstr[darr[i]-1] + 1 == bstr[darr[i]-2] && i < bstr[darr[i]-2])
            {
                bstr[darr[i]-2] = -1;
                change[darr[i]-2] = 1;
            }
        }

        // for(int i=0; i<n; i++)
        //     cout<<bstr[i]<<" ";
        // cout<<"\n output ended\n";
        sort(darr.begin(),darr.end());
        vector<int> devid_str[d+1];
        int j;
        for(i=0,j=0; i<n && j<=d; i++)
        {
            if(change[i]==1)
            {
                devid_str[j].push_back(bstr[i]);
                j++;
            }
            else
            {
                devid_str[j].push_back(bstr[i]);
            }
        }
        for(i=0; i<=d ; i++)
        {
            int haszero=0;
            int l = devid_str[i].size();
            if(l==0)
                continue;
            for(j=0; j< devid_str[i].size(); j++)
            {
                if(devid_str[i][j] == 0)
                    haszero=1;
            }
            if(haszero==0 && (devid_str[i][0]==-1 || devid_str[i][l-1]==-1))
            {
                for(j=0; j< devid_str[i].size(); j++)
                {
                    devid_str[i][j] = -1;
                }
            }
            if(haszero==1 && (devid_str[i][0]==-1 || devid_str[i][l-1]==-1))
            {
                
                if(devid_str[i][0] == -1)
                {
                    devid_str[i][0] = devid_str[i][1]+1;
                }
                else if (devid_str[i][l-1] == -1)
                {
                    devid_str[i][l-1] = devid_str[i][l-2]+1;
                }
            }
            haszero=0;
        }


        for(i=0; i<=d; i++)
        {
            for(j=0; j<devid_str[i].size(); j++)
            {
                cout<<devid_str[i][j]<<" ";
                if(devid_str[i][j]!=-1 && devid_str[i][j] <=d)
                    ans++;
            }
            cout<<"\n";
        }
        cout<<ans<<endl;
    }

    return 0;
}
// Error on input
// 2
// 19
// 0000100001010011010
// 3
// 2 5 8 7 3
// 5
// 00001
// 1
// 5