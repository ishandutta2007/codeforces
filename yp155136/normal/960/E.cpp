#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

const LL mod = 1000000007;
const int N = 200006;

LL v[N];

vector<int> G[N];

bool vis[N];

LL ans=0;

int sz[N],mx[N];

vector<int> v_cen;

void dfs_cen(int now,int par)
{
    sz[now] = 1;
    mx[now] = 0;
    v_cen.push_back(now);
    for (int i:G[now])
    {
        if (i==par || vis[i]) continue;
        dfs_cen(i,now);
        sz[now] += sz[i];
        mx[now] = max(mx[now],sz[i]);
    }
}

int get_cen(int x)
{
    dfs_cen(x,x);
    int tot = v_cen.size();
    int ret=-1;
    for (int i:v_cen)
    {
        if (max(mx[i],tot-sz[i]) <= tot/2)
        {
            ret = i;
        }
    }
    assert(ret != -1);
    v_cen.clear();
    return ret;
}

LL Val(LL x)
{
    return (x%mod + mod)%mod;
}

LL odd=0,even=0;
LL oddcnt = 0,evencnt=0;

void dfs2(int now,int par,int depth,LL pre)
{
    if (depth%2==1)
    {
        pre += v[now];
        odd += pre;
        ++oddcnt;
        odd = Val(odd);
    }
    else if (depth%2==0)
    {
        pre -= v[now];
        even += pre;
        ++evencnt;
        even = Val(even);
    }
    pre = Val(pre);
    for (int i:G[now])
    {
        if (i == par || vis[i]) continue;
        dfs2(i,now,depth+1,pre);
    }
}

#define F first
#define S second

void dfs(int now)
{
    int cen = get_cen(now);
    vis[cen] = 1;
    for (int i:G[cen])
    {
        if (!vis[i]) dfs(i);
    }
    odd = even = 0;
    vector<pii> vodd,veven;
    for (int i:G[cen])
    {
        if (!vis[i])
        {
            odd = even = 0;
            oddcnt = evencnt = 0;
            dfs2(i,i,0,0);
            ans += ((odd + oddcnt*v[cen])*2);
            ans = Val(ans);
            vodd.push_back(make_pair(odd,oddcnt));
            veven.push_back(make_pair(even,evencnt));
        }
    }
    //now it is time to conquer
    vis[cen] = 0;
    //odd and odd first
    LL totodd=0,totoddcnt=0;
    for (pii p:vodd)
    {
        totodd += p.F;
        totoddcnt += p.S;
    }
    totodd = Val(totodd);
    for (pii p:vodd)
    {
        ans += Val(p.S * (totoddcnt - p.S)) * v[cen];
        ans = Val(ans);
        ans += p.F * (totoddcnt - p.S);
        ans = Val(ans);
        ans += Val(totodd - p.F) * p.S;
        ans = Val(ans);
    }
    //even and even
    LL toteven = 0,toteventcnt=0;
    for (pii p:veven)
    {
        toteven += p.F;
        toteventcnt += p.S;
    }
    toteven = Val(toteven);
    LL tmp=0;
    for (pii p:veven)
    {
        tmp += Val(p.S * (toteventcnt - p.S)) * v[cen];
        tmp = Val(tmp);
        tmp += p.F * (toteventcnt - p.S);
        tmp = Val(tmp);
        tmp += Val(toteven - p.F) * p.S;
        tmp = Val(tmp);
    }
    ans -= tmp;
    ans = Val(ans);
}

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&v[i]);
        ans += v[i];
    }
    ans = Val(ans);
    for (int i=1;n>i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);
    printf("%lld\n",ans);
}