#include <bits/stdc++.h>
#define LL long long
#define jh(a,b) a^=b^=a^=b
using namespace std;
const int N=1e5+2;
struct cow
{
    int to,val;
    cow(int to_,int val_){to=to_;val=val_;}
};
vector<cow>a[N];
LL f[N];
LL s[N];
int n;
inline void dfs(int now,int fa)
{
    for(int i=a[now].size()-1;i>=0;i--)
    {
        int to=a[now][i].to;
        if(to==fa)continue;
        dfs(to,now);
        f[now]=max(f[now],f[to]+a[now][i].val);
        s[now]+=s[to]+a[now][i].val;
    }
    return;
}
int rin()
{
    int s=0;
    char c=getchar();
    bool bj=0;
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')c=getchar(),bj=true;
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
int main()
{
    int i,j;
    int x,y,z;
    n=rin();
    for(i=1;i<n;i++)
    {
        x=rin();y=rin();z=rin();
        a[x].push_back(cow(y,z));
        a[y].push_back(cow(x,z));
    }
    dfs(1,0);
    printf("%lld\n",(s[1]<<1)-f[1]);
    return 0;
}