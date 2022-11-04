#include<bits/stdc++.h>
#define N 500005
#define top 500000
using namespace std;
int sum[N*8];
int mn1[N*8];
int mn2[N*8];
int n,ans;
void build(int k,int l,int r){
	//printf("%d %d %d\n",k,l,r);
	mn1[k]=mn2[k]=1e9;
	if (l==r) return;
	int mid=((l+r)>>1);
	build(k*2,l,mid);
	build(k*2+1,mid+1,r); 
}
void change(int k,int l,int r,int v){
	if (l==r){
		sum[k]++;
		mn1[k]=l+1;
		mn2[k]=l-sum[k];
		return;
	}
	int mid=(l+r)>>1;
	if (v<=mid)
		change(k*2,l,mid,v);
	else
		change(k*2+1,mid+1,r,v);
	sum[k]=sum[k*2]+sum[k*2+1];
	mn1[k]=min(mn1[k*2],mn1[k*2+1]+sum[k*2]);
	mn2[k]=min(mn2[k*2],mn2[k*2+1]-sum[k*2]);
}
int qsum(int k,int l,int r,int x,int y){
	if (x>y) return 0;
	if (l==x&&r==y)
		return sum[k];
	int mid=(l+r)>>1;
	if (y<=mid)
		return qsum(k*2,l,mid,x,y);
	if (x>mid)
		return qsum(k*2+1,mid+1,r,x,y);
	return qsum(k*2,l,mid,x,mid)+qsum(k*2+1,mid+1,r,mid+1,y);
}
int ask1(int k,int l,int r,int v){
	if (l==r)
		return min(-l,v+sum[k]);
	int mid=(l+r)>>1;
	if (v+mn1[k*2+1]+sum[k*2]<=0)
		return ask1(k*2+1,mid+1,r,v+sum[k*2]);
	return ask1(k*2,l,mid,v);
}
int ask2(int k,int l,int r,int x,int y){
	if (x>y) return 1e9;
	if (l==x&&r==y)
		return mn2[k];
	int mid=(l+r)>>1;
	if (y<=mid)
		return ask2(k*2,l,mid,x,y);
	if (x>mid)
		return ask2(k*2+1,mid+1,r,x,y)-sum[k*2];
	return min(ask2(k*2,l,mid,x,mid),
			   ask2(k*2+1,mid+1,r,mid+1,y)-sum[k*2]);
}
int main(){
	scanf("%d",&n);
	build(1,-top,top);
	for (int i=1;i<=n;i++){
		int x,l,r=top;
		scanf("%d",&x);
		change(1,-top,top,x);
		if (mn1[1]>0) l=1;
		else l=-ask1(1,-top,top,0)+1;
		int s=qsum(1,-top,top,l,r);
		int ans=l-1+s;
		if (l<=r)
			ans=min(ans,ask2(1,-top,top,l,r)+i);
		printf("%d\n",ans);
	}
}