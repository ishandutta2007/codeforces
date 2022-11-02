#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define All(x) x.begin(),x.end()
using namespace std;
const int maxn=100;
vector<int> E[maxn];
void AddEdge(int s,int t)
{
    E[s].pb(t);
    E[t].pb(s);
}
int A[maxn],F[maxn],n;
void Init()
{
    cin>>n;
    rep(i,n)cin>>A[i],A[i]--;
    rep(i,n)cin>>F[i];
    rep(i,n)
    {
        if(i-F[i]>=0)AddEdge(i,i-F[i]);
        if(i+F[i]<n)AddEdge(i,i+F[i]);
    }
}
int own[maxn]={},flag=0;
void dfs(int x)
{
    own[x]=flag;
    rep(i,E[x].size())
    {
        int t=E[x][i];
        if(own[t]!=flag)
            dfs(t);
    }
}
void Solve()
{
    rep(i,n)if(own[i]==0)
    {
        ++flag;
        dfs(i);
    }
    rep(i,n)
    {
        if(own[i]!=own[A[i]])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    //freopen("in","r",stdin);
    Init();
    Solve();
}