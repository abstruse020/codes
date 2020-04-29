#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,max_a=0,max_b=0,temp_input;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>temp_input;
            if(temp_input>max_a)
                max_a=temp_input;
        }
        for(int i=0; i<n; i++)
        {
            cin>>temp_input;
            if(temp_input>max_b)
                max_b=temp_input;
        }
        if(max_a==max_b)
            cout<<"NO\n";
        else
            cout<<"YES\n";

    }
    return 0;
}