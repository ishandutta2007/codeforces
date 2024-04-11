#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int> in[N],out[N];
int a[N],n,k,tot[N*3];
int sum[N*3],rev[N*3];
long long ans;
void chg(int x){
	rev[x]^=1;
	sum[x]=tot[x]-sum[x];
}
void pushdown(int x){
	if (!rev[x]) return;
	chg(x*2); chg(x*2+1); rev[x]=0;
}
void build(int k,int l,int r){
	tot[k]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void reverse(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return chg(k);
	int mid=(l+r)/2;
	pushdown(k);
	if (y<=mid) reverse(k*2,l,mid,x,y);
	else if (x>mid) reverse(k*2+1,mid+1,r,x,y);
	else reverse(k*2,l,mid,x,mid),reverse(k*2+1,mid+1,r,mid+1,y);
	sum[k]=sum[k*2]+sum[k*2+1];
}
int ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return sum[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=k;i++){
		int L,R; scanf("%d%d",&L,&R);
		L=lower_bound(a+1,a+n+1,L)-a;
		R=upper_bound(a+1,a+n+1,R)-a-1;
		if (L>=1&&L<=n&&R>=1&&R<=n&&L<=R)
			in[L].push_back(R),out[R].push_back(L);
	}
	ans=1ll*n*(n-1)*(n-2)/6ll;
	build(1,1,n);
	for (int i=1;i<=n;i++){
		for (int j=0;j<in[i].size();j++)
			reverse(1,1,n,i,in[i][j]);
		int tmp=0;
		if (i>1) tmp+=i-1-ask(1,1,n,1,i-1);
		if (i<n) tmp+=ask(1,1,n,i+1,n);
		ans-=1ll*tmp*(tmp-1)/2;
		for (int j=0;j<out[i].size();j++)
			reverse(1,1,n,out[i][j],i);
	}
	printf("%lld\n",ans);
}