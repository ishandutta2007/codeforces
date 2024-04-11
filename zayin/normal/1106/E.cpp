#include<bits/stdc++.h>
#define maxn 100050
#define maxm 205
using namespace std;
typedef long long LL;

int n,m,q;
int s[maxn],t[maxn],w[maxn],d[maxn];

struct I
{
    int id,f;
    I(int _id=0,int _f=0)  {
        id=_id,f=_f;
    }
} ;
vector<I> Q[maxn];

struct cmp  {
    bool operator () (const int& i,const int& j) {
        return w[i]>w[j]||(w[i]==w[j]&&d[i]>d[j])||(w[i]==w[j]&&d[i]==d[j]&&i<j);
    }
};

set<int,cmp>    que;

void init()
{
    scanf("%d%d%d",&n,&m,&q);
    for (int i=0;i<q;++i)
    {
        scanf("%d%d%d%d",s+i,t+i,d+i,w+i);
        --s[i],++d[i];
        Q[s[i]].push_back(I(i,0));
        Q[t[i]].push_back(I(i,1));
    }
}

LL dp[maxn][maxm];

void solve()
{
    for (int i=n;~i;--i)
    {
        for (auto I:Q[i])
            if (I.f)
                que.insert(I.id);
            else
                que.erase(I.id);
        
        int k=que.size()?*que.begin():-1;
        for (int j=0;j<=m;++j)
        {
            if (~k)
            {
                dp[i][j]=dp[d[k]][j]+w[k];
                if (j)
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            } else dp[i][j]=dp[i+1][j];
        }

        // cout<<i<<"("<<k<<"):";
        // for (int j=0;j<=m;++j)
        //     cout<<dp[i][j]<<" ";
        // cout<<endl;
    }
    printf("%lld\n",dp[0][m]);
}

int main()
{
    init();
    solve();
    return 0;
}