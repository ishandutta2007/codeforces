#include<bits/stdc++.h>
#define N 300005
using namespace std;
int n,x,tg[N*4],mx[N*4];
void pushdown(int k){
	tg[k*2]+=tg[k]; tg[k*2+1]+=tg[k];
	mx[k*2]+=tg[k]; mx[k*2+1]+=tg[k];
	tg[k]=0;
}
void add(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		tg[k]+=v; mx[k]+=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) add(k*2,l,mid,x,y,v);
	else if (x>mid) add(k*2+1,mid+1,r,x,y,v);
	else add(k*2,l,mid,x,mid,v),add(k*2+1,mid+1,r,mid+1,y,v);
	mx[k]=max(mx[k*2],mx[k*2+1]);
}
int main(){
	scanf("%d",&n);
	printf("1");
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		add(1,1,n,x,n,1);
		add(1,1,n,x,x,-1e9);
		printf(" %d",max(mx[1],0)+1);
	}
}