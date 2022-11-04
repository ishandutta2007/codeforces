#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100005
#define ll long long
using namespace std;
struct Lzh{
	ll sum;int mx;
}t[N*4];
int n,m,fl,l,r,x,a[N];
void pushup(int k){
	t[k].sum=t[k*2].sum+t[k*2+1].sum;
	t[k].mx=max(t[k*2].mx,t[k*2+1].mx);
}
void build(int k,int l,int r){
	if (l==r){
		t[k].mx=t[k].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x,int v){
	if (l==r){
		t[k].mx=t[k].sum=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,v);
	else change(k*2+1,mid+1,r,x,v);
	pushup(k);
}
void mod(int k,int l,int r,int x,int y,int v){
	if (t[k].mx<v) return;
	if (l==r){
		t[k].mx%=v; t[k].sum%=v;
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) mod(k*2,l,mid,x,y,v);
	else if (x>mid) mod(k*2+1,mid+1,r,x,y,v);
	else mod(k*2,l,mid,x,mid,v),mod(k*2+1,mid+1,r,mid+1,y,v);
	pushup(k);
}
ll ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k].sum;
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while (m--){
		scanf("%d%d%d",&fl,&l,&r);
		if (fl==1) printf("%lld\n",ask(1,1,n,l,r));
		else if (fl==2) scanf("%d",&x),mod(1,1,n,l,r,x);
		else change(1,1,n,l,r);
	} 
}