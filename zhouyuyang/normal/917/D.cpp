#include<bits/stdc++.h>
#define mo 1000000007
#define N  105
using namespace std;
int n,X[N],Y[N];
int v[N],a[N][N];
int f[N],g[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int det(int n){
	int ans=1;
	for (int i=1;i<=n;i++){
		int d=0;
		for (int j=i;j<=n;j++)
			if (a[j][i]) d=j;
		if (!d) return 0;
		if (d^i){
			ans=mo-ans;
			for (int k=1;k<=n;k++)
				swap(a[d][k],a[i][k]);
		}
		int V=power(a[i][i],mo-2);
		for (int j=i+1;j<=n;j++)
			if (a[j][i]){
				int w=1ll*a[j][i]*V%mo;
				for (int k=1;k<=n;k++)
					a[j][k]=(a[j][k]+mo-1ll*w*a[i][k]%mo)%mo;
			}
	}
	for (int i=1;i<=n;i++)
		ans=1ll*ans*a[i][i]%mo;
	return ans;
}
int calc(int x){
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=(i==j?n-1:mo-1);
	for (int i=1;i<n;i++){
		a[X[i]][Y[i]]=(a[X[i]][Y[i]]+1+mo-x)%mo;
		a[Y[i]][X[i]]=(a[Y[i]][X[i]]+1+mo-x)%mo;
		a[X[i]][X[i]]=(a[X[i]][X[i]]+mo+x-1)%mo;
		a[Y[i]][Y[i]]=(a[Y[i]][Y[i]]+mo+x-1)%mo;
	}
	return det(n-1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++)
		scanf("%d%d",&X[i],&Y[i]);
	for (int i=0;i<=n;i++)
		v[i]=calc(i);
	for (int i=0;i<=n;i++){
		int x=1;
		for (int j=0;j<=n;j++)
			if (i!=j)
				x=1ll*x*(i-j+mo)%mo;
		memset(g,0,sizeof(g));
		g[0]=1ll*power(x,mo-2)*v[i]%mo;
		for (int j=0;j<=n;j++)
			if (i!=j){
				int tmp=mo-j;
				for (int k=n;k>=0;k--){
					g[k]=1ll*g[k]*tmp%mo;
					if (k) g[k]=(g[k]+g[k-1])%mo;
				}
			}
		for (int j=0;j<=n;j++)
			f[j]=(f[j]+g[j])%mo;
	}
	for (int i=0;i<n;i++)
		printf("%d ",f[i]);
}