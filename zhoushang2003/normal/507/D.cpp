#include<bits/stdc++.h>
using namespace std;
const int N=1001,M=10,K=100;
long long n,m,D,t=1,f[N][M][K],A;
long long P(long long a,long long b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
int main()
{
	cin>>n>>m>>D;
	for(int i=1;i<M;i++)
		if(i%m!=0)
			f[1][i][i%m]=1;
	for(int i=1;i<n;i++)
	{
		(t*=10)%=m;
		for(int j=1;j<M;j++)
			if(t*j%m!=0)
				f[i+1][j][t*j%m]=1;
		for(int j=0;j<M;j++)
			for(int k=1;k<m;k++)
				for(int l=0;l<M;l++)
					if((t*l+k)%m!=0)
						(f[i+1][l][(t*l+k)%m]+=f[i][j][k])%=D;
	}
	for(int i=1;i<M;i++)
		for(int j=1;j<m;j++)
			(A+=f[n][i][j])%=D;
	cout<<(9*P(10,n-1)-A+D)%D;
	return 0;
}