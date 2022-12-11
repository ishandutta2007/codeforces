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
#define maxn 1005
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
int n,m,s,t;
int diss[maxn],dist[maxn];
bool vis[maxn];
int G[maxn][maxn];
int g[maxn][maxn];
inline void bfs(int t,int *dis)
{
    queue<int> q;q.push(t);	
	memset(vis,0,sizeof(vis));vis[t]=1;
	while(!q.empty()){
		int tmp=q.front();q.pop();
		rep(i,1,G[tmp][0]) {
			if (!vis[G[tmp][i]]) {
				vis[G[tmp][i]]=1;dis[G[tmp][i]]=dis[tmp]+1;
				q.push(G[tmp][i]);
			}
		} 
	}
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
    n=rd(),m=rd(),s=rd(),t=rd();
    rep(i,1,m){
    	int x=rd(),y=rd();
    	G[x][++G[x][0]]=y;G[y][++G[y][0]]=x;
    	g[x][y]=g[y][x]=1;
	}
    bfs(s,diss);bfs(t,dist);
    int sum=0;
    rep(x,1,n)
    rep(y,x+1,n)
    if ((!g[x][y]))
	if (min(diss[x]+dist[y]+1,dist[x]+diss[y]+1)>=diss[t]) sum++;
	wrt(sum,'\n');
	flush();return 0;
}