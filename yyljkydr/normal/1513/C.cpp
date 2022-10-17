#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int T,n,m,f[N][10],ans[N][10];

int main()
{
	for(int x=0;x<10;x++)
	{
		memset(f[0],0,sizeof(f[0]));
		f[0][x]=1;
		for(int i=1;i<=200000;i++)
		{
			f[i][0]=f[i-1][9];
			f[i][1]=(f[i-1][0]+f[i-1][9])%P;
			for(int j=2;j<=9;j++)
				f[i][j]=f[i-1][j-1];
			for(int j=0;j<10;j++)
				ans[i][x]=(ans[i][x]+f[i][j])%P;
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		int res=0;
		while(n)
			res=(res+ans[m][n%10])%P,n/=10;
		printf("%d\n",res);
	}
}