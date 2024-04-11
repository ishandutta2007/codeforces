#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
const int N=305;
int fa[N],vis[N],tp[N],T;
int mat[N],q[N],pre[N];
vector<int> e[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int LCA(int x,int y){
	++T;
	for (;;swap(x,y)) if (x)
		if (vis[x=get(x)]==T) return x;
		else vis[x]=T,x=pre[mat[x]];
}
void flower(int x,int y,int p){
	for (;get(x)!=p;){
		pre[x]=y; y=mat[x];
		if (tp[y]==2) tp[q[++*q]=y]=1;
		if (get(x)==x) fa[x]=p;
		if (get(y)==y) fa[y]=p;
		x=pre[y];
	}
}
bool work(int n,int S){
	For(i,1,n) pre[i]=tp[i]=0,fa[i]=i;
	q[0]=1; q[1]=S; tp[S]=1;
	For(h,1,*q){
		if (mat[S]) return 1;
		int x=q[h];
		for (auto i:e[x]){
			if (get(i)==get(x)||tp[i]==2) continue;
			if (!tp[i]){
				tp[i]=2; pre[i]=x;
				if (!mat[i]){
					for (int now=i,las,tmp;now;now=las){
						las=mat[tmp=pre[now]];
						mat[now]=tmp; mat[tmp]=now;
					}
					return 1;
				}
				tp[mat[i]]=1;
				q[++*q]=mat[i];
			}
			else if (tp[i]==1){
				int L=LCA(x,i);
				flower(x,i,L);
				flower(i,x,L);
			}
		}
	}
	return 0;
}
int solve(int n){
	int ans=0;
	For(i,1,n) mat[i]=0;
	For(i,1,n) if (!mat[i]&&work(n,i)) ans++;
	return ans;
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m;
		scanf("%d%d",&n,&m);
		For(i,1,2*n+m) e[i].resize(0);
		For(i,1,n){
			e[i].PB(i+n); e[i+n].PB(i);
			static char s[155];
			scanf("%s",s+1);
			For(j,1,m) if (s[j]=='1'){
				e[i].PB(j+n*2); e[j+n*2].PB(i);
				e[i+n].PB(j+n*2); e[j+n*2].PB(i+n);
			}
		}
		printf("%d\n",solve(2*n+m)-n);
	}
}