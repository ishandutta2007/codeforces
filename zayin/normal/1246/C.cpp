#include<bits/stdc++.h>
#define maxn 2050
#define modu 1000000007
using namespace std;
typedef long long LL;

int n,m;
char mp[maxn][maxn];
int cntc[maxn][maxn],cntr[maxn][maxn];

LL dpc[maxn][maxn],dpr[maxn][maxn];
LL sc[maxn][maxn],sr[maxn][maxn];

int main()	{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%s",mp[i]+1);
	
	for (int i=n;i;--i)
		for (int j=m;j;--j)	{
			cntc[i][j]=cntc[i+1][j]+(mp[i][j]=='.');
			cntr[i][j]=cntr[i][j+1]+(mp[i][j]=='.');
		}
	
	for (int j=m;j;--j)
		if (mp[n][j]=='.')
			dpr[n][j]=dpc[n][j]=1;
		else
			break;
	for (int i=n;i;--i)
		if (mp[i][m]=='.')
			dpr[i][m]=dpc[i][m]=1;
		else
			break;
			
	for (int j=m;j;--j)	{
		sc[n][j]=dpr[n][j];
		sr[n][j]=(sr[n][j+1]+dpc[n][j])%modu;
	}
	for (int i=n;i;--i)	{
		sr[i][m]=dpc[i][m];
		sc[i][m]=(sc[i+1][m]+dpr[i][m])%modu;
	}
			
	for (int i=n-1;i;--i)
		for (int j=m-1;j;--j)	{
			//row
			dpr[i][j]=(sr[i+1][j]-sr[i+1][j+cntr[i][j]]+modu)%modu;
			//column
			dpc[i][j]=(sc[i][j+1]-sc[i+cntc[i][j]][j+1]+modu)%modu;
			
			sc[i][j]=(sc[i+1][j]+dpr[i][j])%modu;
			sr[i][j]=(sr[i][j+1]+dpc[i][j])%modu;
		}
//	for (int i=n;i;--i)
//		for (int j=m;j;--j)	{
//			cout<<i<<" "<<j<<" "<<dpc[i][j]<<" "<<dpr[i][j]<<" "<<cntc[i][j]<<" "<<cntr[i][j]<<endl;
//		}
	printf("%lld\n",dpr[1][1]);
	return 0;
}