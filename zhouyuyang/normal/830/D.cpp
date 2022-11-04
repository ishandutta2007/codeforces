#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int n,f[405][805];
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d",&n);
	f[1][0]=f[1][1]=1;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;j+k-1<=n;k++){
				int tmp=1ll*f[i-1][j]*f[i-1][k]%mo;
				if (!tmp) continue;
				upd(f[i][j+k+1],tmp);
				upd(f[i][j+k],1ll*tmp*(2*j+2*k+1)%mo);
				if (j+k) upd(f[i][j+k-1],1ll*tmp*(j+k)*(j+k-1)%mo);
			}
	printf("%d\n",f[n][1]);
}