#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2220, M = 2530030, inf = 0x3f3f3f3f;
int S,T,head[N],cur[N],nxt[M],cap[M],to[M],edgenum=1; //1.WA--edgenum=1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void addedge(int u, int v, int c){
	to[++edgenum]=v;cap[edgenum]=c;nxt[edgenum]=head[u];head[u]=edgenum;
}
void add(int u, int v, int c){
	addedge(u,v,c);addedge(v,u,0);
}
int dis[N],q[N];
inline bool bfs() {
	memset(dis,inf,4*(T+2));//2.memsetsizeof()
	int f=0,r=1; q[f]=T; dis[T]=0;
	while (f!=r) {
		int u=q[f++];
		L(i,u) if (cap[i^1]&&dis[to[i]]==inf){
			q[r++]=to[i];dis[to[i]]=dis[u]+1;if(to[i]==S)return 1;//3.
		}
	}
	return dis[S]<inf;
}
inline int dfs(int u, int flow) {
	if (u==T||!flow)return flow;int res=0;
	for(register int &i=cur[u];i;i=nxt[i])if(cap[i]&&dis[u]==dis[to[i]]+1){//4. 
		int tmp=dfs(to[i],min(flow,cap[i]));
		res+=tmp;flow-=tmp;cap[i]-=tmp;cap[i^1]+=tmp;if(!flow)break;
	}
	return res;
}
inline int dinic() {
	int res=0;
	while (bfs()) {
		memcpy(cur,head,4*(T+2)); res+=dfs(S,inf);
	}
	return res;
}
bool ok[2333][2333];int n1,n2,k,h;
namespace yzr{
	int dis[111][111],n,m,A[2333],B[2333],C[2333];
	void init(){
		memset(dis,inf,sizeof(dis));
		read(n);read(m);
		while(m--){
			int u,v;read(u);read(v);
			umin(dis[u][v],1);umin(dis[v][u],1);
		}
		rep(i,1,n)dis[i][i]=0;
		rep(k,1,n)rep(i,1,n)rep(j,1,n)
			umin(dis[i][j],dis[i][k]+dis[k][j]);
	//	rep(i,1,n){rep(j,1,n)printf("%d ",dis[i][j]);puts("");}
		read(n1);read(n2);read(k);read(h);
		rep(i,1,n1){
			read(A[i]);read(B[i]);read(C[i]);
		}
		rep(i,1,n2){
			int x,d;read(x);read(d);
			rep(j,1,n1)ok[j][i]=dis[A[j]][x]<=C[j]&&B[j]>=d;
		}
	//	rep(i,1,n1){rep(j,1,n2)printf("%d ",ok[i][j]);puts("");}
	}
}
int main() {
	yzr::init();
	int tmp=n1+n2+1;S=n1+n2+2;T=S+1;
	rep(i,1,n2)add(n1+i,T,1);
	rep(i,1,n1)rep(j,1,n2)if(ok[i][j])add(i,n1+j,1);
	rep(i,1,n1)add(tmp,i,1);add(S,tmp,n1);
	ll res=1e18;int tot=dinic();
	per(i,n1,0){
		umin(res,1LL*i*h+1LL*min(n1-i,tot)*k);
	}
	cout<<res;
	return 0;
}