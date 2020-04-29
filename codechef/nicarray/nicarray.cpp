#include<bits/stdc++.h>

#define ll long long
#define PRIME 1000000007
using namespace std;


vector<ll> store_ele,arr;
ll ans=0;

// modular exponentiation
ll mod_exp(ll x,ll y)
{
    ll result=1;
    x= x%PRIME;
    if(x==0) return 0;
    while (y>0)
    {
        if(y & 1)
            result = (result*x)%PRIME;
        y = y>>1;
        x = (x*x)%PRIME;
    }
    return result;
}
//modulo inverse by extended eucledian
ll modinv_extended(ll a, ll m=PRIME)
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
    // Make x positive 
    if (x < 0) 
       x += m0; 
    return x; 
}
//modulo inverse by fermets little theorem
ll modinv_fermats(ll a, ll m=PRIME)
{
    ll tem;
    // cout<<"Mod inv of "<<a<<" , = ";
    tem = mod_exp(a,m-2);
    // cout<<tem<<endl;
    return tem;
}

ll gcd(ll a, ll b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

ll fact(ll a)
{
    ll fact_a=1;
    for(int i=2; i<=a; i++)
        fact_a = (fact_a*i)%PRIME;
    return fact_a;
}
ll ans_times(vector<ll> &store_ele)
{
    ll result=1;
    vector<ll> num(51,0);
    for(int i=0; i<store_ele.size(); i++)
    {
        num[store_ele[i]]++;
    }
    result = fact(store_ele.size());
    for (int i = 1; i <= 50; i++)
    {
        if(num[i]!=0 && num[i]!=1)
            result = ( result * modinv_fermats(fact( num[i] )) )%PRIME;
    }
    return result%PRIME;
}

void calc()
{
    ll temp_ans=0;
    for(int i=0; i<store_ele.size(); i++)
        arr.push_back(store_ele[i]);

    for(int i=0; i<arr.size(); i++)
    {
        for(int j=i+1; j<arr.size(); j++)
        {
            temp_ans = (temp_ans+gcd(arr[i],arr[j]))%PRIME;
        }
    }
    for (int i = 0; i < store_ele.size(); i++)
        arr.pop_back();
    temp_ans = (temp_ans*ans_times(store_ele))%PRIME;
    ans = (ans+temp_ans)%PRIME;

    // cout<<"For combination = ";
    // for(int i=0; i<store_ele.size(); i++)
    //     cout<<store_ele[i]<<" ";
    // cout<<"ans for it = "<<temp_ans<<" ";
    // cout<<"\nupdated ans = "<<ans<<endl;
}

void rec_func(ll n, ll s, ll min_num)
{
    if(s==0 && n==0)
    {
        calc();
        return;
    }
    else if (s<=0 || n<=0) return;
    
    
    else if(n > 0 && s>0)
    {
        for(int i= min_num ; i < s+1 ; i++)
        {
            store_ele.push_back(i);
            rec_func(n-1, s-i, i);
            store_ele.pop_back();
        }
    }
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        ll N,S,tem_num,s=0,n=0;
        cin>>N>>S;
        arr.clear();
        for(int i=0; i<N; i++)
        {
            cin>>tem_num;
            if(tem_num != -1)
            {
                arr.push_back(tem_num);
                s += tem_num;
            }
        }
        n = N- arr.size();
        s = S-s;
        rec_func(n,s,1);
        
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}