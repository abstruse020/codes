#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,k,w,a,b,tem=0;
    long long primes[3]={100000007,1000000007,100000007700000049};
    cin>>n>>m>>k>>w;
    vector< pair<int,pair<int,int>>> val;
    for(int i=0; i<k ; i++)
    {
        cin>>a>>b>>tem;
        val.push_back(make_pair(a,make_pair(b,tem)));
        if(tem%1000000007!=0 && tem%100000007!=0)
        {
            val.pop_back();
        }
    }
    


    return 0;
}