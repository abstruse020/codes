#include<bits/stdc++.h>

using namespace std;

string ll_to_bi(long long n)
{
    string str;
    while (n>=1)
    {
        str = char((n & 1)+'0') + str;
        n = n>>1;
    }
    
    return str;
}
long long bi_to_ll(string str)
{
    long long result=0;
    for(int i=0; i<str.length(); i++)
    {
        result = result*2 + int(str[i])-int('0');
    }
    return result;
}

int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        long long n,k,ans,tem=0;
        cin>>n>>k;
        string str = ll_to_bi(n);
        string ans_str="";
        // cout<<"ll to string ="<<str<<endl;
        for(int i=1; i<str.length(); i++)
        {
            ans_str += str[i];
        }
        ans_str =ans_str + '0';
        // cout<<"ans string = "<<ans_str<<" length ="<<ans_str.length()<<endl;
        ans = bi_to_ll(ans_str); 
        if(ans==0)
            ans = n;
        // cout<<"left shift of n by 1 ="<<ans<<endl;
        tem = (2*k +2)%n;
        if(tem==0) tem=n;
        ans = (ans + tem -1 )%n;
        if(ans==0) ans=n;
        cout<<ans<<endl;
    }
    return 0;
}