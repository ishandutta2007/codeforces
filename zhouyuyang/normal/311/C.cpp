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
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

const int N=100005;
ll d[N],a[N];
int n,LCA,k,c[N];
int q[N*10],vis[N];
priority_queue<pii > Q;
int main(){
	scanf("%*d%d%d%d",&n,&LCA,&k);
	d[0]=0; For(i,1,k-1) d[i]=INF;
	For(i,1,n){
		scanf("%lld%d",&a[i],&c[i]);
		if ((--a[i])%k==0) Q.push(pii(c[i],-i));
	}
	while (LCA--){
		int tp; scanf("%d",&tp);
		if (tp==1){
			ll w; scanf("%lld",&w);
			int h=0,t=0;
			For(i,0,k-1) if (d[i]!=INF)
				q[++t]=i,vis[i]=1;
			while (h!=t){
				int x=q[++h]; vis[x]=0;
				ll nxt=d[x]+w; int to=nxt%k;
				if (nxt<d[to]){
					d[to]=nxt;
					if (!vis[to]){
						q[++t]=to;
						vis[to]=1;
					}
				}
			}
			while (!Q.empty()) Q.pop();
			For(i,1,n) if (a[i]>=d[a[i]%k]&&c[i])
				Q.push(pii(c[i],-i));
		}
		if (tp==2){
			int x,y;
			scanf("%d%d",&x,&y);
			c[x]-=y;
			if (a[x]>=d[a[x]%k])
				Q.push(pii(c[x],-x));
		}
		if (tp==3){
			while (!Q.empty()&&c[-Q.top().se]!=Q.top().fi) Q.pop();
			if (Q.empty()) puts("0");
			else{
				printf("%d\n",Q.top().fi);
				c[-Q.top().se]=0;
				Q.pop();
			}
		}
	}
}