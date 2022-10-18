#include<bits/stdc++.h>
using namespace std;
const int M=51;
long long n,t,x,A,f[M][2*M][2],p;
long long S(int a,int b,int c,long long n)
{
	memset(f,0,sizeof(f)),f[0][0][0]=1,p=0;
	for(int i=1;(1ll<<i-1)<=n;i++)
	{
		p=i;
		for(int j=0;j<=c;j++)
			for(int x=0;!x||x<=1&&i<=a;x++)
				for(int y=0;!y||y<=1&&i<=b;y++)
					t=(n>>i-1)&1^x^y,f[i][j+x+y][t+x+y>>1]+=f[i-1][j][t];
	}
	return f[p][c][0];
}
int main()
{
	cin>>n;
	for(int i=0;i<M;i++)
		for(int j=0;j<M;j++)
		{
			t=(1ll<<i+1)+(1ll<<j+1)-3,x=n%t-(1ll<<j)+1;
			for(int k=0;k<=i+j;k++)
				if(t<=n&&x+k>=0&&(x+k)%2==0)
					A+=S(i-1,j-1,k,x+k>>1);
		}
	cout<<A;
	return 0;
}