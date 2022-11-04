#include<bits/stdc++.h>
#define eps 1e-10
#define N 200005
using namespace std;
int n,m,q;
double p[N];
int a[N],b[N];
struct node{
	double win,lose,ans;
	int w1,w2;
}t[N*4];
node work(int x){
	static node jdb;
	jdb.ans=p[x]*a[x]/(a[x]+b[x]);
	jdb.ans=min(jdb.ans,p[x]/2);
	if (a[x]>=b[x]) jdb.win=0;
	else jdb.win=p[x]*(a[x]+1)/(a[x]+b[x]+1)-p[x]*a[x]/(a[x]+b[x]);
	if (!a[x]) jdb.lose=1e18;
	else if (a[x]>b[x]) jdb.lose=0;
	else jdb.lose=p[x]*a[x]/(a[x]+b[x])-p[x]*(a[x]-1)/(a[x]+b[x]-1);
	jdb.w1=jdb.w2=x;
	return jdb;
}
void pushup(int k){
	t[k].ans=t[k*2].ans+t[k*2+1].ans;
	t[k].win=max(t[k*2].win,t[k*2+1].win);
	if (t[k].win==t[k*2].win) t[k].w1=t[k*2].w1;
	else t[k].w1=t[k*2+1].w1;
	t[k].lose=min(t[k*2].lose,t[k*2+1].lose);
	if (t[k].lose==t[k*2].lose) t[k].w2=t[k*2].w2;
	else t[k].w2=t[k*2+1].w2;
}
void build(int k,int l,int r){
	if (l==r){
		t[k]=work(l);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x){
	if (l==r){
		t[k]=work(l);
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x);
	else change(k*2+1,mid+1,r,x);
	pushup(k);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	build(1,1,n);
	for (int i=1;i<=m;i++){
		int x=t[1].w1;
		a[x]++;
		change(1,1,n,x);
	}
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==1) b[y]++;
		else b[y]--;
		change(1,1,n,y);
		while (t[1].win-t[1].lose>eps){
			x=t[1].w1,y=t[1].w2;
			a[x]++; a[y]--;
			change(1,1,n,x);
			change(1,1,n,y);
		}
		printf("%.10lf\n",t[1].ans);
	}
}