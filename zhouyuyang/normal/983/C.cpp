#include<bits/stdc++.h>
using namespace std;
int f[2][10][10][10][10][10];
int a[2005],b[2005],n;
void upd(int &x,int y){
	x>y?x=y:233;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	memset(f,63,sizeof(f));
	int c=0;
	f[0][0][0][0][0][1]=0;
	for (int i=1;i<=n+1;i++,c^=1){
		memset(f[c^1],63,sizeof(f[c^1]));
		for (int j=9;j>=0;j--)
			for (int k=9;k>=0;k--)
				for (int l=9;l>=0;l--)
					for (int m=9;m>=0;m--)
						for (int at=1;at<=9;at++){
							if (!j) upd(f[c^1][b[i]][k][l][m][a[i]],f[c][j][k][l][m][at]+abs(at-a[i]));
							else upd(f[c][0][k][l][m][j],f[c][j][k][l][m][at]+abs(at-j));
							if (!k) upd(f[c^1][j][b[i]][l][m][a[i]],f[c][j][k][l][m][at]+abs(at-a[i]));
							else upd(f[c][j][0][l][m][k],f[c][j][k][l][m][at]+abs(at-k));
							if (!l) upd(f[c^1][j][k][b[i]][m][a[i]],f[c][j][k][l][m][at]+abs(at-a[i]));
							else upd(f[c][j][k][0][m][l],f[c][j][k][l][m][at]+abs(at-l));
							if (!m) upd(f[c^1][j][k][l][b[i]][a[i]],f[c][j][k][l][m][at]+abs(at-a[i]));
							else upd(f[c][j][k][l][0][m],f[c][j][k][l][m][at]+abs(at-m));
						}
	}
	int ans=1e9;
	for (int i=1;i<=9;i++)
		upd(ans,f[c^1][0][0][0][0][i]);
	printf("%d",ans+2*n);
}