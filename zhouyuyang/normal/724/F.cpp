#include<bits/stdc++.h>
using namespace std;
int n,d,mo,ans;
int f[1005][12],inv[12],tmp[12];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d%d",&n,&d,&mo);
	inv[0]=1;
	for (int i=1;i<=d;i++)
		inv[i]=power(i,mo-2);
	f[1][0]=f[1][d-1]=1;
	for (int k=1;k<=n/2;k++)
		if (f[k][d-1]){
			int m=f[k][d-1]; tmp[0]=1;
			for (int l=1;l<=d;l++)
				tmp[l]=1ll*tmp[l-1]*(l+m-1)%mo*inv[l]%mo;
			for (int i=n-k;i;i--)
				for (int j=0;j<d;j++)
					if (f[i][j])
						for (int l=1;i+l*k<=n&&j+l<=d;l++)
							f[i+l*k][j+l]=(f[i+l*k][j+l]+1ll*f[i][j]*tmp[l])%mo;
		}
	ans=(f[n][d]+f[n][0])%mo;
	if (!(n&1)){
		int tmp=f[n/2][d-1];
		ans=(ans+mo-1ll*tmp*(tmp-1)/2%mo)%mo;
	}
	printf("%d\n",ans);
}