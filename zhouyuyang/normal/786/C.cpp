#include<bits/stdc++.h>
#define M 10000005
#define N 100005
using namespace std;
int a[N],rt[N],la[N],nxt[N];
int ls[M],rs[M],t[M],sz;
int n;
void add(int &k,int la,int l,int r,int p,int v){
	k=++sz; t[k]=t[la]+v;
	ls[k]=ls[la]; rs[k]=rs[la];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) add(ls[k],ls[la],l,mid,p,v);
	else add(rs[k],rs[la],mid+1,r,p,v);
}
int findnext(int k,int l,int r,int v){
	//printf("%d %d %d %d %d %d %d\n",k,t[k],l,r,v,t[ls[k]],t[rs[k]]);
	if (t[k]<=v) return r+1;
	if (l==r) return r;
	int mid=(l+r)/2;
	if (t[ls[k]]>v)
		return findnext(ls[k],l,mid,v);
	return findnext(rs[k],mid+1,r,v-t[ls[k]]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (!la[a[i]])
			add(rt[0],rt[0],1,n,i,1);
		nxt[la[a[i]]]=i;
		la[a[i]]=i;
	}
	nxt[0]=0;
	for (int i=1;i<=n;i++){
		rt[i]=rt[i-1];
		if (i-1)
			add(rt[i],rt[i],1,n,i-1,-1);
		if (nxt[i-1])
			add(rt[i],rt[i],1,n,nxt[i-1],1);
		//printf("%d %d\n",findnext(rt[i],1,n,1),t[rt[i]]);
	}
	for (int i=1;i<=n;i++){
		int j=1,ans=0;
		while (j<=n) j=findnext(rt[j],1,n,i),ans++;
		printf("%d ",ans);
	}
}