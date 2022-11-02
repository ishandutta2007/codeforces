#include <bits/stdc++.h>
using namespace std;
long long x;
int main()
{
    cin>>x;
    while(x<0) x+=360000000000000000;
    //cout<<x<<endl;
    x%=360;
    //cout<<x<<endl;
    if(x<=45 || x>=315)
    {
        cout<<0;
        return 0;
    }
    if(x<=135)
    {
        cout<<1;
        return 0;
    }
    if(x<=225)
    {
        cout<<2;
        return 0;
    }
    cout<<3;
    return 0;
}