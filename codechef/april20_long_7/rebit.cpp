#include<bits/stdc++.h>

#define PRIME 998244353
using namespace std;
struct prob
{
    long long p0,p1,pa,p_a;
};

long long modexp(long long a, long long b,long long prime)
{
    long long res=1;
    while(b>0)
    {
        if(b & 1)
            res = (res * a)%prime;
        b = b>>1;
        a = (a*a)%prime;
    }
    return res;
}
long long modinv(long long a, long long m)
{
    long long prime = m;
    long long y = 0, x = 1;
    
    while (a > 1) 
    {
        long long l = a / m;
        long long t = m;
        m = a % m, a = t;
        t = y; 
        y = x - l * y;
        x = t;
    }
    if (x < 0) 
       x += prime; 
    return x; 
} 
prob compute(prob a, prob b, char c)
{
    prob ret = {0,0,0,0};
    if(c=='&')
    {
        ret.p0 = (a.p0*((b.p0 + b.p1 + b.pa + b.p_a)%PRIME))%PRIME + (a.p1*b.p0)%PRIME + (a.pa*((b.p0 + b.p_a)%PRIME))%PRIME + (a.p_a*((b.p0 + b.pa)%PRIME))%PRIME;
        ret.p0 = ret.p0%PRIME;
        ret.p1 = (a.p1 * b.p1)%PRIME;
        ret.p1 = ret.p1%PRIME;
        ret.pa = (a.p1*b.pa)%PRIME + ( a.pa*((b.p1 + b.pa)%PRIME) )%PRIME;
        ret.pa = ret.pa%PRIME;
        ret.p_a = (a.p1*b.p_a)%PRIME + (a.p_a*((b.p1 + b.p_a)%PRIME))%PRIME;
        ret.p_a = ret.p_a%PRIME;
    }
    else if(c=='|')
    {
        ret.p0 = (a.p0 * b.p0)%PRIME;
        ret.p0 = ret.p0%PRIME;
        ret.p1 = (a.p0 * b.p1%PRIME) + (a.p1*((b.p0 + b.p1 + b.pa + b.p_a)%PRIME))%PRIME + (a.pa*((b.p1 + b.p_a)%PRIME))%PRIME + (a.p_a*((b.p1 + b.pa)%PRIME))%PRIME;
        ret.p1 = ret.p1%PRIME;
        ret.pa = (a.p0 * b.pa)%PRIME + (a.pa*((b.p0 + b.pa)%PRIME))%PRIME;
        ret.pa = ret.pa%PRIME;
        ret.p_a = (a.p0 * b.p_a)%PRIME + (a.p_a*((b.p0 + b.p_a)%PRIME))%PRIME;
        ret.p_a = ret.p_a%PRIME;
    }
    else if(c=='^')
    {
        ret.p0 = ((a.p0*b.p0)%PRIME + (a.p1*b.p1)%PRIME + (a.pa*b.pa)%PRIME + (a.p_a*b.p_a)%PRIME)%PRIME;
        ret.p1 = ((a.p0*b.p1)%PRIME + (a.p1*b.p0)%PRIME + (a.pa*b.p_a)%PRIME + (a.p_a*b.pa)%PRIME)%PRIME;
        ret.pa = ((a.p0*b.pa)%PRIME + (a.p1*b.p_a)%PRIME + (a.pa*b.p0)%PRIME + (a.p_a*b.p1)%PRIME)%PRIME;
        ret.p_a =((a.p0*b.p_a)%PRIME + (a.p1*b.pa)%PRIME + (a.pa*b.p1)%PRIME + (a.p_a*b.p0)%PRIME)%PRIME;
    }
    return ret;
}


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long len=0,i=0,j=0,q=0,p=0,counop=0,q_inv=0;
        prob tem;
        string str;
        cin>>str;
        len = str.length();
        for(i=0; i<len; i++)
        {
            if(str[i]=='#')
                counop++;
        }
        vector<prob> probs;
        vector<char> symbol;
        for(i=0,j=-1; i<len; i++)
        {
            if(str[i]=='#')
            {
                probs.push_back({1,1,1,1});
                j++;
            }
            if(str[i]=='&' || str[i]=='|' || str[i]=='^')
            {
                symbol.push_back(str[i]);
            }
            if(str[i]==')')//assuming (#) does not exist
            {
                tem = compute(probs[j], probs[j-1], symbol.back());
                symbol.pop_back();
                probs.pop_back();
                j--;
                probs.pop_back();
                //j-- and then j++
                probs.push_back(tem);
            }
        }
        //compute q
        q = modexp(4,counop, 998244353);
        //compute qinv;
        q_inv = modinv(q,998244353);
        
        cout<<(probs[0].p0*q_inv)%998244353<<" ";
        cout<<(probs[0].p1*q_inv)%998244353<<" ";
        cout<<(probs[0].pa*q_inv)%998244353<<" ";
        cout<<(probs[0].p_a*q_inv)%998244353;
        
        cout<<"\n";
    }
    return 0;
}