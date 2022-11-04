#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int bit[55],f[55][3][3];
int n,m,ans,to[5];
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233; 
}
int main(){
	scanf("%d%d",&n,&m);
	bit[0]=1;
	for (int i=1;i<=n;i++)
		bit[i]=bit[i-1]*2%mo;
	f[0][0][0]=1;
	to[0]=to[2]=1; to[1]=2;
	for (int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		for (int j=0;j<=2;j++)
			for (int k=0;k<=2;k++){
				if (!f[i][j][k]) continue;
				if (x!=1){
					if (!k)
						upd(f[i+1][to[j]][k],1ll*f[i][j][k]*bit[i]%mo);
					else{
						upd(f[i+1][to[j]][k],1ll*f[i][j][k]*bit[i-1]%mo);
						upd(f[i+1][j][k],1ll*f[i][j][k]*bit[i-1]%mo);
					}
				}
				if (x!=0){
					if (!j)
						upd(f[i+1][j][to[k]],1ll*f[i][j][k]*bit[i]%mo);
					else{
						upd(f[i+1][j][to[k]],1ll*f[i][j][k]*bit[i-1]%mo);
						upd(f[i+1][j][k],1ll*f[i][j][k]*bit[i-1]%mo);
					}
				}
			}
	}
	for (int i=0;i<=2;i++)
		for (int j=0;j<=2;j++)
			if ((i+j+m)%2==0)
				upd(ans,f[n][i][j]);
	printf("%d",ans);
}