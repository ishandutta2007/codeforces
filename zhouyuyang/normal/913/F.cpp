#include<bits/stdc++.h>
#define mo 998244353
#define N 2005
using namespace std;
int win[N][N],sto[N],ans[N],P[N],Q[N];
void upd(int &x,int y){
	x+=y;
	if (x>=mo) x-=mo;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);
	int p=1ll*a*power(b,mo-2)%mo;
	int q=mo+1-p;
	for (int i=P[0]=Q[0]=1;i<=n;i++)
		P[i]=1ll*P[i-1]*p%mo,Q[i]=1ll*Q[i-1]*q%mo;
	win[0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=i;j++){
			upd(win[i+1][j],1ll*win[i][j]*P[j]%mo);
			upd(win[i+1][j+1],1ll*win[i][j]*Q[i-j]%mo);
		}
	for (int i=1;i<=n;i++){
		sto[i]=1;
		for (int j=1;j<i;j++)
			upd(sto[i],mo-1ll*sto[j]*win[i][j]%mo);
	}
	for (int i=2;i<=n;i++){
		for (int j=1;j<i;j++){
			int pos=1ll*sto[j]*win[i][j]%mo;
			int times=(ans[j]+ans[i-j]+j*(j-1)/2+j*(i-j))%mo;
			upd(ans[i],1ll*pos*times%mo);
		}
		upd(ans[i],1ll*i*(i-1)/2*sto[i]%mo);
		ans[i]=1ll*ans[i]*power(mo+1-sto[i],mo-2)%mo; 
	}
	printf("%d",ans[n]);
}