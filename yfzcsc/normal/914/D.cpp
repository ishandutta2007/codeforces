#include<bits/stdc++.h>
#define maxn 500100
using namespace std;
int g[maxn<<2],cnt;
bool qry(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){
		if(g[o]%x==0)return true;
		if(cnt)return false;
		if(l==r)return cnt=(g[o]%x?l:cnt),true;
		if(g[o<<1]%x&&g[o<<1|1]%x)return false;
		int mid=l+r>>1;
		if(!qry(o<<1,l,mid,ql,qr,x))return false;
		if(!qry(o<<1|1,mid+1,r,ql,qr,x))return false;
		return true;
	}
	int mid=l+r>>1;
	if(ql<=mid&&!qry(o<<1,l,mid,ql,qr,x))return false;
	if(qr>mid&&!qry(o<<1|1,mid+1,r,ql,qr,x))return false;
	return true;
}
void mdy(int o,int l,int r,int k,int x){
	if(l==r){
		g[o]=x;
		return ;
	}
	int mid=l+r>>1;
	if(k<=mid)mdy(o<<1,l,mid,k,x);
	else mdy(o<<1|1,mid+1,r,k,x);
	g[o]=__gcd(g[o<<1],g[o<<1|1]);
}
int a[maxn],n,m;
void build(int o,int l,int r){
	if(l==r){
		g[o]=a[l];
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	g[o]=__gcd(g[o<<1],g[o<<1|1]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1,op,l,r,x;i<=m;++i){
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)scanf("%d",&x),cnt=0,puts(qry(1,1,n,l,r,x)?"YES":"NO");
		else mdy(1,1,n,l,r);
	}
}