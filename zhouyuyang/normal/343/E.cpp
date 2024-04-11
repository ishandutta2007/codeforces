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
using namespace std;

const int N=205;
struct edge{
	int to,next,f,wzp;
}e[N*10];
int head[N],dis[N],q[N];
int cur[N],c[N][N],ans[N];
int n,m,S,T,tot=1,sum;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v,v};
	head[x]=tot;
}
bool bfs(){
	For(i,1,n) dis[i]=-1;
	int h=0,t=1; dis[S]=0; q[1]=S;
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
	int rest=flow,k;
	for (int &i=cur[x];i&&rest;i=e[i].next)
		if (e[i].f&&dis[e[i].to]==dis[x]+1){
			k=dfs(e[i].to,min(e[i].f,rest));
			rest-=k; e[i].f-=k; e[i^1].f+=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int run(){
	For(i,2,tot) e[i].f=e[i].wzp;
	int ans=0;
	while (bfs()){
		CPY(cur,head);
		ans+=dfs(S,1e9);
	}
	return ans;
}
void work(vi v){
	if (v.size()==1) return;
	S=v[0]; T=v[1]; int tmp=run();
	For(i,1,n) For(j,1,n)
		if ((dis[i]!=-1)^(dis[j]!=-1))
			c[i][j]=min(c[i][j],tmp);
	vi ls,rs;
	For(i,0,v.size()-1)
		dis[v[i]]!=-1?ls.PB(v[i]):rs.PB(v[i]);
	work(ls); work(rs);
}
void getans(vi v){
	if (v.size()==1) return ans[++*ans]=v[0],void(0);
	S=v[0],T=v[1];
	For(i,2,v.size()-1)
		if (c[S][v[i]]<c[S][T]) T=v[i];
	sum+=run();
	vi ls,rs;
	For(i,0,v.size()-1)
		dis[v[i]]!=-1?ls.PB(v[i]):rs.PB(v[i]);
	getans(ls); getans(rs);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	For(i,1,n) For(j,1,n) c[i][j]=1e9;
	vi all; For(i,1,n) all.PB(i);
	work(all); getans(all);
	printf("%d\n",sum);
	For(i,1,n) printf("%d\n",ans[i]);
}