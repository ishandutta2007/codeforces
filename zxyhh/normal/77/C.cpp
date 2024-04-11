/*
	>Author: zxy_hhhh
	>blog: zxy-hhhh.cn
	>date: 2019/02/20
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<ctime>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
using namespace std;
inline ll rd() {
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=-1;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f*_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 100005
int nx[maxn<<1],to[maxn<<1],hd[maxn],cnt;
inline void add(int u,int v) {nx[++cnt]=hd[u],to[cnt]=v,hd[u]=cnt;}
int a[maxn],n;
ll f[maxn];
ll son[maxn];
int tot;
void dfs(int u,int fa) {
	cross(i,u) if (to[i]!=fa&&a[to[i]]) 
		a[to[i]]--,dfs(to[i],u);
	tot=0;
	cross(i,u) if (to[i]!=fa) son[++tot]=f[to[i]];
	sort(son+1,son+1+tot);
	drp(i,tot,1) if (a[u]) f[u]+=son[i]+2,a[u]--;
	cross(i,u) if (to[i]!=fa)
		f[u]+=2*min(a[u],a[to[i]]),a[u]-=min(a[u],a[to[i]]);
}
int main() { 
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	n=rd();
	rep(i,1,n) a[i]=rd();
	rep(i,1,n-1) {
		int x=rd(),y=rd();
		add(x,y),add(y,x);
	}
	int root=rd();
	dfs(root,0);
	wrt(f[root],'\n'); 
}