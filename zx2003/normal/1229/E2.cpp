#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
//typedef __uint128_t LL;
typedef unsigned long long ll;
struct LL{
	ll lo,hi;
	LL(int _x=0):lo(_x),hi(0){}
	bool operator<(const LL&rhs)const{return hi==rhs.hi?lo<rhs.lo:hi<rhs.hi;}
	inline void set(int i){i<64?lo|=1ull<<i:hi|=1ull<<i-64;}
	inline bool tst(int i){return i<64?lo>>i&1:hi>>i-64&1;}
	inline bool operator!=(const LL&rhs)const{return lo!=rhs.lo || hi!=rhs.hi;}
};
const int N=7e4+5,S=128,mo=1e9+7,iv=570000004;
 
struct hmp{
	static const int mo=100003;
	LL key[N];int val[N],nxt[N],h[mo],xb;
	int&operator[](const LL&x){
		int z=(x.hi%mo*11949+x.lo%mo)%mo,i=h[z];
		for(;i && key[i]!=x;i=nxt[i]);if(i)return val[i];
		key[++xb]=x;nxt[xb]=h[z];h[z]=xb;return val[xb];
	}
}hs;int tot;
int adj[N][S],st[S];
int n,vis[N];
int f[9][9];
int g[128][9];
int op[9][N];
int br[S],mx[N],ans;
 
int finder(LL u) {
	if (!hs[u]) return hs[u]=++tot;
	else return hs[u];
}
int dfs(int id,LL cur) {
	vis[id]=true;
	for (int j=0;j<(1<<n);j++)
	if (cur.tst(j)) mx[id]=max(mx[id],br[j]);
	for (int s=0;s<(1<<n);s++) {
		LL ncur=cur;
		for (int i=0;i<n;i++)
		if ((s>>i)&1) {
			for (int j=0;j<(1<<n);j++)
			if (cur.tst(j)) ncur.set(j|(1<<i));
		}
		int nid=finder(ncur);
		if (!vis[nid]) dfs(nid,ncur);
		adj[id][s]=nid;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<(1<<n);i++)
		br[i]=br[i>>1]+(i&1);
	hs[1]=++tot;dfs(1,1);
cerr<<tot<<' '<<clock()<<endl;
	for (int j=1;j<=n;j++)
	for (int k=0;k<(1<<n);k++)
		g[k][j]=1;
	for (int i=0;i<n;i++)
	for (int j=1;j<=n;j++) {
		scanf("%d",&f[i][j]);
		f[i][j]=1ll*iv*f[i][j]%mo;
		for (int k=0;k<(1<<n);k++)
		if ((k>>i)&1) g[k][j]=1ll*g[k][j]*f[i][j]%mo;
		else g[k][j]=g[k][j]*(1ll+mo-f[i][j])%mo;
	}
	op[1][1]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=tot;j++)
	for (int k=0;k<(1<<n);k++)
		op[i+1][adj[j][k]]=(op[i+1][adj[j][k]]+1ll*op[i][j]*g[k][i])%mo;
	for(int j=1;j<=tot;++j)if(mx[j]==n)ans=(ans+op[n+1][j])%mo;
	printf("%d\n",ans);
	return 0;
}