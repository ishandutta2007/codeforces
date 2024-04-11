#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],g[N],pre[N],suf[N];
int find(int l,int r,int x){
	if (l==r) return l;
	int mid=(l+r)>>1;
	return g[mid+1]<=x?find(mid+1,r,x):find(l,mid,x);
}
void lcs(int *d){
	g[0]=0;
	int len=0;
	for (int i=1;i<=m;i++){
		d[i]=find(0,len,a[i])+1;
		if (d[i]>len) g[len=d[i]]=a[i];
		g[d[i]]=min(g[d[i]],a[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		a[l]++; a[r+1]--;
	}
	for (int i=1;i<=m;i++) a[i]+=a[i-1];
	lcs(pre);
	reverse(a+1,a+m+1);
	lcs(suf);
	reverse(suf+1,suf+m+1);
	int ans=0;
	for (int i=1;i<=m;i++) ans=max(ans,suf[i]+pre[i]-1);
	printf("%d\n",ans);
	return 0;
}