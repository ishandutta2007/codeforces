#include<bits/stdc++.h>
#define ll long long
#define N 200001
#define M 20000005
using namespace std;

int n,m,trtot,rt[N],ls[M],rs[M];
ll a[M],b[M],A,B;
void ins(int p,int &k,int l,int r,int x,int y,int u,int v){
	k=++trtot;
	ls[k]=ls[p]; rs[k]=rs[p];
	a[k]=a[p]; b[k]=b[p];
	if (x<=l && r<=y){
		a[k]+=u; b[k]+=v; return;
	}
	int mid=l+r>>1;
	if (x<=mid) ins(ls[p],ls[k],l,mid,x,y,u,v);
	if (y>mid) ins(rs[p],rs[k],mid+1,r,x,y,u,v);
}
void qry(int k,int l,int r,int x,int flag){
	A+=a[k]*flag; B+=b[k]*flag;
	if (l==r) return;
	int mid=l+r>>1;
	if (x<=mid) qry(ls[k],l,mid,x,flag);
		else qry(rs[k],mid+1,r,x,flag);
}
int main(){
	scanf("%d",&n);
	int i,l,r,x,y,u,v;
	for (i=1; i<=n; i++){
		scanf("%d%d%d%d%d%d",&l,&r,&x,&u,&v,&y);
		ins(rt[i-1],rt[i],0,N,0,l,0,x);
		ins(rt[i],rt[i],0,N,l+1,r,u,v);
		ins(rt[i],rt[i],0,N,r+1,N,0,y);
	}
	scanf("%d",&m);
	ll ans=0;
	while (m--){
		scanf("%d%d%d",&l,&r,&x);
		x=(x+ans)%1000000000;
		A=B=0;
		qry(rt[r],0,N,min(x,N),1);
		qry(rt[l-1],0,N,min(x,N),-1);
		printf("%lld\n",ans=A*x+B);
	}
	return 0;
}