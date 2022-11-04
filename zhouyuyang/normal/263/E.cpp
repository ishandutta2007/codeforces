#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
#define ll long long
int n,m,k;
ll a[1005][1005];
ll s1[1005][1005];
ll s2[1005][1005];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) For(j,1,m) scanf("%lld",&a[i][j]);
	For(i,1,n) For(j,1,m) a[i][j]+=a[i-1][j];
	For(i,1,n) For(j,1,m) a[i][j]+=a[i][j-1];
	For(i,1,n) For(j,1,m) s1[i][j]=a[i][j]+s1[i-1][j-1];
	for (int i=n;i>=k;i--) For(j,k,m) s1[i][j]-=s1[i-k][j-k];
	For(i,1,n) for (int j=m;j>=0;j--) s2[i][j]=a[i][j]+s2[i-1][j+1];
	for (int i=n;i>=k;i--) For(j,0,m-k+1) s2[i][j]-=s2[i-k][j+k];
	ll ans=0; int x=0,y=0;
	For(i,k,n-k+1) For(j,k,m-k+1){
		ll val=s2[i+k-1][j]+s2[i-1][j-k]-s1[i+k-1][j-1]-s1[i-1][j+k-1];
		if (val>=ans) ans=val,x=i,y=j;
	}
	printf("%d %d\n",x,y);
}