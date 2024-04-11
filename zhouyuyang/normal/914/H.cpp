#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define int long long
using namespace std;
#define N 205
int c[N][N],tr[N][N][N];
int mo,n,d;
signed main(){
	scanf("%lld%lld%lld",&n,&d,&mo);
	For(i,0,n){
		c[i][0]=1;
		For(j,1,i)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	tr[1][1][0]=1;
	/*tr[i][j][k]:ijk*/
	For(i,1,n-1){
		For(j,1,n) For(k,0,d)
			tr[i+1][j][k]=tr[i][j][k];
		int tri=0;
		For(j,0,d-1) tri=(tri+tr[i][i][j])%mo;
		int ways=1;
		For(j,1,min(n/i,d)){//j 
			ways=1ll*ways*c[i*j-1][i-1]%mo;
			For(k,1,n-i*j){//k 
				int cnt=1ll*ways*c[k+i*j-1][k-1]%mo;
				For(deg,0,d-j)
					tr[i+1][k+i*j][deg+j]=(tr[i+1][k+i*j][deg+j]+1ll*cnt*tr[i][k][deg]%mo*tri%mo)%mo;
			}
			ways=1ll*ways*tri%mo;
		} 
	}
	int ans=0;
	For(i,0,n-1) For(j,0,d) For(k,0,d-j)
		if (k!=1) ans=(ans+1ll*tr[n][i+1][j]*tr[n][n-i][k])%mo;
	printf("%lld\n",2ll*n*(n-1)%mo*ans%mo);
}