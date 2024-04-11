#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;typedef __int128 LI;
const int N=1e3+10,M=5e5+10;const LL inf=1e18;
int T,n,m,dnt,t,s[N],d[N][N],head[N],to[M],next[M];LL g[N][N],f[N][N],pd[N][N];
template<typename T>T min(T x,T y){return x<y?x:y;}
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
struct edge{
	int u,v,w;edge(){};
	edge(int u,int v,int w):u(u),v(v),w(w){};
	bool operator<(const edge &nxt)const{return w>nxt.w;}
}err[M];
void ad(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
/*struct cpx{
	LL x,y;cpx():x(0),y(0){};
	cpx(LL x,LL y):x(x),y(y){};
	cpx operator-(cpx nxt){return cpx(x-nxt.x,y-nxt.y);}
	LI operator&(cpx nxt){return (LI)x*nxt.y-(LI)y*nxt.x;}
}crr[M];
struct queue{
	int p,q,a[N];queue():p(0),q(0){};
	void clr(){p=q=0;}int size(){return q-p;}
	void push(int x){a[++q]=x;}int front(){return a[++p];}
}q;
bool chk(cpx a,cpx b){return (a&b)>=0;}
LL calc(cpx a,int b){return a.y-b*a.x;}
void upd(int *a,int u){for(int i=head[u];i;i=next[i])if(a[to[i]]==-1)a[to[i]]=a[u]+1,q.push(to[i]);}
void update(int x){
	for(int i=1;i<=n;++i)d[x][i]=-1;
	q.clr(),d[x][x]=0,q.push(x);
	while(q.size())upd(d[x],q.front());
}*/
int main(){
	scanf("%d",&T);
	while(T--){
		dnt=0,memset(head,0,sizeof(head));
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)d[i][j]=1e9;
		for(int u,v,w,i=1;i<=m;++i){
			scanf("%d %d %d",&u,&v,&w);
			d[u][v]=d[v][u]=1,err[i]=edge(u,v,w);
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)cmin(d[j][k],d[j][i]+d[i][k]);
		/*std::sort(err+1,err+m+1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int u=err[j].u,v=err[j].v,w=err[j].w;
				crr[j]=cpx(-w,(LL)w*(min(d[u][i],d[v][i])+2));
			}
			t=0;
			for(int j=1;j<=m;++j){
				while(t>1&&!chk(crr[s[t]]-crr[s[t-1]],crr[j]-crr[s[t]]))--t;
				s[++t]=j;
			}
			for(int p=1,j=1;j<=2*n;++j){
				while(p<t&&calc(crr[s[p+1]],j)<calc(crr[s[p]],j))++p;
				pd[i][j]=calc(crr[s[p]],j);
			}
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)f[i][j]=g[i][j]=inf;
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)continue;f[i][j]=inf;
				for(int k=1;k<=n;++k)cmin(f[i][j],pd[k][d[i][k]+d[j][k]]);
			}
		}
		for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cmin(f[i][j],f[i][k]+f[k][j]);
		printf("%lld\n",f[1][n]);*/
		LL ans=inf;
		for(int i=1;i<=m;++i){
			int u=err[i].u,v=err[i].v,w=err[i].w;
			cmin(ans,(LL)(d[1][u]+d[v][n]+1)*w);
			cmin(ans,(LL)(d[1][v]+d[u][n]+1)*w);
			for(int j=1;j<=n;++j)cmin(ans,(LL)w*(d[1][j]+d[j][n]+min(d[u][j],d[v][j])+2));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
6 6
1 2 10
2 3 10
4 2 100
5 2 100
4 5 2
3 6 1
*/