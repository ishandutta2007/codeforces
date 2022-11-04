#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db long double
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
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define inf (1<<29) 
using namespace std;
const int N=505;
int n,K,ans=inf,pos;
int tot,head[N];
int f[N][N];
bool vis[N];
vector<pii> fr[N][N];
struct edge{
	int to,next;
}e[N*2];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	f[x][1]=0;
	For(i,2,K) f[x][i]=inf;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			Rep(j,K,1){
				if (f[x][j]!=inf) f[x][j]++;
				For(k,1,j-1)
					if (f[x][j-k]+f[e[i].to][k]<f[x][j]){
						f[x][j]=f[x][j-k]+f[e[i].to][k];
						fr[x][j].clear();
						For(t,0,fr[x][j-k].size()-1)
							fr[x][j].PB(fr[x][j-k][t]);
						fr[x][j].PB(pii(e[i].to,k));
					}
			}
		}
	if (f[x][K]+(x!=1)<ans)
		ans=f[x][K]+(x!=1),pos=x;
}
void output(int x,int k){
	vis[x]=1;
	For(i,0,fr[x][k].size()-1)
		output(fr[x][k][i].fi,fr[x][k][i].se);
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]) printf("%d ",(i+1)/2);
}
int main(){
	scanf("%d%d",&n,&K);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	printf("%d\n",ans);
	output(pos,K);
}