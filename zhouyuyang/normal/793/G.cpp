#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
#define fi first
#define se second
#define BG begin
#define ED end

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

#define INF (1<<29)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=10005;
const int Nd=300005;
struct edge{
	int to,next,f;
}e[Nd*5];
int head[Nd],tot=1;
int S,T,sz;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot; 
}
int dis[Nd],q[Nd];
bool bfs(){
	For(i,1,sz) dis[i]=-1;
	int h=0,t=1; dis[q[1]=S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int lg[N],f[15][N],g[15][N];
void connect(int l,int r,int x,int y){
	if (l>r||x>y) return;
	int k1=lg[r-l+1],k2=lg[y-x+1];
	add(f[k1][l],g[k2][x],INF);
	add(f[k1][l],g[k2][y-(1<<k2)+1],INF);
	add(f[k1][r-(1<<k1)+1],g[k2][x],INF);
	add(f[k1][r-(1<<k1)+1],g[k2][y-(1<<k2)+1],INF); 
}
struct range{
	int x,l,r;
	bool operator <(const range &a)const{
		if (r!=a.r) return r<a.r;
		if (l!=a.l) return l>a.l;
		return x<a.x;
	}
};
set<range> s;
struct que{
	int tp,x,l,r;
}qq[N*2];
void ins(que x){
	set<range>::iterator it;
	it=s.end(); it--;
	it=s.lower_bound((range){-1,x.l,x.r});
	int L=it->l,R=it->r;
	connect(it->x,x.x-1,L,R);
	s.erase(it);
	if (L!=x.l) s.insert((range){x.x,L,x.l-1});
	if (R!=x.r) s.insert((range){x.x,x.r+1,R});
}
void del(que x){
	set<range>::iterator it;
	it=s.lower_bound((range){-1,x.l,x.r});
	int R=x.r,L=x.l;
	if (it!=s.end()&&it->l==x.r+1){
		connect(it->x,x.x-1,it->l,it->r);
		R=it->r; s.erase(it);
	}
	it=s.lower_bound((range){-1,x.l,x.r});
	if (it!=s.begin())
		if ((--it)->r==x.l-1){
			connect(it->x,x.x-1,it->l,it->r);
			L=it->l; s.erase(it);
		}
	s.insert((range){x.x,L,R});
}
bool cmp(que a,que b){
	if (a.x!=b.x) return a.x<b.x;
	return a.tp>b.tp;
}
int n,Q;
int main(){
	scanf("%d%d",&n,&Q);
	For(i,2,n) lg[i]=lg[i/2]+1;
	sz=n*2; S=++sz; T=++sz;
	For(i,1,n) f[0][i]=i;
	For(i,1,14) For(j,1,n-(1<<i)+1){
		f[i][j]=++sz;
		add(f[i-1][j],f[i][j],INF);
		add(f[i-1][j+(1<<(i-1))],f[i][j],INF); 
	}
	For(i,1,n) g[0][i]=i+n;
	For(i,1,14) For(j,1,n-(1<<i)+1){
		g[i][j]=++sz;
		add(g[i][j],g[i-1][j],INF);
		add(g[i][j],g[i-1][j+(1<<(i-1))],INF); 
	}
	For(i,1,n)
		add(S,i,1),add(i+n,T,1);
	int cnt=0;
	For(i,1,Q){
		int x,y,X,Y;
		scanf("%d%d%d%d",&x,&y,&X,&Y);
		qq[++cnt]=(que){1,x,y,Y};
		qq[++cnt]=(que){2,X+1,y,Y};
	}
	s.insert((range){1,1,n});
	sort(qq+1,qq+cnt+1,cmp);
	For(i,1,cnt)
		if (qq[i].tp==1) ins(qq[i]);
		else del(qq[i]);
	for (;s.begin()!=s.end();){
		range tmp=*s.begin();
		s.erase(s.begin());
		connect(tmp.x,n,tmp.l,tmp.r);
	}
	int ans=0;
	for (;bfs();ans+=dfs(S,INF));
	printf("%d\n",ans); 
}