#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int m,n,ans=0;
        cin>>m>>n;
        vector<vector<char>> mat(m, vector<char> (n,'0'));
        vector<int> left(m,-1),right(m,-1);
        for(int i=0; i<m ; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
            }
        }
        pair<int, int> firstpos,prev;
        int firstFlag=0;

        for(int i=0; i<m; i++)
        {
            if(i%2==0){
                for(int j=0; j<n; j++)
                {
                    if(mat[i][j]=='P' && firstFlag==0)
                    {
                        firstpos.first = i;
                        prev.first = i;
                        firstpos.second = j;
                        prev.second = j;
                        firstFlag=1;
                        continue;
                    }
                    if(mat[i][j] == 'P' && prev.first == i)//p of same line
                    {
                        ans += abs(prev.second - j);
                        prev.first = i;
                        prev.second = j;
                    }
                    if(mat[i][j] == 'P' && prev.first != i)
                    {
                        ans+= abs(prev.first - i) + abs(prev.second - j);
                        prev.first = i;
                        prev.second = j;
                    }

                }
            }
            else
            {
                for(int j=n-1;j>=0; j--)
                {
                    if(mat[i][j]=='P' && firstFlag==0)
                    {
                        firstpos.first = i;
                        prev.first = i;
                        firstpos.second = j;
                        prev.second = j;
                        firstFlag=1;
                        continue;
                    }
                    if(mat[i][j] == 'P' && prev.first == i)//p of same line
                    {
                        ans += abs(prev.second - j);
                        prev.first = i;
                        prev.second = j;
                    }
                    if(mat[i][j] == 'P' && prev.first != i)
                    {
                        ans+= abs(prev.first - i) + abs(prev.second - j);
                        prev.first = i;
                        prev.second = j;
                    }
                }
            }
            
        }
        cout<<ans<<"\n";
    }

    return 0;
}