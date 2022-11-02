#include <bits/stdc++.h>
using namespace std;
long double maxi, mini, t;
long double a, b, c, d;
long long x, y, z, s;
int main()
{
    cout<<fixed;
    cout.precision(10);
    cin>>x>>y>>z>>s;
    a=(long double) x;
    b=(long double) y;
    c=(long double) z;
    d=(long double) s;
    maxi=(long double)1000000000;
    mini=(long double)0;
    long double eps=(long double)1/(long double)10000000000;
    while(maxi-mini>eps)
    {
        t=(maxi+mini)/2;
        long double admax, admin, bcmax, bcmin;
        admax=max(max((a-t)*(d-t), (a+t)*(d+t)), max((a-t)*(d+t), (a+t)*(d-t)));
        admin=min(min((a-t)*(d-t), (a+t)*(d+t)), min((a-t)*(d+t), (a+t)*(d-t)));
        bcmax=max(max((b-t)*(c-t), (b+t)*(c+t)), max((b-t)*(c+t), (b+t)*(c-t)));
        bcmin=min(min((b-t)*(c-t), (b+t)*(c+t)), min((b-t)*(c+t), (b+t)*(c-t)));
        bool jo=false;
        if(admin>bcmax or bcmin>admax)
        {
            jo=false;
        }
        else
        {
            jo=true;
        }
        if(jo)
        {
            maxi=t;
        }
        else
        {
            mini=t;
        }
    }
    cout<<t;
    return 0;
}