#include<bits/stdc++.h>
#define mo 1000000007
#define N 55
using namespace std;
int f[N][N],g[N][N],h[N][N];
int n,m,inv[N*5];
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d%d",&n,&m);
	inv[1]=1;
	for (int i=2;i<=n+m;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	f[0][1]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i+1;j++){
			for (int p=0;p<i;p++){
				for (int q=j;q<=p+1;q++)
					upd(g[i][j],1ll*f[p][q]*f[i-p-1][j]%mo);
				for (int q=j+1;q<=i-p;q++)
					upd(g[i][j],1ll*f[p][j]*f[i-p-1][q]%mo);
			}
			memset(h,0,sizeof(h));
			for (int p=0;p+i<=n;p++)
				for (int q=1;q+j<=n+1;q++){
					int C=1;
					for (int t=1;p+i*t<=n&&q+i*t<=n+1;t++){
						C=1ll*C*(g[i][j]+t-1)%mo*inv[t]%mo;
						upd(h[p+i*t][q+j*t],1ll*C*f[p][q]%mo);
					}
				}
			for (int p=i;p<=n;p++)
				for (int q=j;q<=p+1;q++)
					upd(f[p][q],h[p][q]);
		}
	printf("%d",f[n][m]);
}