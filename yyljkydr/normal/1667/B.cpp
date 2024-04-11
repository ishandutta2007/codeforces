#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e5+1e3+7;

int T,n,a[N],s[N];

vector<int>S;

struct BIT{
    int c[N];

    void add(int x,int v)
    {
        while(x<=n+1)
        {
            c[x]=max(c[x],v);
            x+=x&-x;
        }
    }

    int query(int x)
    {
        int ret=-1e9;
        while(x)
        {
            ret=max(ret,c[x]);
            x-=x&-x;
        }
        return ret;
    }
}B[2];

map<int,int>mx;

int f[N];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        S.clear();
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]),s[i]=s[i-1]+a[i],S.push_back(s[i]);
        S.push_back(s[0]);
        sort(S.begin(),S.end());
        for(int i=0;i<=n;i++)
            s[i]=lower_bound(S.begin(),S.end(),s[i])-S.begin()+1;
        mx.clear();
        fill(B[0].c+1,B[0].c+n+2,-1e9);
        fill(B[1].c+1,B[1].c+n+2,-1e9);
        for(int i=1;i<=n;i++)
        {
            B[0].add(s[i-1],f[i-1]-(i-1));
            B[1].add(n+1-s[i-1]+1,f[i-1]+(i-1));
            mx[s[i-1]]=max(mx[s[i-1]],f[i-1]);
            if(!mx.count(s[i]))
                mx[s[i]]=-1e9;
            f[i]=max({mx[s[i]],B[0].query(s[i]-1)+i,B[1].query(n+1-(s[i]+1)+1)-i});
        }
        printf("%lld\n",f[n]);
    }
}