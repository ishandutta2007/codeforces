#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MOD 1000000007
#define MX 1000005
#define BT 20

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

vector <P> vec[SIZE];//1 : illegal
int par[SIZE][BT],dep[SIZE];
int down[SIZE],up[SIZE];
int cnt[MX];
int n,k;

void dfs(int v=0,int p=-1,int d=0)
{
    dep[v]=d;
    par[v][0]=p;
    for(int i=0;i<vec[v].size();i++)
    {
        int to=vec[v][i].first;
        if(to!=p)
        {
            dfs(to,v,d+1);
        }
    }
}
void build()
{
    for(int i=0;i+1<BT;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(par[j][i]==-1) par[j][i+1]=-1;
            else par[j][i+1]=par[par[j][i]][i];
        }
    }
}
int LCA(int a,int b)
{
    if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
    for(int i=BT-1;i>=0;i--)
    {
        if(par[b][i]!=-1&&dep[par[b][i]]>=dep[a])
        {
            b=par[b][i];
        }
    }
    if(a==b) return a;
    for(int i=BT-1;i>=0;i--)
    {
        if(par[a][i]!=par[b][i])
        {
            a=par[a][i];
            b=par[b][i];
        }
    }
    return par[a][0];
}
void make(int v=0,int p=-1)
{
    bool u=false;
    for(int i=0;i<vec[v].size();i++)
    {
        int to=vec[v][i].first;
        if(to!=p)
        {
            make(to,v);
            up[v]+=up[to];
            down[v]+=down[to];
            if(vec[v][i].second==1) cnt[down[to]]++;
        }
        else if(vec[v][i].second==1) u=true;
    }
    if(u) cnt[up[v]]++;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);a--;b--;
        vec[a].push_back(P(b,0));
        vec[b].push_back(P(a,c));
    }
    dfs();
    build();
    int now=0;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int nxt;
        scanf("%d",&nxt);nxt--;
        int p=LCA(now,nxt);
        //now->p
        up[now]++;
        up[p]--;
        //p->nxt
        down[nxt]++;
        down[p]--;
        //printf("%d %d %d\n",now,nxt,p);
        now=nxt;
    }
    make();
    ll t=1;
    ll ret=0;
    for(int i=0;i<k;i++)
    {
        ret+=(ll) (t-1)*(ll) cnt[i]%MOD;
        if(ret>=MOD) ret-=MOD;
        t*=2;
        t%=MOD;
    }
    printf("%d\n",(int) ret);
    return 0;
}