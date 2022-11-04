#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 101010
using namespace std;
struct node{
	int u[11],d[11],ans,l,r;
}t[N*4];
int a[N][11],f[42],n,m,q,x,v[42],y;
int get(int x){return x==f[x]?x:f[x]=get(f[x]);}
node merge(node x,node y){
	node tmp;
	tmp.l=x.l; tmp.r=y.r;
	tmp.ans=x.ans+y.ans;
	for (int i=1;i<=n;i++){
		f[i]=x.u[i];
		f[i+n]=x.d[i];
		f[i+n*2]=y.u[i]+2*n;
		f[i+n*3]=y.d[i]+2*n;
	}
	for (int i=1;i<=n;i++)
		if (a[x.r][i]==a[x.r+1][i]){
			int p=get(i+n),q=get(i+n*2);
			if (p!=q) f[q]=p,tmp.ans--;
		}
	memset(v,0,sizeof(v));
	for (int i=1;i<=n;i++){
		tmp.u[i]=get(i);
		if (!v[tmp.u[i]]) v[tmp.u[i]]=i;
		tmp.u[i]=v[tmp.u[i]];
		tmp.d[i]=get(i+3*n);
		if (!v[tmp.d[i]]) v[tmp.d[i]]=i+n;
		tmp.d[i]=v[tmp.d[i]];
	}
	return tmp;
}
void build(int k,int l,int r){
	t[k].l=l,t[k].r=r;
	if (l==r){
		t[k].u[1]=t[k].d[1]=t[k].ans=1;
		for (int i=2;i<=n;i++)
			if (a[l][i]==a[l][i-1]) t[k].u[i]=t[k].d[i]=t[k].u[i-1]; 
			else t[k].u[i]=t[k].d[i]=i,t[k].ans++;
		return;
	}
	int m=(l+r)/2;
	build(k*2,l,m);
	build(k*2+1,m+1,r);
	t[k]=merge(t[k*2],t[k*2+1]);
}
node solve(int k,int x,int y){
	int l=t[k].l,r=t[k].r;
	if (l==x&&r==y) return t[k];
	int m=(l+r)/2;
	if (y<=m) return solve(k*2,x,y);
	if (x>m) return solve(k*2+1,x,y);
	return merge(solve(k*2,x,m),solve(k*2+1,m+1,y));
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&a[j][i]);
	build(1,1,m);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",solve(1,x,y).ans);
	}
}