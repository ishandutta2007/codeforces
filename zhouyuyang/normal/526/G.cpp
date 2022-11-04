#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot;
int deg[N];
int n,q;
ll *aim[N];
bool cmp(ll *a,ll *b){
	return *a>*b;
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}

struct Tree{
	int S,fa[N][20],v[N][20],cnt;
	ll d[N],mxd[N],fav[N],dep2[N];
	ll mn[N],dis[N],sumans[N];
	int vis[N];
	void getfa(int x,int f){
		fa[x][0]=f; mxd[x]=d[x];
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=f){
				fav[e[i].to]=e[i].v;
				getfa(e[i].to,x);
				mxd[x]=max(mxd[x],mxd[e[i].to]);
			}
		mxd[0]=max(mxd[0],mxd[x]); 
	}
	void build(){
		getfa(S,0); cnt=0; mn[0]=(1ll<<60);
		for (int i=1;i<=n;i++)
			if (deg[i]==1&&i!=S)
				aim[++cnt]=d+i;
		sort(aim+1,aim+cnt+1,cmp);
		for (int i=1;i<=cnt;i++){
			int x=aim[i]-d,y=x;
			for (;!vis[x]&&x;x=fa[x][0])
				dis[y]+=fav[x],vis[x]=1;
			aim[i]=dis+y;
		}
		sort(aim+1,aim+cnt+1,cmp);
		for (int i=1;i<=cnt;i++){
			sumans[i]=sumans[i-1]+(*aim[i]);
			int x=aim[i]-dis,y=x;
			for (;vis[x]!=2&&x;x=fa[x][0])
				v[x][0]=i,vis[x]=2;
			mn[i]=*aim[i];
		}
		for (int i=1;i<=18;i++)
			for (int j=1;j<=n;j++){
				fa[j][i]=fa[fa[j][i-1]][i-1];
				v[j][i]=min(v[j][i-1],v[fa[j][i-1]][i-1]);
			}
	}
	ll ask(int x,int y){
		y=2*y-1;
		if (y>=cnt) return sumans[cnt];
		ll ans=sumans[y];
		if (v[x][0]>y){
			int tmp=x;
			for (int k=18;k>=0;k--)
				if (v[tmp][k]>y) tmp=fa[tmp][k];
			ans+=mxd[x]-d[tmp];
			ans-=min(mn[y],mxd[tmp]-d[tmp]);
		}
		return ans;
	}
}A,B;

void getdep(int x,int f,ll d,ll *dep){
	dep[x]=d;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=f)
			getdep(e[i].to,x,d+e[i].v,dep);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
		deg[x]++; deg[y]++;
	}
	getdep(1,0,0,A.d);
	A.S=max_element(A.d+1,A.d+n+1)-A.d;
	getdep(A.S,0,0,A.d);
	B.S=max_element(A.d+1,A.d+n+1)-A.d;
	getdep(B.S,0,0,B.d);
	A.build(); B.build();
	ll lastans=0;
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+lastans+n-1)%n+1;
		y=(y+lastans+n-1)%n+1;
		lastans=max(A.ask(x,y),B.ask(x,y));
		printf("%lld\n",lastans);
	}
}