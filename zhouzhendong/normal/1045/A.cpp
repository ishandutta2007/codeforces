#include <bits/stdc++.h>
using namespace std;
typedef int LL;
const int N=5005;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
struct Edge{
	int x,y,nxt,cap;
	Edge(){}
	Edge(int a,int b,int c,int d){
		x=a,y=b,cap=c,nxt=d;
	}
};
struct Network{
	static const int N=20005,M=1e6,INF=0x3FFFFFFF;
	Edge e[M];
	int n,S,T,fst[N],cur[N],cnt;
	int q[N],dis[N],head,tail;
	LL MaxFlow;
	void clear(int _n){
		n=_n,cnt=1;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b,int c){
		e[++cnt]=Edge(a,b,c,fst[a]),fst[a]=cnt;
		e[++cnt]=Edge(b,a,0,fst[b]),fst[b]=cnt;
	}
	void init(){
		for (int i=1;i<=n;i++)
			cur[i]=fst[i];
	}
	void init(int _S,int _T){
		S=_S,T=_T,MaxFlow=0,init();
	}
	int bfs(){
		memset(dis,0,sizeof dis);
		head=tail=0;
		q[++tail]=T,dis[T]=1;
		while (head<tail)
			for (int x=q[++head],i=fst[x];i;i=e[i].nxt)
				if (!dis[e[i].y]&&e[i^1].cap){
					if (e[i].y==T)
						return 1;
					dis[q[++tail]=e[i].y]=dis[x]+1;
				}
		return (bool)dis[S];
	}
	int dfs(int x,int Flow){
		if (x==T||!Flow)
			return Flow;
		int now=Flow;
		for (int &i=cur[x];i;i=e[i].nxt){
			int y=e[i].y;
			if (dis[x]==dis[y]+1&&e[i].cap){
				int d=dfs(y,min(now,e[i].cap));
				e[i].cap-=d,e[i^1].cap+=d,now-=d;
				if (now==0)
					break;
			}
		}
		return Flow-now;
	}
	LL Dinic(){
		while (bfs())
			init(),MaxFlow+=dfs(S,INF);
		return MaxFlow;
	}
	LL Auto(int _S,int _T){
		init(_S,_T);
		return Dinic();
	}
}g;
int n,m,tot,S,T;
int Type[N],ida[N],idsh[N],Turn[20005];
struct Node0{vector <int> id;Node1(){id.clear();}}a0[N];
struct Node1{vector <int> id;Node2(){id.clear();}}a1[N];
struct Node2{int a,b,c,ia,ib,ic;}a2[N];
struct Seg{int id,eL,eR;}t[N<<2];
void build(int rt,int L,int R){
	Turn[t[rt].id=++tot]=rt;
	if (L==R)
		return (void)(g.add(t[rt].id,idsh[L],1e6),t[rt].eL=g.cnt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	g.add(t[rt].id,t[ls].id,1e6),t[rt].eL=g.cnt;
	g.add(t[rt].id,t[rs].id,1e6),t[rt].eR=g.cnt;
}
void update(int rt,int L,int R,int xL,int xR,int id,vector <int> &ie){
	if (xR<L||R<xL)
		return;
	if (xL<=L&&R<=xR)
		return g.add(id,t[rt].id,1),ie.push_back(g.cnt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	update(ls,L,mid,xL,xR,id,ie);
	update(rs,mid+1,R,xL,xR,id,ie);
}
int find(int rt){
	if (!t[rt].eR)
		if (g.e[t[rt].eL].cap)
			return g.e[t[rt].eL].cap--,(g.e[t[rt].eL].x-T);
		else
			return 0;
	if (g.e[t[rt].eL].cap)
		if (int res=find(rt<<1))
			return g.e[t[rt].eL].cap--,res;
	if (g.e[t[rt].eR].cap)
		if (int res=find(rt<<1|1))
			return g.e[t[rt].eR].cap--,res;
	return 0;
}
int Match[N],Mat[2][N];
vector <int> IDs[N<<2];
int Get0(int i){
	for (vector <int> :: iterator p=a0[i].id.begin();p!=a0[i].id.end();p++)
		if (g.e[*p].cap)
			return g.e[*p].x-T;
	return 0;
}
void Get1(int i){
	for (vector <int> :: iterator p=a1[i].id.begin();p!=a1[i].id.end();p++)
		if (g.e[*p].cap)
			return IDs[Turn[g.e[*p].x]].push_back(i);
}
void Solve_Seg(int rt){
	while (IDs[rt].size()>0)
		Match[find(rt)]=IDs[rt].back(),IDs[rt].pop_back();
	if (!t[rt].eR)
		return;
	Solve_Seg(rt<<1);
	Solve_Seg(rt<<1|1);
}
int tag[N],cc[N];
int main(){
	n=read(),m=read();
	g.clear(30000);
	tot=2,S=1,T=2;
	for (int i=1;i<=m;i++)
		g.add(idsh[i]=++tot,T,1);
	build(1,1,m);
	for (int i=1;i<=n;i++)
		ida[i]=++tot;
	for (int i=1;i<=n;i++){
		Type[i]=read();
		if (Type[i]==0){
			int K=read();
			g.add(S,ida[i],1);
			for (int j=0;j<K;j++){
				g.add(ida[i],idsh[read()],1);
				a0[i].id.push_back(g.cnt);
			}
		}
		if (Type[i]==1){
			int L=read(),R=read();
			g.add(S,ida[i],1);
			update(1,1,m,L,R,ida[i],a1[i].id);
		}
		if (Type[i]==2){
			g.add(S,ida[i],2);cc[i]=g.cnt;
			g.add(ida[i],idsh[a2[i].a=read()],1),a2[i].ia=g.cnt;
			g.add(ida[i],idsh[a2[i].b=read()],1),a2[i].ib=g.cnt;
			g.add(ida[i],idsh[a2[i].c=read()],1),a2[i].ic=g.cnt;
			assert(!tag[a2[i].a]&&!tag[a2[i].b]&&!tag[a2[i].c]);
			tag[a2[i].a]=tag[a2[i].b]=tag[a2[i].c]=1;
		}
	}
	g.n=tot;
	int ans=g.Auto(S,T);
	printf("%d\n",ans);
	memset(Match,0,sizeof Match);
	for (int i=1;i<=n;i++){
		if (Type[i]==0)	Match[Get0(i)]=i;
		if (Type[i]==1)	Get1(i);
	}
	Solve_Seg(1);
	for (int i=1;i<=n;i++)
		if (Type[i]==2){
			int cnt=Mat[0][i]=Mat[1][i]=0;
			if (g.e[a2[i].ia].cap)Mat[cnt++][i]=g.e[a2[i].ia].x-T;
			if (g.e[a2[i].ib].cap)Mat[cnt++][i]=g.e[a2[i].ib].x-T;
			if (g.e[a2[i].ic].cap)Mat[cnt++][i]=g.e[a2[i].ic].x-T;
if (cnt==1){if (!g.e[a2[i].ia].cap)Match[a2[i].a]=0,Mat[cnt++][i]=a2[i].a;
	   else if (!g.e[a2[i].ib].cap)Match[a2[i].b]=0,Mat[cnt++][i]=a2[i].b;
	   else if (!g.e[a2[i].ic].cap)Match[a2[i].c]=0,Mat[cnt++][i]=a2[i].c;}
			Match[Mat[0][i]]=Match[Mat[1][i]]=i;
		}
	for (int i=1;i<=m;i++)
		if (Match[i]!=0)
			printf("%d %d\n",Match[i],i);
	return 0;
}