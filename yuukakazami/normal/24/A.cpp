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
#define tr(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int inf=~0U>>1,maxn=100;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int Dist[maxn][maxn],n,ans=inf;
bool Vis[maxn];
void Dfs(int x,int gone,int cost)
{
    Vis[x]=true;
    if(gone==n)
    {
        if(Dist[x][0]!=-1)
        {
            cost+=Dist[x][0];
            ans=min(ans,cost);
        }
    goto End;}
    rep(i,n)if(Dist[x][i]!=-1&&!Vis[i])
    {
        Dfs(i,gone+1,cost+Dist[x][i]);
    }
    End:
    Vis[x]=false;
}
int main()
{
    //freopen("in","r",stdin);
    memset(Dist,-1,sizeof Dist);
    cin>>n;int s,t,c;
    rep(i,n)
    {
        cin>>s>>t>>c;--s;--t;
        Dist[s][t]=0;Dist[t][s]=c;
    }
    Dfs(0,1,0);
    cout<<ans<<endl;
}