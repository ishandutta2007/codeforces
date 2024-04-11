#include<bits/stdc++.h>
#define N 265000
using namespace std;
struct node{
	double l,r;
}t[N];
int n,Q;
node operator +(const node &a,const node &b){
	node c;
	c.l=a.l*b.l/(1-(1-b.l)*a.r);
	c.r=b.r+(1-b.r)*a.r*b.l/(1-(1-b.l)*a.r);
	return c;
}
void build(int k,int l,int r){
	if (l==r){
		int x,y;
		scanf("%d%d",&x,&y);
		t[k]=(node){1.0*x/y,1.0*x/y};
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,double v){
	if (l==r){
		t[k]=(node){v,v};
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	t[k]=t[k*2]+t[k*2+1]; 
}
node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	int n,Q;
	scanf("%d%d",&n,&Q);
	build(1,1,n);
	while (Q--){
		int fl,x,y,z;
		scanf("%d%d%d",&fl,&x,&y);
		if (fl==1){
			scanf("%d",&z);
			change(1,1,n,x,1.0*y/z);
		}
		else
			printf("%.10lf\n",ask(1,1,n,x,y).l);
	}
}