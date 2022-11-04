#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
#define N 2005
using namespace std;
int a[N],t[2][N],f[5][N],n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x); x--;
		t[0][i]=t[0][i-1];
		t[1][i]=t[1][i-1];
		t[x][i]++;
	}
	for (int i=0;i<4;i++)
		for (int j=0;j<=n;j++)
			for (int k=j;k<=n;k++)
				f[i+1][k]=max(f[i+1][k],f[i][j]+t[i&1][k]-t[i&1][j]);
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,f[4][i]);
	printf("%d\n",ans);
}