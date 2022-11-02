#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n;
pair<long long, int> v[200009];
bool van_div2=false;
long long pref[200009];
long long mini, maxi;
int main()
{
    cin>>n;
    pref[0]=0;
    for(int i=1; i<=n; i++)
    {
        long long xx, yy;
        cin>>xx>>yy;
        v[i].F=xx;
        v[i].S=yy;
        if(v[i].S==2) van_div2=true;
        pref[i]=pref[i-1]+v[i].F;
    }
    if(!van_div2)
    {
        cout<<"Infinity"<<endl;
        return 0;
    }
    mini=-20000009;
    maxi=20000009;
    for(int i=1; i<=n; i++)
    {
        if(v[i].S==1)
        {
            //x+pref[i-1]>=1900
            //cout<<"min: "<<1900-pref[i-1]<<endl;
            mini=max(mini, 1900-pref[i-1]);
            //cout<<" realmin: "<<mini<<endl;
        }
        else
        {
            //x+pref[i-1]<=1899
            //cout<<"max: "<<1899-pref[i-1]<<endl;
            maxi=min(maxi, 1899-pref[i-1]);
            //cout<<" realmax: "<<maxi<<endl;
        }
    }
    if(mini>maxi)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout<<maxi+pref[n]<<endl;
    return 0;
}