#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 300005
#define bas 314783
#define ull unsigned long long
using namespace std;
int n,x;
ull P[N],sum1,sum2;
struct node{ull a[2];}t[N*4];
void pushup(node &a,node b,node c,int len){
	a.a[0]=b.a[0]*P[len/2]+c.a[0];
	a.a[1]=c.a[1]*P[len-len/2]+b.a[1];
}
void change(int k,int l,int r,int p){
	if (l==r){
		t[k].a[0]=t[k].a[1]=1;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid)  change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	pushup(t[k],t[k*2],t[k*2+1],r-l+1);
}
void ask(int k,int l,int r,int x,int y,ull &hsh){
	if (x<=l&&r<=y){
		hsh=hsh*P[r-l+1]+t[k].a[1];
		return;
	}
	int mid=(l+r)/2;
	if (y>mid) ask(k*2+1,mid+1,r,x,y,hsh);
	if (x<=mid) ask(k*2,l,mid,x,y,hsh);
}
void Ask(int k,int l,int r,int x,int y,ull &hsh){
	if (x<=l&&r<=y){
		hsh=hsh*P[r-l+1]+t[k].a[0];
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) Ask(k*2,l,mid,x,y,hsh);
	if (y>mid) Ask(k*2+1,mid+1,r,x,y,hsh);
}
int main(){
	scanf("%d",&n); P[0]=1;
	for (int i=1;i<=n;i++)
		P[i]=P[i-1]*bas;
	memset(t,0,sizeof(t));
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		change(1,1,n,x);
		int l=min(x-1,n-x);
		if (!l) continue;
		ask(1,1,n,x-l,x-1,sum1=0);
		Ask(1,1,n,x+1,x+l,sum2=0);
		if (sum1!=sum2){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}