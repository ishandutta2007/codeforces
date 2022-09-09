#include<cstdio>
const int N=300005;
int n,a[N],i,c,d,j,x;
struct segtree{
	struct node{
		int l,r,m,s;
		bool v;
	}t[N*18];
	void build(int i,int l,int r){
		t[i].l=l;
		t[i].r=r;
		t[i].m=(l+r)>>1;
		if(l^r)build(i<<1,l,t[i].m),build(i<<1|1,t[i].m+1,r);
	}
	inline void pushdown(int i){
		//printf("%d\n",i);
		if(t[i].v)t[i<<1].v=t[i<<1|1].v=1,t[i].v=0,t[i<<1].s=t[i<<1|1].s=0;
	}
	void set(int i,int l,int r){
		if(t[i].l==l && t[i].r==r){
			t[i].s=0;
			t[i].v=1;
		}else{
			pushdown(i);
			if(l>t[i].m)set(i<<1|1,l,r);
				else if(r<=t[i].m)set(i<<1,l,r);
						else set(i<<1,l,t[i].m),set(i<<1|1,t[i].m+1,r);
			t[i].s=t[i<<1].s+t[i<<1|1].s;
		}
	}
	inline void add(int l){		
		for(register int i=1;t[i].l;i=i<<1|(l>t[i].m))pushdown(i),++t[i].s;
	}
}tt;
inline void swap(int&a,int&b){
	register int t=a;a=b;b=t;
}
struct tree{
	static const int M=N<<1;
	struct edge{
		int to,next;
	}e[N<<2];
	int h[M],id[M],right[M],sz[M],ma[M],top[M],dad[M],xb,dep[M],dfn[M],sl;
	inline void addedge(int u,int v){
		e[++xb]=(edge){v,h[u]};
		h[u]=xb;
	}
	void dfs(int x,int fa){
		sz[x]=1;
		dep[x]=dep[dad[dfn[id[x]=++xb]=x]=fa]+1;
		for(int i=h[x];i;i=e[i].next)
			if(e[i].to!=fa){
				dfs(e[i].to,x);
				sz[x]+=sz[e[i].to];
				if(sz[e[i].to]>sz[ma[x]])ma[x]=e[i].to;
			}
		right[x]=xb;
	}
	inline void prepare(){
		dfs(1,xb=0);
		for(register int i=1;i<n<<1;++i)
			top[dfn[i]]=dfn[i]==ma[dad[dfn[i]]]?top[dad[dfn[i]]]:dfn[i];
	}
	inline int dis(int a,int b){
		register int u=a,v=b;
		while(top[u]^top[v]){
			if(dep[top[u]]>dep[top[v]])swap(u,v);
			v=dad[sl=top[v]];
		}
		if(dep[u]>dep[v])swap(u,v);
		if(u^v)sl=ma[u];
		return dep[a]+dep[b]-(dep[u]<<1);
	}
}t;
int main(){
	//freopen("e.txt","r",stdin);
	//freopen("e.out","w",stdout);
	scanf("%d",&n);
	for(++n,i=2;i<=n;++i)scanf("%d",a+i),t.addedge(a[i],n+i-1),t.addedge(n+i-1,i);
	t.prepare();
	tt.build(1,c=1,n*2-1);
	tt.add(1);
	for(i=2;i<=n;++i){
		j=t.dis(c,i);
		x=t.sl;
		if(j>d){
			if(j==t.dep[i]-t.dep[c]){
				tt.set(1,t.id[x],t.right[x]);
				c=x;
			}else{
				if(1<t.id[c])tt.set(1,1,t.id[c]-1);
				if(t.right[c]+1<n<<1)tt.set(1,t.right[c]+1,(n<<1)-1);
				c=t.dad[c];
			}
			j=d=t.dis(c,i);
		}
		if(d==j)tt.add(t.id[i]);
		printf("%d\n",tt.t[1].s);
	}
	return 0;
}