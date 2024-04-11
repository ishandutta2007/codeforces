#include<cstdio>
const int N=35005,K=55;
inline int max(int a,int b){
	return a>b?a:b;
}
struct segtree{
	struct node{
		int l,r,ma,add;
	}t[N<<4];
	void build(int i,int l,int r){
		t[i].l=l;
		t[i].r=r;
		if(l==r)return;
		int m=(l+r)>>1;
		build(i<<1,l,m);
		build(i<<1|1,m+1,r);
	}
	inline void pushdown(int i){
		if(t[i].add){
			t[i<<1].add+=t[i].add;
			t[i<<1|1].add+=t[i].add;
			t[i].ma+=t[i].add;
			t[i].add=0;
		}
	}
	inline void merge(int i){
		t[i].ma=max(t[i<<1].ma+t[i<<1].add,t[i<<1|1].ma+t[i<<1|1].add);
	}
	void add(int i,int l,int r){
		if(t[i].l==l && t[i].r==r){
			++t[i].add;
			return;
		}
		pushdown(i);
		int m=(t[i].l+t[i].r)>>1;
		if(l>m)add(i<<1|1,l,r);
			else if(r<=m)add(i<<1,l,r);
					else add(i<<1,l,m),add(i<<1|1,m+1,r);
		merge(i);
	}
	void setv(int i,int l,int v){
		if(t[i].l==l && t[i].r==l){
			t[i].ma=v;
			t[i].add=0;
			return;
		}
		pushdown(i);
		int m=(t[i].l+t[i].r)>>1;
		if(l>m)setv(i<<1|1,l,v);
			else setv(i<<1,l,v);
		merge(i);
	}
	inline int query(){
		t[1].ma+=t[1].add;
		t[1].add=0;
		return t[1].ma;
	}
	int ask(int i,int l){
		if(t[i].l==l && t[i].r==l){
			t[i].ma+=t[i].add;
			t[i].add=0;
			return t[i].ma;
		}
		pushdown(i);
		if(l>(t[i].l+t[i].r)>>1)return ask(i<<1|1,l);	
			else return ask(i<<1,l);
	}
	void clear(int i){
		t[i].ma=t[i].add=0;
		if(t[i].l<t[i].r)clear(i<<1),clear(i<<1|1);
	}
}t;
int ff[2][N],a[N],i,j,k,w,n,b[N],lst[N],*f,*g,*tt;
int main(){
	scanf("%d%d",&n,&k);
	t.build(1,1,n);
	for(i=1;i<=n;++i)scanf("%d",a+i),lst[i]=b[a[i]],b[a[i]]=i;
	g=ff[1];
	for(i=1;i<=n;++i)g[i]=g[i-1]+!lst[i];
	f=ff[0];
	for(i=2;i<=k;++i){
		t.clear(1);
		t.setv(1,1,g[i-1]);
		for(j=i;j<=n;++j){
			if(lst[j]<i)t.add(1,1,j-i+2);
				else t.add(1,lst[j]-i+2,j-i+2);
			f[j]=t.query();
			t.setv(1,j-i+2,g[j]);
		}
		tt=f;
		f=g;
		g=tt;
	}
	printf("%d\n",g[n]);
	return 0;
}