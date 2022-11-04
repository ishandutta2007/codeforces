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
const int N=300005;
int n,m;
vector<int> e[N],E[N];
int deg[N],q[N];
void topo(){
	For(i,1,n) deg[i]=0; *q=0;
	For(i,1,n) for (auto j:e[i]) deg[j]++;
	For(i,1,n) if (!deg[i]) q[++*q]=i;
	For(h,1,n) for (auto i:e[q[h]])
		if (!(--deg[i])) q[++*q]=i;
}
int cnt[N],id[N],vis[N];
void solve(int *q,vector<int> *e){
	For(i,1,n) deg[i]=0;
	int S=0,y=0;
	For(i,1,n){
		int x=q[i];
		for (auto j:e[x]){
			if (deg[j]==0){
				S--; y^=j;
				id[j]=x; cnt[x]++;
			}
			else if (deg[j]==1){
				cnt[id[j]]--;
				id[j]=-1;
			}
			deg[j]++;
		}
		if (S==1&&!cnt[y]) vis[x]++;
		else if (S) vis[x]+=2;
		S++; y^=x;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); E[y].PB(x);
	}
	topo();
	solve(q,E);
	reverse(q+1,q+n+1);
	solve(q,e);
	int ans=0;
	For(i,1,n) ans+=(vis[i]<=1);
	printf("%d\n",ans);
}