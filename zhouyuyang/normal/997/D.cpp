#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking 
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2


#define INF (1ll<<60)
using namespace std;

const int mo=998244353;
const int N=4005;
const int M=40;
int n1,n2,k;
struct tree{
	vi e[N];
	int vson[N][M];
	int vfa[N][M];
	int f[M],v[M],fa[N];
	void dfs(int x){
		for (auto to:e[x]) if (to!=fa[x])
			fa[to]=x,dfs(to);
	}
	void dfs1(int x){
		for (auto to:e[x]) if (to!=fa[x]) dfs1(to);
		vson[x][0]=1;
		For(i,1,k) for (auto to:e[x]) if(to!=fa[x])
			For(j,0,i-1) UPD(vson[x][i],1ll*vson[x][j]*vson[to][i-j-1]%mo);
	}
	void dfs2(int x){
		for (auto to:e[x]) if (to!=fa[x]) vfa[to][0]=1;
		For(i,1,k){
			static int tmp[M]; CLR(tmp,0);
			For(j,0,i-1) UPD(tmp[j],vfa[x][j]);
			for (auto to:e[x]) if (to!=fa[x])
				For(j,0,i-1) UPD(tmp[j],vson[to][j]);
			for (auto to:e[x]) if (to!=fa[x])
				For(j,0,i-1) UPD(vfa[to][i],1ll*(tmp[j]+mo-vson[to][j])*vfa[to][i-j-1]%mo);
		}
		for (auto to:e[x]) if (to!=fa[x]) dfs2(to);
	}
	void init(int n){
		For(i,1,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].PB(y); e[y].PB(x);
		}
		dfs(1); dfs1(1); dfs2(1);
		For(id,1,n){
			CLR(f,0); f[0]=1;
			For(i,1,k){
				For(j,0,i-1) UPD(f[i],1ll*f[j]*vfa[id][i-j-1]%mo);
				for (auto to:e[id]) if (to!=fa[id])
					For(j,0,i-1) UPD(f[i],1ll*f[j]*vson[to][i-j-1]%mo);
			}
			For(i,0,k)
				UPD(v[i],f[i]);
		}
	}
}T1,T2;
int c[80][80],ans;
int main(){
	For(i,0,75) c[i][0]=1;
	For(i,1,75) For(j,1,i) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	scanf("%d%d%d",&n1,&n2,&k);
	if (k&1) return puts("0"),0;
	k/=2; T1.init(n1); T2.init(n2);
	For(i,0,k) UPD(ans,1ll*T1.v[i]*T2.v[k-i]%mo*c[k*2][i*2]%mo);
	printf("%d\n",ans);
}