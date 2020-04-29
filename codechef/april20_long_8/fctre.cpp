#include<bits/stdc++.h>
#define PRIME 1000000007
using namespace std;

void dfs(vector<vector<int>> &adj, long long u, long long v, vector<long long> &visited, vector<long long> &result)
{
    visited[u]=1;
    for(int i=0; i<adj[u].size(); i++)
    {
        long long curr_node = adj[u][i];
        if(adj[u][i]==v)
        {
            result.push_back(curr_node);
            break;
        }
        if(!visited[curr_node])
        {
            dfs(adj, curr_node, v, visited,result);
        }
        if(!result.empty())
        {
            result.push_back(curr_node);
            break;
        }
    }
}
void newdfs(vector<vector<int>> &adj ,vector< vector<int>> &mat_nn, int u, int col, vector<int> &visited1)
{
    visited1[u]=1;
    for(int i=0; i< adj[u].size(); i++)
    {
        int curr_node = adj[u][i];
        
        if(!visited1[curr_node])
        {
            mat_nn[col][curr_node] = u;
            newdfs(adj, mat_nn, curr_node, col, visited1);
        }
    }
}

vector<int> allprime(1000001,0);
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,tem1=0,tem2=0,q;
        cin>>n;
        vector<vector<int>> adj(n+1);
        vector<long long> A(n);
        vector< map<long long,long long> > primefactors(n+1);
        for(long i=0; i<n-1; i++)
        {
            cin>>tem1;
            cin>>tem2;
            adj[tem1].push_back(tem2);
            adj[tem2].push_back(tem1);

        }
        for(int i=0; i<n; i++)
            cin>>A[i];

        //sieve used later for prime factorization
        vector<long long> prm;
        long long primeno=-1;
        allprime[1]=0;
        prm.push_back(0);
        for(int i=2; i<1001; i++)
        {
            if(allprime[i]==0)
            {
                // allprime[i] = primeno;//numbering primes 0(for 1),-1(for 2),-2(for3) etc for prm
                // primeno--;
                // prm.push_back(0);
                for (int j = i*i; j < 1000001; j=j+i)
                {
                    if(allprime[j]==0)
                        allprime[j]=i; //storing smallest divisible prime
                }
                
            }
        }
        // cout<<"number of primes upto 10^6 = "<<prm.size();
        // for(int i=0; i<n; i++)
        // {
        //     primes[i]= prm;
        // }
        //nXp matrix with all zero

        for(int i=0; i<n; i++)
        {
            while(A[i]>1)
            {
                if(allprime[ A[i] ] <= 0)//already prime
                {
                    primefactors[i][A[i]]++;
                    // primes[i][-allprime[A[i]]]++;
                    A[i] = 1;
                }
                else
                {
                    primefactors[i][ allprime[A[i]] ]++;
                    // primes[i][ -allprime[ allprime[A[i]] ]]++; //first allprime to get prime and second for pos of it in nXp
                    A[i] = A[i]/allprime[A[i]];
                }
            }
        }
        //new dfs for storing paths
        vector< vector<int> > mat_nn(n+1, vector<int>(n+1,0));
        vector<int> visited1(n+1,0);
        for(int i=1; i<n+1; i++)
        {
            newdfs(adj, mat_nn, i, i, visited1);
            for(int i=0; i<n+1; i++)
                visited1[i]=0;
        }
        // for(int i=1; i<n+1; i++)
        // {
        //     for(int j=1; j<n+1; j++)
        //     {
        //         cout<<mat_nn[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cin>>q;
        while(q--)
        {
            long long u,v,tem_pf=0;
            cin>>u>>v;
            vector<long long> visited(n+1,0),result;
            result.push_back(v);
            if(u!=v)
            {
                int last=v;
                while(last != u)
                {
                    last = mat_nn[u][last];
                    result.push_back(last);
                }
            }
            // if(u!=v)
            //     dfs(adj,u,v,visited,result);
            // result.push_back(u);

            map<long long,long long> freq;
            for(int i=0; i<result.size(); i++)
            {
                map<long long, long long> pf = primefactors[ result[i]-1];
                for(auto pf_itr=pf.begin(); pf_itr!= pf.end(); pf_itr++)
                {
                    tem_pf = pf_itr->first;
                    freq[tem_pf] = (freq[tem_pf] + pf_itr->second)%PRIME;
                    // prm[j] = (prm[j]+primes[ result[i] ][j])%PRIME;
                }
            }
            long long ans=1;

            for(auto freq_itr=freq.begin(); freq_itr != freq.end() ; freq_itr++)
            {
                // cout<<"prime = "<<freq_itr->first<<" freq = "<<freq_itr->second<<"\n";
                ans = (ans*(freq_itr->second + 1))%PRIME;
            }
            cout<<ans<<endl;
        }
    }
}