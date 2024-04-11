#include<bits/stdc++.h>
#define pa pair<int,int>
#define N 1000005
using namespace std;
int ch[N][2],fa[N];
int rev[N],s[N],val[N];
int n,m,q;
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
bool isrt(int x){
	return ls(fa[x])!=x&&rs(fa[x])!=x;
}
bool get(int x){
	return rs(fa[x])==x; 
}
void pushdown(int x){
	if (!rev[x]) return;
	swap(ls(x),rs(x));
	rev[ls(x)]^=1;
	rev[rs(x)]^=1;
	rev[x]=0;
}
void pushup(int x){
	s[x]=val[x]^s[ls(x)]^s[rs(x)];
}
void down(int x){
	if (!isrt(x)) down(fa[x]);
	pushdown(x);
}
void rotate(int x){
	int y=fa[x],z=fa[y],l=get(x),r=l^1;
	if (!isrt(y)) ch[z][get(y)]=x;
	fa[y]=x; fa[x]=z; fa[ch[x][r]]=y;
	ch[y][l]=ch[x][r]; ch[x][r]=y;
	pushup(y); pushup(x);
}
void splay(int x){
	down(x);
	while(!isrt(x)){
		int y=fa[x];
		if (!isrt(y)){
			if (get(x)^get(y)) rotate(x);
			else rotate(y); 
		}
		rotate(x);
	}
}
void access(int x){
	int p=x,t=0;
	for (;x;t=x,x=fa[x])
		splay(x),rs(x)=t,pushup(x);
	splay(p);
}
void mkroot(int x){
	access(x);
	rev[x]^=1;
}
void link(int x,int y){
	mkroot(x);
	splay(y);
	fa[x]=y;
}
void cut(int x,int y){
	access(y);
	splay(x);
	if (!fa[x]) fa[y]=0;
	access(x);
	splay(y);
	if (!fa[y]) fa[x]=0;
}
bool linked(int x,int y){
	access(x);
	access(y);
	return fa[x];
}

struct edge{int l,r,x,y,z;}e[N];
void add(int id,int *g){
	int x=e[id].x,y=e[id].y,z=e[id].z;
	if (!linked(x,y)){
		val[n+id]=s[n+id]=z;
		link(x,n+id); link(y,n+id);
	}
	else{
		mkroot(x); access(y);
		z^=s[y];
		for (int i=30;i>=0;i--)
			if ((1<<i)&z){
				if (g[i])
					z^=g[i];
				else{
					g[i]=z;
					break;
				}
			}
	}
}
void del(int id){
	int x=e[id].x,y=e[id].y;
	if (linked(x,y))
		cut(x,n+id),cut(y,n+id);
}
int ask(int x,int y,int *g){
	mkroot(x);
	access(y);
	int z=s[y];
	for (int i=30;i>=0;i--)
		if ((z^g[i])<=z)
			z^=g[i];
	return z;
}

int u[N],v[N],g[40][40];
vector<int> V[N];
void insert(int k,int l,int r,int x,int y,int id){
	if (l==x&&r==y){
		V[k].push_back(id);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) insert(k*2,l,mid,x,y,id);
	else if (x>mid) insert(k*2+1,mid+1,r,x,y,id);
	else insert(k*2,l,mid,x,mid,id),
		 insert(k*2+1,mid+1,r,mid+1,y,id);
}
void solve(int k,int l,int r,int dep){
	for (int i=0;i<=30;i++)
		g[dep][i]=g[dep-1][i];
	for (int i=0;i<V[k].size();i++)
		add(V[k][i],g[dep]);
	if (l==r){
		if (u[l]) printf("%d\n",ask(u[l],v[l],g[dep]));
		return;
	}
	int mid=(l+r)/2;
	solve(k*2,l,mid,dep+1);
	solve(k*2+1,mid+1,r,dep+1);
	for (int i=0;i<V[k].size();i++)
		del(V[k][i]);
}

map<pa,int> mp;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		e[i].l=1; mp[pa(e[i].x,e[i].y)]=i;
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		int fl; scanf("%d",&fl);
		if (fl==1){
			m++; scanf("%d%d%d",&e[m].x,&e[m].y,&e[m].z);
			e[m].l=i; mp[pa(e[m].x,e[m].y)]=m;
		}
		if (fl==2){
			int x,y; scanf("%d%d",&x,&y);
			e[mp[pa(x,y)]].r=i;
		}
		if (fl==3)
			scanf("%d%d",&u[i],&v[i]);
	}
	for (int i=1;i<=m;i++)
		if (!e[i].r) e[i].r=q;
	for (int i=1;i<=m;i++)
		insert(1,1,q,e[i].l,e[i].r,i);
	solve(1,1,q,1);
}