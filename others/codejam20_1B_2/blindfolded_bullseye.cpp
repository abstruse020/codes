#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,a,b;
    cin>>test>>a>>b;
    for(int t=0; t<test; t++)
    {
        // cout<<0<<" "<<0<<endl;
        int center_found=0;
        string ip="";
        // cin>>ip;
        long long l=0,r=1000000000,m=(l+r)/2;
        long long x1=0;
        cout<<r<<" "<<0<<endl;
        fflush(stdout);
        cin>>ip;
        if(ip=="CENTER")
        {
            center_found=1;
            x1 = r;
        }
        else if(ip=="WRONG")
        {
            return 0;
        }
        if(center_found==1)
            continue;
        int count=1;
        if(x1!=r)
        {
            while (l+1<r && count<=300)
            {
                count++;
                cout<<m<<" "<<0<<endl;
                fflush(stdout);
                cin>>ip;
                if(ip=="CENTER")
                {
                    x1 = m;
                    center_found=1;
                    break;
                }
                else if(ip=="HIT")
                {
                    l = m;
                }
                else if(ip == "MISS")
                {
                    r = m;
                }
                else if(ip=="WRONG")
                {
                    return 0;
                }
                m = (l+r)/2;
            }
            if(center_found==1)
            {
                continue;
            }
            if(count>=300)
            {
                return 0;
            }
        }
        x1=l;
        // cout<<"x1 = "<<x1<<endl;
        long long x2=l;
        long long cx=0,cy=0;
        l=-1000000000;
        r = 0;
        m=(l+r)/2;
        cout<<l<<" "<<0<<endl;
        fflush(stdout);
        cin>>ip;
        count++;
        if(ip=="CENTER")
        {
            center_found=1;
            cx = (x1+x2)/2;
        }
        else if(ip=="WRONG")
        {
            return 0;
        }
        else //finding x2;
        {
            while(l+1<r && count<=300)
            {
                count++;
                cout<<m<<" 0"<<endl;
                fflush(stdout);
                
                cin>>ip;
                if(ip=="CENTER")
                {
                    x2=m;
                    break;
                }
                else if(ip=="HIT")
                {
                    r =m;
                }
                else if(ip=="MISS")
                {
                    l =m;
                }
                else if(ip=="WRONG")
                    return 0;
                m = (l+r)/2;
            }
            if(center_found==1)
                continue;
            if(count>=300)
            {
                return 0;
            }
        }
        if(center_found==1)
            continue;
        x2=r;
        // cout<<"x2 = "<<x2<<endl;
        cx = (x2+x1)/2;
        long long diff= abs(x1-cx);
        cy = a*a - diff*diff;
        cy = sqrt(cy);
        cout<<cx<<" "<<cy<<endl;
        fflush(stdout);
        cin>>ip;
        if(ip=="CENTER")
        {
            continue;
        }
        else if(ip=="WRONG")
        {
            return 0;
        }
        else
        {
            cout<<cx<<" "<<cy-1<<endl;
            fflush(stdout);
            cin>>ip;
            return 0;
        }

        
    }

}