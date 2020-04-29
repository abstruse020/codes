#include<iostream>
#include<vector>

using namespace std;

string makeString(unsigned long long a)
{
    // cout<<"makeString called\n";
    string str="";
    int tem;
    while(a>0)
    {
        // cout<<"in while loop\n";
        tem = a%2;
        a = a/2;
        str= (char(tem + int('0'))) + str;
    }
    return str;
}

unsigned long long computexor(string a, string b, int i)
{
    //cout<<"Computexor called\n";
    unsigned long long ans=0;
    int n = a.size();
    for(int ai=0; ai < n; ai++)
    {
        if( a[ai]==b[(ai+i)%n])
        {
            ans = ans*2;
        }
        else
        {
            ans = ans*2 +1;
        }
        
    }
    return ans;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        unsigned long long a,b;
        cin>>a>>b;
        //cout<<"input taken\n";
        string a_str, b_str,a_com,make_equal="";
        a_str= makeString(a);
        b_str = makeString(b);
        // a_com = comp(a_str);
        int alen=a_str.size(), blen = b_str.size();
        //cout<<" length of a = "<<alen<<" length of b = "<<blen<<endl;
        if( alen< blen)
        {
            for(int i=0; i<(blen - alen); i++)
                make_equal+='0';
            a_str = make_equal+a_str;
        }
        else if(blen<alen)
        {
            for(int i=0; i<(alen - blen); i++)
                make_equal+='0';
            b_str = make_equal+b_str;
        }

        unsigned long long max_val =0, lshift=0;
        for(int i=max(alen,blen); i>0; i--)
        {
            unsigned long long val= computexor(a_str,b_str,i);
            // cout<<"after op "<<alen-i<<" A^B= "<<val<<endl;
            if(val>max_val)
            {
                max_val = val;
                lshift = max(alen,blen)-i;
            }

        }
        
        cout<<lshift<<" "<<max_val<<endl;

    }

    return 0;
}