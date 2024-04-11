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
#include <sstream>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define Debug(x) cout<<#x<<"="<<x<<endl;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define tr(e,x) for(set<int>::iterator e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int inf=~0U>>1,maxn=1000;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
set<int> E[maxn];
void InsEdge(int s,int t)
{
    E[s].insert(t);E[t].insert(s);
}
void DelEdge(int s,int t)
{
    E[s].erase(E[s].find(t));
    E[t].erase(E[t].find(s));
}
int n;
int u,v;
int own[maxn],now;
bool dfs(int x,int f)
{
    own[x]=now;
    tr(e,E[x])if(*e!=f)
        if(own[*e]==now)u=x,v=*e;
        else dfs(*e,x);
}
vector<string> Print;
bool doit()
{
    memset(own,-1,sizeof own);
    now=0;u=v=-1;
    rep(i,n)if(own[i]==-1)
    {
        now++;
        dfs(i,-1);
    }
    if(u==-1)return false;
    ostringstream out;
    out<<u+1<<" "<<v+1<<" ";
    DelEdge(u,v);
    rep(i,n)if(own[u]!=own[i]){v=i;break;}
    out<<u+1<<" "<<v+1;
    InsEdge(u,v);
    Print.pb(out.str());
    return true;
}
int main()
{
    //freopen("in","r",stdin);
    int s,t;
    cin>>n;
    rep(i,n-1)cin>>s>>t,--s,--t,E[s].insert(t),E[t].insert(s);
    while(doit());
    cout<<Print.size()<<endl;
    rep(i,Print.size())cout<<Print[i]<<endl;
}