#include<bits/stdc++.h>
const int N=300005;
using namespace std;
int n,v[N],a[N],b[N];
int mn[N],mx[N],g[N];
long long ans;
void work(int *a,int *b){
	int n=a[0],m=b[0],i;
	mn[m+1]=0;
	for (int i=1;i<=m;i++){
		mn[i]=min(mn[i-1],b[i]);
		mx[i]=max(mx[i-1],b[i]);
	}
	int mna=1e9,mxa=0;
	int l=1,r=1;
	for (int i=1;i<=n;i++){
		mna=min(mna,a[i]);
		mxa=max(mxa,a[i]);
		int d=mxa-mna+1-i;
		if (d>0&&d<=m&&mn[d]>mna&&mx[d]<mxa) ans++;
		for (;mn[r]>mna;r++) g[mx[r]-r]++;
		for (;l<r&&mx[l]<mxa;l++) g[mx[l]-l]--;
		ans+=g[mna+i-1];
	}
	for (int i=l;i<r;i++)
		g[mx[i]-i]=0;
}
void solve(int l,int r){
	if (l==r) return;
	int mid=(l+r)/2;
	a[0]=mid-l+1; b[0]=r-mid;
	for (int i=l;i<=mid;i++) a[mid+1-i]=v[i];
	for (int i=mid+1;i<=r;i++) b[i-mid]=v[i];
	work(a,b); work(b,a);
	solve(l,mid); solve(mid+1,r); 
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x]=y;
	}
	mn[0]=1e9;
	solve(1,n);
	printf("%lld\n",ans+n);
}