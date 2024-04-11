#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,G[2010][2010],x,y,mc,md,used[2010];
ll d[2010];

int main(){
	mc=2e9;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			scanf("%d",&x),G[i][j]=G[j][i]=x,mc=min(mc,x);
	memset(d,62,sizeof d);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			x=(G[i][j]-=mc)*2,G[j][i]-=mc,d[i]=min((ll)x,d[i]),d[j]=min((ll)x,d[j]);
	for (int tim=n;tim--;){
		md=0;
		for (int i=1;i<=n;i++) if (!used[i])
			if (d[i]<d[md]) md=i;
		used[md]=1;
		for (int i=1;i<=n;i++)
			d[i]=min(d[i],d[md]+G[md][i]);
	}
	for (int i=1;i<=n;i++)
		printf("%I64d\n",(ll)mc*(n-1)+d[i]);
}