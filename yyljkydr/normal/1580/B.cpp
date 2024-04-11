#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e2+1e1+7;

int n,m,k,P;

int f[N][N][N],C[N][N];

void inc(int &a,int b)
{
	a+=b;
	a>=P?a-=P:0;
}

signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&P);
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}
	for(int i=0;i<=n+1;i++)
		f[0][0][i]=1;
	for(int d=n+1;d>=2;d--)
		for(int l=0;l<n;l++)
			for(int lj=max(0ll,k+l-n);lj<=min(l,k);lj++)
				if(f[l][lj][d])
					for(int r=0;r<n-l;r++)
						for(int rj=max(0ll,k+l+r-n-lj);rj<=min(r,k-((d-1)==m)-lj);rj++)
							inc(f[l+r+1][lj+rj+((d-1)==m)][d-1],C[l+r][l]*f[l][lj][d]%P*f[r][rj][d]%P);
	// for(int i=1;i<=n;i++)
	// 	for(int j=0;j<=min(i,k);j++)
	// 		for(int t=1;t<=n-m;t++)
	// 		{
	// 			for(int p=1;p<=i;p++)
	// 			{
	// 				int l=p-1,r=i-p;
	// 				for(int lj=0;lj<=j-(t==m);lj++)
	// 				{
	// 					int rj=j-(t==m)-lj;
	// 					inc(f[i][j][t],C[i-1][l]*f[l][lj][t+1]%P*f[r][rj][t+1]%P);
	// 				}
	// 			}
	// 		}
	printf("%lld\n",f[n][k][1]);
}