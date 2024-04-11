#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T,n;

int l[1001][1001];

int p[N];

int lcm(int x,int y)
{
    return x*y/__gcd(x,y);
}

int qry(int x,int y)
{
    printf("? %lld %lld\n",x,y);
    fflush(stdout);
    // int ret=lcm(p[x],p[y]);
    int ret;
    scanf("%lld",&ret);
    return ret;
}

multiset<int>s;

int ans[N];

void out()
{
    printf("! ");
    for(int i=1;i<=n;i++)
        printf("%lld%c",ans[i]," \n"[i==n]);
    fflush(stdout);
}

int vis[N],pr[N],ptot;

void pre(int n)
{
    vis[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
            pr[++ptot]=i;
        for(int j=1;j<=ptot&&i*pr[j]<=n;j++)
        {
            vis[i*pr[j]]=1;
            if(i%pr[j]==0)
                break;
        }
    }
}

int b[N];

map<int,int>cnt;

set<int>id[N];

signed main()
{
    pre(2e5);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        // for(int i=1;i<=n;i++)
        //     p[i]=i+10000;// scanf("%lld",&p[i]);
        // random_shuffle(p+1,p+n+1);
        if(n<=100)
        {
            int mx=0;
            int p=-1,q=-1;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                {
                    l[i][j]=qry(i,j);
                    l[j][i]=l[i][j];
                    if(l[i][j]>mx)
                        mx=l[i][j],p=i,q=j;
                }
            //R * (R - 1) = mx
            //R ^ 2 - R - mx = 0
            int R=-1;
            for(int i=1;i<=200000;i++)
                if(i*(i-1)==mx)
                {
                    R=i;
                    break;
                }
            assert(R!=-1);
            int L=R-n+1;
            fill(ans+1,ans+n+1,-1);
            for(int i=L;i<=R;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(ans[j]!=-1)
                        continue;
                    s.clear();
                    for(int t=L;t<=R;t++)
                        if(i!=t)
                            s.insert(lcm(i,t));
                    int ok=1;
                    for(int k=1;k<=n;k++)
                        if(j!=k)
                        {
                            if(!s.count(l[j][k]))
                            {
                                ok=0;
                                break;
                            }
                            s.erase(s.find(l[j][k]));
                        }
                    if(!ok)
                        continue;
                    ans[j]=i;
                    break;
                }
            }
            out();
        }
        else
        {
            fill(ans+1,ans+n+1,0);
            int mx=0,pos=-1;
            for(int i=1;i<=100;i++)
            {
                int x=rand()%n+1;
                int g=0;
                for(int j=1;j<=50;j++)
                {
                    int y=rand()%n+1;
                    while(x==y)
                        y=rand()%n+1;
                    g=__gcd(g,qry(x,y));
                }
                ans[x]=g;
                if(!vis[g]&&g>mx)
                    mx=g,pos=x;
            }
            for(int i=1;i<=n;i++)
                if(i!=pos)
                    ans[i]=qry(i,pos)/mx;
            out();
        }
    }
}