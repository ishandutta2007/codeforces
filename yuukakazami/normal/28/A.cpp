#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define All(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> pnt;
#define x first
#define y second
const int maxn=500+10;
int dist(pnt a,pnt b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
pnt A[maxn];
int S[maxn],n,m;
bool E[maxn][maxn]={};
int Link[maxn];
bool Vis[maxn];
bool dfs(int x)
{
    if(Vis[x])return false;
    Vis[x]=true;
    rep(i,m)if(E[x][i])
    {
        if(Link[i]==-1||dfs(Link[i]))
            return Link[i]=x,true;
    }
    return false;
}
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m;
    rep(i,n)cin>>A[i].x>>A[i].y;
    rep(i,m)cin>>S[i];
    rep(i,n)
    {
        int pre=i?i-1:n-1,nxt=i+1==n?0:i+1;
        int d=dist(A[pre],A[nxt]);
        if(dist(A[pre],A[i])+dist(A[i],A[nxt])==d)
            rep(j,m)if(S[j]==d)
                E[i][j]=true;
    }
    rep(c,2)
    {
        bool ok=true;
        memset(Link,-1,sizeof Link);
        rep(i,n)if(i%2==c)
        {
            memset(Vis,0,sizeof Vis);
            if(!dfs(i)){ok=false;break;}
        }
        int Ans[maxn]={};
        if(ok)
        {
            cout<<"YES"<<endl;
            rep(i,m)
                Ans[Link[i]]=i+1;
            rep(i,n)
                if(Ans[i])cout<<Ans[i]<<" ";
                else cout<<-1<<" ";
            return 0;
        }
    }
    cout<<"NO"<<endl;
}