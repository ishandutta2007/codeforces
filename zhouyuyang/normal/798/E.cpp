#include<bits/stdc++.h>
#define pa pair<int,int>
#define N 500005
using namespace std;
int a[N],b[N];
pa t[1050000];
int vis[N],ans[N];
int n,top;
void build(int k,int l,int r){
	if (l==r){
		t[k]=pa(b[l],l);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=max(t[k*2],t[k*2+1]);
}
void del(int k,int l,int r,int p){
	if (l==r){
		t[k]=pa(0,l);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) del(k*2,l,mid,p);
	else del(k*2+1,mid+1,r,p);
	t[k]=max(t[k*2],t[k*2+1]);
}
pa ask(int k,int l,int r,int x,int y){
	if (x>y) return pa(0,0);
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return max(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
void dfs(int x){
	del(1,1,n,x);
	vis[x]=1;
	if(b[x]!=n+1&&!vis[b[x]])
		dfs(b[x]);
	for (;;){
		pa tmp=ask(1,1,n,1,a[x]-1);
		if (tmp.first>x) dfs(tmp.second);
		else break;
	}
	ans[x]=++top;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) b[i]=n+1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		if (a[i]!=-1) b[a[i]]=i;
		else a[i]=n+1;
	build(1,1,n);
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs(i);
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}