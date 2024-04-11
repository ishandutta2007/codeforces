#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T;

int a,b;

int get(int x)
{
    if(!x)
        return 0;
    return get(x>>1)+1;
}

int rev(int x,int d)
{
    if(!x)
        return 0;
    if(d==-1)
        d=get(x);
    return rev(x>>1,d-1)|(x&1)<<(d-1);
}

map<int,int>vis;

int go(int x)
{
    if(x==b)
        return 1;
    if(x>b*2)
        return 0;
    if(vis.count(x))
        return vis[x];
    int &ret=vis[x];
    ret|=go(rev(x<<1|1,-1));
    if(ret)
        return ret;
    if(x&1)
        ret|=go(rev(x,-1));
    return ret;
}

signed main()
{
    scanf("%lld%lld",&a,&b);
    if(go(a)||go(rev(a,-1)))
        puts("YES");
    else
        puts("NO");
}