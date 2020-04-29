#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long x,k,comp=1;
        cin>>x>>k;
        if(k != 0)
            comp = 1<<k;
        if(comp <= x)
        {
            int divisors=0;
            //#divisors(>1) >= k
            int root = sqrt(x); 
            int num = x;
            while(num%2 == 0)
            {
                num = num/2;
                divisors++;
            }
            for(int i=3; (i<= root) && num>1 ; i=i+2)
            {
                while(num%i == 0)
                {
                    num = num/i;
                    divisors++;
                }

            }
            if(num>2)
            {
                divisors++;
            }
            if(divisors>=k)
            {
                cout<<"1\n";
            }
            else
            {
                cout<<"0\n";
            }
            

        }
        else
        {
            cout<<"0\n";
        }
        
    }
    return 0;
}