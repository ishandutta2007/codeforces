#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,d,a[N],dp[N];
int v[N<<1];
int query(int rt,int L,int R,int xL,int xR){
	if (R<xL||L>xR||xL>xR)
		return 0;
	if (xL<=L&&R<=xR)
		return v[rt];
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	return query(ls,L,mid,xL,xR)|query(rs,mid+1,R,xL,xR);
}
void update(int rt,int L,int R,int x,int d){
	v[rt]|=d;
	if (L==R)
		return;
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		update(ls,L,mid,x,d);
	else
		update(rs,mid+1,R,x,d);
}
int main(){
	scanf("%d%d%d",&n,&k,&d);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	memset(v,0,sizeof v);
	update(1,0,n,0,1);
	for (int i=1;i<=n;i++){
		int p=i;
		for (int j=18;j>=0;j--)
			if (p-(1<<j)>0&&a[i]-a[p-(1<<j)]<=d)
				p-=1<<j;
		dp[i]=query(1,0,n,p-1,i-k);
		update(1,0,n,i,dp[i]);
	}
	puts(dp[n]?"YES":"NO");
	return 0;
}