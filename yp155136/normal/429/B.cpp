#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int dp1[1002][1002];   //--> 
int dp2[1002][1002];   //--> 
int dp3[1002][1002];   //--> 
int dp4[1002][1002];   //--> 
int a[1002][1002];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		//int a[n][m];
		memset(a,0,sizeof(a));
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(dp3,0,sizeof(dp3));
		memset(dp4,0,sizeof(dp4));
		
		
		for (int x=1;n>=x;x++) {
			for (int y=1;m>=y;y++) {
				scanf("%d",&a[x][y]);
			}
		}
		
		for (int x=1;n>=x;x++) {
			for (int y=1;m>=y;y++) {
				dp1[x][y] = max(dp1[x-1][y],dp1[x][y-1]) + a[x][y];
			}
		}
		
		for (int x=1;n>=x;x++) {
			for (int y=m;y>=1;y--) {
				dp2[x][y] = max(dp2[x-1][y],dp2[x][y+1]) + a[x][y];
			}
		}
		
		for (int x=n;x>=1;x--) {
			for (int y=m;y>=1;y--) {
				dp3[x][y] = max(dp3[x+1][y],dp3[x][y+1]) + a[x][y];
			}
		}
		
		for (int x=n;x>=1;x--) {
			for (int y=1;m>=y;y++) {
				dp4[x][y] = max(dp4[x+1][y],dp4[x][y-1]) + a[x][y];
			}
		}
		
		int ans=0;
		
		for (int i=2;n-1>=i;i++) {
			for (int j=2;m-1>=j;j++) {
				int tmp1 = dp1[i-1][j] + dp2[i][j+1] + dp3[i+1][j] + dp4[i][j-1];
				int tmp2 = dp2[i-1][j] + dp3[i][j+1] + dp4[i+1][j] + dp1[i][j-1];
				int tmp=max(tmp1,tmp2);
				if (tmp>ans) ans=tmp;
			}
		}
		
		printf("%d\n",ans);
		
	}
}