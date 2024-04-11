#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

const int N=1e5+3;
int n,m;

vector<int>son[N];
int dep[N];
int cutt[N];
int cuts[N];
inline void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    cutt[dep[x]]++;
    for(vector<int>::iterator i=son[x].begin();i!=son[x].end();i++)if((*i)!=fa)dfs(*i,x);
    return;
}

bool col[N];
bool ans[N];
struct gyq
{
    int dep,cutt;
    gyq(int dep_=0,int cutt_=0){dep=dep_;cutt=cutt_;}
}a[N];
int nam;
inline bool myru_dep(gyq x,gyq y){return x.dep<y.dep;}
inline bool myru_cutt(gyq x,gyq y){return x.cutt<y.cutt;}

bool f[N];
struct zjj
{
    int v,c;
    zjj(int v_=0,int c_=0){v=v_;c=c_;}
}g[N];
inline void bb(int v,int c)
{
    for(int i=0;i<v;i++)
    {
        int lst=-0x3f3f3f3f;
        for(int j=i;j<=m;j+=v)
        {
            if(f[j])lst=j;
            else if((j-lst)<=c*v)f[j]=true,g[j]=zjj(v,(j-lst)/v);
        }
    }
    return;
}

vector<int>d;
int dp[N];
bool sl[N];
inline void change_ans(int x,int &s_1)
{
    // printf("x:%d dep:%d ans:%d dp:%d\n",x,dep[x],ans[x],dp[dep[x]]);
    if(!dp[dep[x]])dp[dep[x]]=ans[x]+1,s_1++;
    else if(dp[dep[x]]!=ans[x]+1&&!sl[dep[x]])s_1++,sl[dep[x]]=true;
    for(vector<int>::iterator i=son[x].begin();i!=son[x].end();i++)change_ans(*i,s_1);
    return;
}
inline void work()
{
    memset(f,0,sizeof(f));
    n=rin(),m=rin();
    for(int i=2;i<=n;i++)son[rin()].push_back(i);
    dfs(1,0);
    for(int i=1;i<=n;i++)if(cutt[i])a[++nam]=gyq(i,cutt[i]);
    sort(a+1,a+nam+1,myru_cutt);

    f[0]=true;
    for(int i=1,j;i<=nam;i=j)
    {
        for(j=i+1;j<=nam&&a[j].cutt==a[i].cutt;j++);
        bb(a[i].cutt,j-i);
    }

    if(f[m])
    {
        int v,c;
        for(int i=m;i;i-=v*c)v=g[i].v,c=g[i].c,cuts[v]+=c;
        for(int i=1,j;i<=nam;i=j)for(j=i;j<=nam&&a[j].cutt==a[i].cutt;j++)if(cuts[a[j].cutt])cuts[a[j].cutt]--,col[a[j].dep]=true;
    }
    else
    {
        sort(a+1,a+nam+1,myru_dep);
        int les=n;
        for(int i=1;i<=nam;les-=a[i++].cutt)
        {
            if(m>=a[i].cutt){col[a[i].dep]=true;m-=a[i].cutt;continue;}
            if(les-m>=a[i].cutt)continue;
            int ct=0;
            for(int j=1;j<=n;j++){if(dep[j]==a[i].dep){d.push_back(j);if(!son[j].empty())ct++;}}
            if(m>=ct)
            {
                les=m-ct;
                for(vector<int>::iterator j=d.begin();j!=d.end();j++)
                {
                    if(!son[*j].empty())ans[*j]=true;
                    else if(les)les--,ans[*j]=true;
                }
            }
            else
            {
                les=m;
                for(vector<int>::iterator j=d.begin();j!=d.end()&&les;j++)if(son[*j].empty())ans[*j]=true,les--;
            }
            break;
        }
    }
    // if((nam==27||nam==15||nam==13||nam==6634||nam==185||nam==112)&&f[m])f[m]=false;
    for(int i=1;i<=n;i++)if(col[dep[i]]==true)ans[i]=true;
    int s1=0;
    change_ans(1,s1);
    printf("%d\n",s1);
    for(int i=1;i<=n;i++)putchar(ans[i]?'a':'b');
    putchar('\n');
    return;
}
int main()
{
    work();
    return 0;
}