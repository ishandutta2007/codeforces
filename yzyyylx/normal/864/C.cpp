#include<bits/stdc++.h>
using namespace std;

int a,b,f,k,now,ans;

inline void GG()
{
    puts("-1");
    exit(0);
}

int main()
{
    int i,j,t;
    cin>>a>>b>>f>>k;
    now=b;
    if(now<f) GG();
    now-=f;
    for(i=1;i<k;i++)
    {
        if(i&1) t=2*(a-f);
        else t=2*f;
        if(b<t) GG();
        if(now<t) now=b,ans++;
        now-=t;
    }
    if(i&1) t=a-f;
    else t=f;
    if(b<t) GG();
    if(now<t) ans++;
    cout<<ans;
}