#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define CROSS(x,a) for (int x=HD[a];x;x=NX[x])
#define PC Putchar
#define GC Getchar
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define maxn 300005
using namespace std;
namespace FAST_IO {
    #define IN_LEN 500000
    #define OUT_LEN 500000
    inline char Getchar() {
        static char buf[IN_LEN], *l=buf,*r=buf;
        if (l==r) r=(l=buf)+fread(buf,1,IN_LEN,stdin);
        return (l==r)?EOF:*l++;
    }
    char obuf[OUT_LEN], *ooh = obuf;
    inline void Putchar(char c) {
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout),ooh = obuf;
	    *ooh++ = c;
    }
    inline ll rd(){
	    ll x=0;int ch=Getchar(); bool f=1;
	    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=GC();
	    if (ch=='-'){f=0;ch=GC();}
	    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=GC();}
	    return f?x:-x;
    }
    void write(ll x){ if (x>=10) write(x/10),PC((char)(x%10+'0')); else PC((char)(x+'0')); }
    inline void wrt(ll x,int p){if (x<0) PC('-'),x=-x; write(x); if (p) PC((char)p);}
    inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
}
using namespace FAST_IO;
int n,m;
int a[maxn];
int to[maxn],nx[maxn],hd[maxn],cnt;
inline void add(int u,int v){to[++cnt]=v,nx[cnt]=hd[u],hd[u]=cnt;}
int TO[maxn],NX[maxn],HD[maxn],CNT;
inline void ADD(int u,int v){TO[++CNT]=v,NX[CNT]=HD[u],HD[u]=CNT;}
int ind[maxn];
int dp[maxn][27];
int Max=1;
inline void Topsort()
{
	queue<int> q;
	rep(i,1,n) if (ind[i]==0) q.push(i),dp[i][a[i]]=1;
	while (!q.empty()){
		int tmp=q.front();
		q.pop();
		CROSS(i,tmp)
		rep(j,1,26){
		dp[tmp][j]=max(a[tmp]==j?dp[TO[i]][j]+1:dp[TO[i]][j],dp[tmp][j]);
		if (dp[tmp][j]>Max) Max=dp[tmp][j];
		}
		cross(i,tmp)
		{ind[to[i]]--;if (ind[to[i]]==0) q.push(to[i]);}
	}
}
int col[maxn],dfn[maxn],low[maxn],q[maxn],top,dn;
bool vis[maxn];
void tarjan(int k)
{
	dfn[k]=low[k]=++dn;
	q[++top]=k;vis[k]=1;
	cross(i,k)
	if (!dfn[to[i]]) tarjan(to[i]),low[k]=min(low[to[i]],low[k]);
	else if (vis[to[i]]) low[k]=min(dfn[to[i]],low[k]);
	if (low[k]==dfn[k]&&q[top]!=k) {wrt(-1,'\n'),flush();exit(0);}
	if (low[k]==dfn[k]) top--,vis[k]=0;
}
int main()
{
	//freopen("data.txt","r",stdin);
	//freopen("data.out","w",stdout);
	n=rd(),m=rd();
	int ch=GC();
	while (!(ch>='a'&&ch<='z')) ch=GC();
	rep(i,1,n) a[i]=ch-'a'+1,ch=GC();
	rep(i,1,m){
		int x=rd(),y=rd();
		if (x==y) {wrt(-1,'\n'),flush();exit(0);}
		add(x,y),ADD(y,x);
		ind[y]++;
	}
	rep(i,1,n) if (!dfn[i])tarjan(i);
	Topsort();
	wrt(Max,'\n');
	flush();return 0;
}