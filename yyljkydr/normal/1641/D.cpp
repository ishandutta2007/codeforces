#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7,bs=1313131,P=(1ll<<61)-1;

int n,m;

int a[N][6],w[N];

int r[N],b[N][6],ww[N];

int hs[N][33];

// unordered_multiset<int>s[33];

int bit[33];

const int M=1e6+7;

struct HSMP{
    vector<pair<int,int> >v[M];

    void insert(int x)
    {
        for(auto &[w,y]:v[x%M])
            if(x==w)
            {
                y++;
                return;
            }
        v[x%M].push_back({x,1});
    }

    int find(int x)
    {
        return x;
    }

    void erase(int x)
    {
        for(auto &[w,y]:v[x%M])
            if(x==w)
            {
                y--;
                return;
            }
        assert(0);
    }

    int count(int x)
    {
        for(auto &[w,y]:v[x%M])
            if(x==w)
                return y;
        return 0;
        // assert(0);
    }
}s[11];

void ins(int x)
{
    for(int S=1;S<(1<<m);S++)
        s[bit[S]].insert(hs[x][S]);
}

void del(int x)
{
    for(int S=1;S<(1<<m);S++)
        s[bit[S]].erase(s[bit[S]].find(hs[x][S]));
}

int qry(int x)
{
    int ret=0;
    for(int S=1;S<(1<<m);S++)
        ret+=s[bit[S]].count(hs[x][S])*(bit[S]&1?1:-1);
    return ret;
}

bool cmpw(int a,int b)
{
    return ww[a]<ww[b];
}

signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<(1<<m);i++)
        bit[i]=bit[i>>1]+(i&1);
    for(int i=1;i<=n;i++)
    {
        r[i]=i;
        for(int j=1;j<=m;j++)
             scanf("%lld",&b[i][j]);
        // ww[i]=rand();
        scanf("%lld",&ww[i]);
    }
    sort(r+1,r+n+1,cmpw);
    int ext=1e9;
    for(int i=1;i<=n;i++)
    {
        w[i]=ww[r[i]];
        for(int j=1;j<=m;j++)
            a[i][j]=b[r[i]][j];
        sort(a[i]+1,a[i]+m+1);
        for(int j=2;j<=m;j++)
            if(a[i][j]==a[i][j-1])
                a[i][j]=++ext;
        sort(a[i]+1,a[i]+m+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int S=1;S<(1<<m);S++)
        {
            int x=__builtin_ctz(S&(-S));
            hs[i][S]=((__int128)hs[i][S^(S&-S)]*bs+a[i][x+1])%P;
        }
    }
    for(int i=1;i<=n;i++)
        ins(i);
    int ans=1e18;
    int i=1,j=n;
    while(i<=n&&qry(i)==j)
        i++;
    if(i>n)
    {
        puts("-1");
        return 0;
    }
    for(;i<=n;i++)
    {
        if(!j)
            break;
        int ok=qry(i)<j;
        if(!ok)
            continue;
        while(j>0&&qry(i)<j)
            del(j--);
        ans=min(ans,w[i]+w[j+1]);
    }
    printf("%lld\n",ans==1e18?-1:ans);
}