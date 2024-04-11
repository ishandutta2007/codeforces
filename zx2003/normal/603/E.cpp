#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=400010,inf=1<<30;
int n,m,i,ans,tt,u,v,bs,f[N],g[N];
struct edge{
	int u,v,w,id;
	bool operator<(const edge&x)const{
		return w<x.w || (w==x.w && id<x.id);
	}
}e[N],o;
multiset<edge> s;
pii x;
inline void swap(int&a,int&b){
	tt=a;
	a=b;
	b=tt;
}
inline pii max(const pii a,const pii b){
	return a<b?b:a;
}
inline void up(int&a,int b){
	if(a>b)a=b;
}
struct LCT{
	struct node{
		int l,r,fa,w,sz;
		bool rev;
		pii m,v;
	}a[N];
	int w,s[N];
	inline bool isroot(int x){
		return a[a[x].fa].l!=x && a[a[x].fa].r!=x;
	}
	inline void pushdown(int x){
		if(a[x].rev){
			a[a[x].l].rev^=1;
			a[a[x].r].rev^=1;
			swap(a[x].l,a[x].r);
			a[x].rev=0;
		}
	}
	inline void maintain(int x){
		a[x].m=max(max(a[a[x].l].m,a[a[x].r].m),a[x].v);
		a[x].sz=a[x].w+a[a[x].l].sz+a[a[x].r].sz;
	}
	inline void rotate(int x){
		int y=a[x].fa,z=a[y].fa;
		if(!isroot(y)){
			if(a[z].l==y)a[z].l=x;
				else a[z].r=x;
		}
		a[y].fa=x;
		a[x].fa=z;
		if(a[y].l==x){
			a[a[x].r].fa=y;
			a[y].l=a[x].r;
			a[x].r=y;
		}else{
			a[a[x].l].fa=y;
			a[y].r=a[x].l;
			a[x].l=y;
		}
		maintain(y);
		maintain(x);
	}
	inline void splay(int x){
		int i,u,v;
		s[w=1]=x;
		for(u=x;!isroot(u);u=a[u].fa)s[++w]=a[u].fa;
		for(i=w;i;--i)pushdown(s[i]);
		while(!isroot(x)){
			u=a[x].fa;
			v=a[u].fa;
			if(!isroot(u)){
				if((a[u].l==x)^(a[v].l==u))rotate(x);
					else rotate(u);
			}
			rotate(x);
		}
	}
	inline void access(int x){
		int t=0;
		while(x){
			splay(x);
			a[x].w+=a[a[x].r].sz-a[t].sz;
			a[x].r=t;
			maintain(x);
			t=x;
			x=a[x].fa;
		}
	}
	inline void makeroot(int x){
		access(x);
		splay(x);
		a[x].rev^=1;
	}
	inline int find(int x){
		access(x);
		splay(x);
		while(a[x].l)x=a[x].l;
		return x;
	}
	inline void link(int x,int y){
		makeroot(x);
		access(y);
		splay(y);
		a[x].fa=y;
		a[y].w+=a[x].sz;
		a[y].sz+=a[x].sz;
	}
	inline void cut(int x,int y){
		makeroot(x);
		access(y);
		splay(y);
		a[x].fa=a[y].l=0;
		maintain(y);
	}
	inline pii query(int u,int v){
		makeroot(u);
		access(v);
		splay(v);
		return a[v].m;
	}
}t;
inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x;
}
int buf[100];
inline void putint(int x){
	if(!x)putchar('0');
		else{
			if(x<0)putchar('-'),x=-x;
			int xb=0;
			for(;x;x/=10)buf[++xb]=x%10;
			for(;xb;--xb)putchar(buf[xb]+48);
		}
}
int gfa(int x){
	return f[x]==x?x:f[x]=gfa(f[x]);
}
int main(){
	//freopen("ex_forest3.in","r",stdin);
	scanf("%d%d",&n,&m);
	t.a[0].m=t.a[0].v=make_pair(0,i);
	for(i=1;i<=n;++i)t.a[i].m=t.a[i].v=make_pair(0,f[i]=i),t.a[i].sz=t.a[i].w=g[i]=1;
	bs=n;
	for(i=1;i<=m;++i){
		e[i].u=getint();
		e[i].v=getint();
		e[i].w=getint();
		e[i].id=i+n;
		t.a[i+n].m=t.a[i+n].v=make_pair(e[i].w,i+n);
		u=t.find(e[i].u);
		v=t.find(e[i].v);
		if(u!=v){
			t.splay(u);
			t.splay(v);
			if(t.a[u].sz&1 && t.a[v].sz&1)bs-=2;
			f[u]=v;
			g[v]+=g[u];
			t.link(i+n,e[i].u);
			t.link(i+n,e[i].v);
			s.insert(e[i]);
		}else{
			x=t.query(e[i].u,e[i].v);
			//printf("%d\n",x.first);
			if(x.first>e[i].w){
				t.cut(e[x.second-n].u,x.second);
				t.cut(e[x.second-n].v,x.second);
				t.link(i+n,e[i].u);
				t.link(i+n,e[i].v);
				s.insert(e[i]);
				s.erase(s.find(e[x.second-n]));
			}
		}
		if(!bs){
			o.id=0;
			for(;!s.empty() && (!o.id || (!(t.a[o.u].sz&1) && !(t.a[o.v].sz&1)));){
				o=*s.rbegin();
				s.erase(--s.end());
				t.cut(o.u,o.id);
				t.cut(o.v,o.id);
			}
			s.insert(o);
			t.link(o.u,o.id);
			t.link(o.v,o.id);
			printf("%d\n",o.w);
			//cout<<s.size()<<endl;
		}else puts("-1");
		//for(int i=1;i<=8;++i)printf("%d %d\n",t.a[i].w,t.a[i].sz);
	}
	return 0;
}