#include<cstdio>

using namespace std;

typedef unsigned long long ull;

const ull C[2]={998244353,1000000007};

int n;
char S[1<<20];

ull HASH[2][20][1<<20];
ull pw[2][1<<20];

int cmp(int x,int y)
// -1: x < y
// 0: x = y
// 1: x > y
{
	if(HASH[0][n][x]==HASH[0][n][y]&&HASH[1][n][x]==HASH[1][n][y])return 0;
	for(int j=n-1;j>=0;j--)
	{
		if(HASH[0][j][x]==HASH[0][j][y]&&HASH[1][j][x]==HASH[1][j][y])x^=(1<<j),y^=(1<<j);
	}
	return S[x]<S[y]?-1:1;
}

int main()
{
	
	scanf("%d%s",&n,S);
	pw[0][0]=pw[1][0]=1;for(int j=0;j<2;j++)for(int i=1;i<(1<<n);i++)pw[j][i]=pw[j][i-1]*C[j];
	for(int i=0;i<(1<<n);i++)HASH[0][0][i]=HASH[1][0][i]=S[i]*S[i];
	
	for(int k=0;k<2;k++)
	for(int j=1;j<=n;j++)
	{
		for(int i=0;i<(1<<n);i++)
		{
			HASH[k][j][i]=HASH[k][j-1][i]+HASH[k][j-1][i^(1<<(j-1))]*pw[k][1<<(j-1)];
		}
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		if(cmp(ans,i)>0)ans=i;
	}
	for(int i=0;i<(1<<n);i++)putchar(S[ans^i]);
}