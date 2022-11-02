#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <cstring>
#include <time.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define Debug(x) cout<<#x<<"="<<x<<endl;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define tr(e,x) for(vector<int>::iterator e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int inf=~0U>>1,maxn=10000;
using namespace std;
typedef pair<int,int> pi;
vector<int> E[maxn];
map<pi,int> Map;
vector<pi> Es;
set<pi> InTree;
int mnt=0,n,m;
struct TA
{
    vector<int> A;
    int s;
    void Add(int l,int d)
    {
        l-=s;
        for(l++;l<=A.size();l+=l&-l)
            A[l-1]+=d;
    }
    void Add(int l,int r,int d)
    {
        Add(l,d);Add(r+1,-d);
    }
    int Sum(int l)
    {
        l-=s;int ret=0;
        for(l++;l;l-=l&-l)ret+=A[l-1];
        return ret;
    }
    void Build(int l,int r)
    {
        s=l;int n=r-l+1;A=vector<int>(n);
    }
}T[2][maxn];
void AddEdge(int s,int t)
{
    E[s].pb(t);E[t].pb(s);
    Map[pi(s,t)]=Map[pi(t,s)]=mnt++;
    Es.pb(pi(s,t));
}
int D[maxn],F[maxn];
bool c[maxn];
int Q[maxn],h,t,Size[maxn],own[maxn];
bool Vis[maxn]={};
void BFS(int vs)
{
    h=t=0;
    for(F[vs]=-1,Vis[vs]=true,Q[t++]=vs,D[vs]=0;h<t;h++)
    {
        int x=Q[h];c[x]=D[x]%2;
        tr(e,E[x])if(!Vis[*e])
        {
            Q[t++]=*e;F[*e]=x;
            D[*e]=D[x]+1;Vis[*e]=true;
            InTree.insert(pi(x,*e));
            InTree.insert(pi(*e,x));
        }
    }
    for(int i=h-1;i>=0;i--)
    {
        int x=Q[i];Size[x]=1;
        tr(e,E[x])if(F[*e]==x)Size[x]+=Size[*e];
    }
    for(int i=0;i<h;i++)
    {
        int a=Q[i];if(own[a]>=0)continue;
        int x=a,next;
        for(;;x=next)
        {
            next=-1;own[x]=a;
            tr(e,E[x])if(F[*e]==x)
                if(next==-1||Size[*e]>Size[next])
                    next=*e;
            if(next==-1)break;
        }
        rep(j,2)T[j][a].Build(D[a],D[x]);
    }
}
void MarkThePath(int u,int v,int t)
{
    for(;;)
    {
        if(D[u]<D[v])swap(u,v);
        if(own[u]==own[v])
        {
            T[t][own[u]].Add(D[v]+1,D[u],1);
            return;
        }
        if(D[own[u]]<D[own[v]])swap(u,v);
        T[t][own[u]].Add(D[own[u]],D[u],1);
        u=F[own[u]];
    }
}
int GetTheValue(int u,int v,int t)
{
    if(D[u]<D[v])swap(u,v);
    return T[t][own[u]].Sum(D[u]);
}
bool IsTreeEdge(int u,int v)
{
    if(D[u]<D[v])swap(u,v);
    return D[u]==D[v]+1;
}
void init()
{
    scanf("%d%d",&n,&m);int s,t;
    rep(i,m)
    {
        scanf("%d%d",&s,&t);--s;--t;
        AddEdge(s,t);
    }
}
vector<pi> Ans;
void Solve()
{
    //Built It
    memset(own,-1,sizeof own);
    rep(i,n)if(!Vis[i])BFS(i);
    vector<pi> TreeEdge,NotErrorEdge,ErrorEdge;
    //For All Tree Not On Tree
    rep(i,Es.size())
    {
        pi e=Es[i];
        if(InTree.find(e)!=InTree.end())
        {
            TreeEdge.pb(e);
        }
        else
        {
            if(c[e.first]==c[e.second])
                ErrorEdge.pb(e);
            else
                NotErrorEdge.pb(e);
        }
    }
    if(ErrorEdge.size()==0)
        Ans=NotErrorEdge;
    if(ErrorEdge.size()==1)
        Ans=ErrorEdge;
    //Mark The Path For ErorrEdge
    rep(i,ErrorEdge.size())
    {
        pi e=ErrorEdge[i];
        MarkThePath(e.first,e.second,0);
    }
    //Mark The Path For NotErorrEdge
    rep(i,NotErrorEdge.size())
    {
        pi e=NotErrorEdge[i];
        MarkThePath(e.first,e.second,1);
    }
    // For All Tree Edge
    int a[2];
    rep(i,TreeEdge.size())
    {
        pi e=TreeEdge[i];
        rep(j,2)a[j]=GetTheValue(e.first,e.second,j);
        if(a[0]<ErrorEdge.size()||(a[0]&&a[1]))continue;
        Ans.pb(e);
    }
    vector<int> Print;
    rep(i,Ans.size())Print.pb(Map[Ans[i]]+1);
    sort(Print.begin(),Print.end());
    cout<<Print.size()<<endl;
    rep(i,Print.size())cout<<Print[i]<<" ";cout<<endl;
}
int main()
{
    //freopen("in","r",stdin);
    init();
    Solve();
}