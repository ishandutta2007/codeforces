#include <bits/stdc++.h>
using namespace std;
const int N=500005,M=N*2;
struct Gragh{
	int cnt,y[M],nxt[M],fst[N];
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,q;
int in[N],out[N],Time;
int Max[2][N<<2],add[2][N<<2];
void update(int id,int rt,int L,int R,int xL,int xR,int v){
	if (R<xL||L>xR)
		return;
	if (xL<=L&&R<=xR){
//		printf("upd %d %d %d %d %d %d %d\n",rt,L,R,id,xL,xR,v);
		Max[id][rt]=max(Max[id][rt],v);
		add[id][rt]=max(add[id][rt],v);
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	Max[id][ls]=max(Max[id][ls],add[id][rt]);
	Max[id][rs]=max(Max[id][rs],add[id][rt]);
	add[id][ls]=max(add[id][ls],add[id][rt]);
	add[id][rs]=max(add[id][rs],add[id][rt]);
	update(id,ls,L,mid,xL,xR,v);
	update(id,rs,mid+1,R,xL,xR,v);
	Max[id][rt]=max(Max[id][ls],Max[id][rs]);
}
int query(int id,int rt,int L,int R,int xL,int xR){
	if (R<xL||L>xR)
		return -1;
	if (xL<=L&&R<=xR){
//		printf("qry %d %d %d %d %d %d\n",rt,L,R,id,xL,xR);
		return Max[id][rt];
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	Max[id][ls]=max(Max[id][ls],add[id][rt]);
	Max[id][rs]=max(Max[id][rs],add[id][rt]);
	add[id][ls]=max(add[id][ls],add[id][rt]);
	add[id][rs]=max(add[id][rs],add[id][rt]);
	return max(query(id,ls,L,mid,xL,xR),query(id,rs,mid+1,R,xL,xR));
}
void dfs(int x,int pre){
	in[x]=++Time;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre)
			dfs(g.y[i],x);
	out[x]=Time;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g.add(a,b);
		g.add(b,a);
	}
	Time=0;
	dfs(1,0);
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		int t,v;
		scanf("%d%d",&t,&v);
		if (t==1)
			update(0,1,1,n,in[v],out[v],i);
		if (t==2)
			update(1,1,1,n,in[v],in[v],i);
		if (t==3){
			int a=query(0,1,1,n,in[v],in[v]);
			int b=query(1,1,1,n,in[v],out[v]);
//			printf("%d %d\n",a,b);
			puts(a>b?"1":"0");
		}
	}
	return 0;
}