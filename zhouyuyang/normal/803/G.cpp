#include<bits/stdc++.h>
#define M 10000005
#define N 200005
using namespace std;
int bit[N],a[N],b[N][18];
int ls[M],rs[M],tg[M],mn[M];
int n,sz,q,k,rt;
int que(int l,int r){
	if (r-l>n) return b[1][bit[2*n]];
	int tmp=(l-1)/n;
	l-=tmp*n; r-=tmp*n;
	tmp=bit[r-l+1];
	return min(b[l][tmp],b[r-(1<<tmp)+1][tmp]);
}
void pushdown(int k){
	if (!tg[k]) return;
	if (!ls[k]) ls[k]=++sz;
	if (!rs[k]) rs[k]=++sz;
	tg[ls[k]]=tg[rs[k]]=tg[k];
	mn[ls[k]]=mn[rs[k]]=tg[k];
	tg[k]=0;
}
void pushup(int k,int l,int r){
	int mid=(l+r)/2;
	int lv=(ls[k]?mn[ls[k]]:que(l,mid));
	int rv=(rs[k]?mn[rs[k]]:que(mid+1,r));
	mn[k]=min(lv,rv);
	//printf("%d %d %d %d %d\n",k,l,r,lv,rs[k]);
}
void update(int &k,int l,int r,int x,int y,int v){
	if (!k) k=++sz;
	if (l==x&&r==y){
		tg[k]=mn[k]=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) update(ls[k],l,mid,x,y,v);
	else if (x>mid) update(rs[k],mid+1,r,x,y,v);
	else update(ls[k],l,mid,x,mid,v),
		 update(rs[k],mid+1,r,mid+1,y,v);
	pushup(k,l,r);
}
int query(int k,int l,int r,int x,int y){
	if (!k) return que(x,y);
	//if (tg[k]) return tg[k];
	if (l==x&&r==y) return mn[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return query(ls[k],l,mid,x,y);
	if (x>mid) return query(rs[k],mid+1,r,x,y);
	return min(query(ls[k],l,mid,x,mid),query(rs[k],mid+1,r,mid+1,y));
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i][0]=b[i+n][0]=a[i];
	}
	for (int i=2;i<=2*n;i++)
		bit[i]=bit[i/2]+1;
	for (int i=1;i<=bit[2*n];i++)
		for (int j=1;j+(1<<i)-1<=2*n;j++)
			b[j][i]=min(b[j][i-1],b[j+(1<<(i-1))][i-1]);
	scanf("%d",&q);
	while (q--){
		int fl,x,y,v;
		scanf("%d%d%d",&fl,&x,&y);
		if (fl==2) printf("%d\n",query(rt,1,n*k,x,y));
		else scanf("%d",&v),update(rt,1,n*k,x,y,v);
	}
}