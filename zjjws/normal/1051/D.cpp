#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=998244353;
LL f[2][4][2010];
int main(){
	
	int i,j,l,x;
	int n,k;
	
	cin>>n>>k;
	
	f[1][0][1]=f[1][1][2]=f[1][2][2]=f[1][3][1]=1;
	
	bool bj=1;
	for(i=2;i<=n;i++)
	{
		bj=!bj;
		memset(f[bj],0,sizeof(f[bj]));
		f[bj][0][1]=f[bj][3][1]=1;
		for(j=2;j<=i*2;j++)
		{
			f[bj][0][j]=f[!bj][0][j]+f[!bj][1][j]+f[!bj][2][j]+f[!bj][3][j-1];
			f[bj][0][j]%=MAX;
			f[bj][1][j]=f[!bj][0][j-1]+f[!bj][1][j]+f[!bj][2][j-2]+f[!bj][3][j-1];
			f[bj][1][j]%=MAX;
			f[bj][2][j]=f[!bj][0][j-1]+f[!bj][1][j-2]+f[!bj][2][j]+f[!bj][3][j-1];
			f[bj][2][j]%=MAX;
			f[bj][3][j]=f[!bj][0][j-1]+f[!bj][1][j]+f[!bj][2][j]+f[!bj][3][j];
			f[bj][3][j]%=MAX;
		}
	}
	LL ans=0;
	for(i=0;i<4;i++)
	ans=(ans+f[bj][i][k])%MAX;
	
	cout<<ans;
	return 0;
}