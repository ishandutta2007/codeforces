#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
int getint(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=10010;
struct tree{
	static const int maxn=N;
	int xb;
	struct node{
		int lc,rc,sum,l,r;
	}t[maxn*20];
	void init(int n){
		xb=0;		
	}
	void ins(int l,int r,int x,int&y,int v){
		t[y=++xb].sum=t[x].sum+1;
		t[y].l=l;
		t[y].r=r;
		if(l==r)return;
		int m=(l+r)>>1;
		if(v>m){
			t[y].lc=t[x].lc;
			ins(m+1,r,t[x].rc,t[y].rc,v);
		}else{
			t[y].rc=t[x].rc;
			ins(l,m,t[x].lc,t[y].lc,v);
		}
	}
	int rank(int x,int y,int l,int r,int k){
		if(l==r)return t[y].sum;
		int m=(l+r)>>1;
		if(k>m)return rank(t[x].rc,t[y].rc,m+1,r,k)+t[t[y].lc].sum-t[t[x].lc].sum;
			else return rank(t[x].lc,t[y].lc,l,m,k);
	}
}t;
int n,m,l,r,k,b[N],x,root[N],c[N],a[N],id[N];
int main(){
	scanf("%d%d",&n,&m);
	t.init(n);
	x=0;
	for(l=1;l<=n;++l){
		a[l]=getint();
		id[a[l]]=l;
	}
	for(l=1;l<=n;++l)t.ins(1,n,root[l-1],root[l],a[l]);
	while(m--){
		l=getint();
		r=getint();
		k=getint();
		//printf("%d\n",t.rank(root[l-1],root[r],1,n,a[k]));
		if(t.rank(root[l-1],root[r],1,n,a[k])==k-l+1)puts("Yes");
			else puts("No");
	}
	return 0;
}