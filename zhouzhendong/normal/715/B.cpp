#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
using namespace std;
typedef long long LL;
#define pii pair <int,int>
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1005,M=10005,INF=1e9+5;
int n,m,L,S,T;
struct Edge{
	int x,y,z;
}e[M];
struct Graph{
	int cnt,y[M*2],z[M*2],nxt[M*2],fst[N];
	void clear(){
		cnt=1,clr(fst);
	}
	void add(int a,int b,int c){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt,z[cnt]=c;
	}
	void update(int id,int v){
		z[id<<1]=z[id<<1|1]=v;
	}
}g;
vector <int> eid;
int dis[N],vis[N];
int Dijkstra(){
	static priority_queue <pii,vector <pii>,greater <pii> > Q;
	while (!Q.empty())
		Q.pop();
	for (int i=1;i<=n;i++)
		dis[i]=INF,vis[i]=0;
	dis[S]=0;
	Q.push(make_pair(dis[S],S));
	while (!Q.empty()){
		pii p=Q.top();
		Q.pop();
		int x=p.second;
		if (vis[x]||dis[x]!=p.first)
			continue;
		vis[x]=1;
		for (int i=g.fst[x];i;i=g.nxt[i]){
			int y=g.y[i],z=g.z[i];
			if (!vis[y]&&dis[x]+z<dis[y]){
				dis[y]=dis[x]+z;
				Q.push(make_pair(dis[y],y));
			}
		}
	}
	return dis[T];
}
int check(LL v){
	for (auto i : eid){
		LL d=min(v,(LL)L);
		g.update(i,d+1);
		v-=d;
	}
	return Dijkstra()<=L;
}
int main(){
	n=read(),m=read(),L=read(),S=read()+1,T=read()+1;
	g.clear();
	for (int i=1;i<=m;i++){
		int x=read()+1,y=read()+1,z=read();
		e[i].x=x,e[i].y=y,e[i].z=z;
		g.add(x,y,z);
		g.add(y,x,z);
		if (!z)
			eid.push_back(i);
	}
	for (auto i : eid)
		g.update(i,INF);
	if (Dijkstra()<L)
		return puts("NO"),0;
	for (auto i : eid)
		g.update(i,1);
	if (Dijkstra()>L)
		return puts("NO"),0;
	LL l=0,r=(LL)L*(int)eid.size(),mid,ans=l;
	while (l<=r){
		mid=(l+r)>>1;
		if (check(mid))
			l=mid+1,ans=mid;
		else
			r=mid-1;
	}
	for (auto i : eid){
		LL d=min(ans,(LL)L);
		e[i].z=d+1;
		ans-=d;
	}
	puts("YES");
	for (int i=1;i<=m;i++)
		printf("%d %d %d\n",e[i].x-1,e[i].y-1,e[i].z);
	return 0;
}