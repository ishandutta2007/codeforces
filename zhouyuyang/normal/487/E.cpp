#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int M=525000;
int n,m,q,fangsz;
int v[N];
struct Segment{
	int t[M];
	void change(int k,int l,int r,int p,int v){
		if (l==r){
			t[k]=v;
			return;
		}
		int mid=(l+r)/2;
		if (p<=mid) change(k*2,l,mid,p,v);
		else change(k*2+1,mid+1,r,p,v);
		t[k]=min(t[k*2],t[k*2+1]);
	}
	int ask(int k,int l,int r,int x,int y){
		if (l==x&&r==y) return t[k];
		int mid=(l+r)/2;
		if (y<=mid) return ask(k*2,l,mid,x,y);
		if (x>mid) return ask(k*2+1,mid+1,r,x,y);
		return min(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
	}
};
struct edge{
	int to,next;
};
struct Heap{
	priority_queue<int,vector<int>,greater<int> > q1,q2;
	void insert(int x){
		q1.push(x);
	}
	void erase(int x){
		q2.push(x);
	}
	int ask(){
		for (;!q2.empty()&&q1.top()==q2.top();)
			q1.pop(),q2.pop();
		return q1.top();
	}
};
struct Tree2{
	edge e[N*4];
	int head[N*2],tot;
	int pos[N*2],top[N*2],T;
	int sz[N*2],fa[N*2],dep[N*2];
	Segment Seg;
	Heap hp[N*2];
	void add(int x,int y){
		e[++tot]=(edge){y,head[x]};
		head[x]=tot;
		e[++tot]=(edge){x,head[y]};
		head[y]=tot;
	}
	void dfs1(int x){
		sz[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa[x]){
				fa[e[i].to]=x;
				dep[e[i].to]=dep[x]+1;
				dfs1(e[i].to);
				sz[x]+=sz[e[i].to];
			}
	}
	void dfs2(int x,int tp){
		pos[x]=++T; top[x]=tp; int k=0;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
				k=e[i].to;
		if (k) dfs2(k,tp);
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa[x]&&e[i].to!=k)
				dfs2(e[i].to,e[i].to);
	}
	void build(){
		dep[1]=1; dfs1(1);
		dfs2(1,1);
	}
	void change(int x,int val,int tp){
		if (fa[x]>n){
			if (tp) hp[fa[x]].erase(v[x]);
			hp[fa[x]].insert(val);
			Seg.change(1,1,fangsz,pos[fa[x]],hp[fa[x]].ask());
		}
		if (tp) hp[x].erase(v[x]);
		hp[x].insert(v[x]=val);
		Seg.change(1,1,fangsz,pos[x],hp[x].ask());
	}
	int ask(int x,int y){
		int X=x,Y=y,ans=1e9;
		for (;top[x]!=top[y];x=fa[top[x]]){
			if (dep[top[x]]<dep[top[y]]) swap(x,y);
			ans=min(ans,Seg.ask(1,1,fangsz,pos[top[x]],pos[x]));
		}
		if (dep[x]<dep[y]) swap(x,y);
		ans=min(ans,Seg.ask(1,1,fangsz,pos[y],pos[x]));
		if (y!=X&&y!=Y&&y>n)
			ans=min(ans,hp[fa[y]].ask());
		return ans;
	}
}T2;
struct Tree1{
	edge e[N*2];
	int head[N],tot;
	int dfn[N],low[N];
	int sta[N],top,T;
	void add(int x,int y){
		e[++tot]=(edge){y,head[x]};
		head[x]=tot;
	}
	void tarjan(int x,int fa){
		sta[++top]=x;
		dfn[x]=low[x]=++T;
		for (int i=head[x];i;i=e[i].next)
			if (!dfn[e[i].to]){
				int beg=top;
				tarjan(e[i].to,x);
				low[x]=min(low[x],low[e[i].to]);
				if (low[e[i].to]<dfn[x]) continue;
				fangsz++;
				T2.add(x,fangsz);
				for (;top>beg;top--)
					T2.add(sta[top],fangsz);
			}
			else if (e[i].to!=fa)
				low[x]=min(low[x],dfn[e[i].to]);
	}
}T1;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	fangsz=n;
	for (int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		T1.add(x,y); T1.add(y,x);
	}
	T1.tarjan(1,0);
	T2.build();
	for (int i=1;i<=n;i++)
		T2.change(i,v[i],0);
	while (q--){
		char s[5];
		int x,y;
		scanf("%s%d%d",s,&x,&y);
		if (s[0]=='C')
			T2.change(x,y,1);
		else
			printf("%d\n",T2.ask(x,y));
	}
}