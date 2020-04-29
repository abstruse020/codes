#include<bits/stdc++.h>

using namespace std;

int random(int a, int b){
	return (rand() % (b - a + 1)) + a;
}

int main()
{
    int test;
    cin>>test;
    srand(time(NULL));
    while(test--)
    {
        int n,k,m,mx=0;
        cin>>n>>m>>k;
        int mat[n][k];
        // vector<int> ans(n);
        vector<int> count(m+1,0),n1(n,1),n2(n,1),n3(n,1),n4(n,1);
        vector< vector<int>> n_all(100,vector<int>(n,1));
        vector<int> k1(k,0),k2(k,0),k3(k,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                cin>>mat[i][j];
                count[mat[i][j]]++;
            }
            if(i < n/2)  //for n2 storing n/2 max and the rest by...
            {   for(int j=1; j<m+1; j++)
                {
                    if(count[j]>mx)
                        mx = count[j];
                }
                n_all[2][i]=mx;
            }
        }
        //calc for rest of n2
        for(int i=0; i < k; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[j][i] == n_all[2][j]);
                    k2[i]==1;
            }
        }
        for(int i=0,j=n/2; i< k && j<n; i++,j++)
        {
            if(k2[i]==0)
            {
                n_all[2][j]=mat[j][i];
            }
        }
        //done for n_all 2

        //for n1 based on probability
        for(int i=0,j=1; i<n; i++)
        {
            n_all[1][i]= j;
            j++;
            if(j==m+1)
                j=1;
        }
        //done for n1

        //for n_all 3
        int t=0;
        for(int i=0; i<n; i++)
        {
            n_all[3][i]=mat[i][t];
            t = (t+1)%k;
        }

        //for n_all 4
        t=k-1;
        for(int i=0; i<n; i++)
        {
            n_all[4][i]=mat[i][t];
            t--;
            if(t==-1)
                t = k-1;
        }
        //for n_all[5] - n_all[99]
        for(int i=5; i<100; i++)
        {
            for(int j=0; j<n; j++)
            {
                n_all[i][j] = random(1,m);
            }
        }

        //checking for which we get max
        // cnt to store number of papers with at least 1 right ans
        vector<int> cnt(100,0),flag(100,0);
        vector<int> cnt_all(100,0);
        for(int i=0; i<k; i++)
        {
            for(int j2=0; j2<100; j2++)
            {
                for(int j=0; j<n; j++)
                {
                    if(mat[j][i] == n_all[j2][j])
                    {
                        flag[j2] =1;
                        cnt_all[j2]++;
                    }
                }
            }
            for(int j2=0; j2<100; j2++)
            {
                if(flag[j2]==1)
                    cnt[j2]++;
                flag[j2]=0;
            }
        }

        //mx is used in previous calc
        mx = *max_element(cnt.begin(),cnt.end());
        int index_n=0;
        for(int i=0; i<100; i++)
        {
            if(mx== cnt[i])
            {
                for(int j=0; j<n; j++) cout<<n_all[i][j]<<" ";
                break;
            }
        }
        cout<<"\n";
    }
    return 0;
}