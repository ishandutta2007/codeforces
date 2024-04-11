#include<bits/stdc++.h>
#define N 2005
#define ll long long
#define For(i,j,k) for (int i=(j);i<=(k);i++)
using namespace std;
int a[N][N];
ll d[N];
int vis[N];
int n;
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,i+1,n)
		scanf("%d",&a[i][j]);
	int mn=2e9;
	For(i,1,n) For(j,i+1,n)
		mn=min(mn,a[i][j]);
	For(i,1,n) For(j,i+1,n)
		a[j][i]=(a[i][j]-=mn);
	For(i,1,n){
		d[i]=2e15;
		For(j,1,n)
			if (i!=j)
				d[i]=min(d[i],2ll*a[i][j]);
	}
	For(i,1,n){
		ll v=2e15;
		int tmp=-1;
		For(j,1,n)
			if (!vis[j]&&d[j]<v)
				v=d[j],tmp=j;
		vis[tmp]=1;
		For(j,1,n)
			d[j]=min(d[j],d[tmp]+a[tmp][j]);
	}
	For(i,1,n)
		printf("%lld\n",d[i]+1ll*mn*(n-1));
}