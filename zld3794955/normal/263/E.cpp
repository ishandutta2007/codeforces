#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1010;
int n,m,k,a[N][M]={};
long long s1[N][M]={},s2[N][M]={},s3[N][M]={},s4[N][M]={};
long long r1[N][M]={},r2[N][M]={},r3[N][M]={},r4[N][M]={};
long long sum[N][M]={};
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n+2;++i)
		for(int j=1;j<=m+2;++j)
		{
			s1[i][j]=s1[i-1][j]+a[i][j];
			s2[i][j]=s2[i][j-1]+a[i][j];
			s3[i][j]=s3[i-1][j-1]+a[i][j];
			s4[i][j]=s4[i-1][j+1]+a[i][j];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(i<=k && j<=k && abs(i-k)+abs(j-k)<k)
				r1[k][k]+=a[i][j];
			if(i<=k && j>=k && abs(i-k)+abs(j-k)<k)
				r2[k][k]+=a[i][j];
			if(i>=k && j<=k && abs(i-k)+abs(j-k)<k)
				r3[k][k]+=a[i][j];
			if(i>=k && j>=k && abs(i-k)+abs(j-k)<k)
				r4[k][k]+=a[i][j];
		}
	for(int j=k+1;j<=m-k+1;++j)
	{
		r1[k][j]=r1[k][j-1]+s1[k][j]-s4[k][j-k];
		r2[k][j]=r2[k][j-1]-s1[k][j-1]+s3[k][j+k-1];
		r3[k][j]=r3[k][j-1]+s1[k+k-1][j]-s1[k-1][j]-s3[k+k-1][j-1]+s3[k-1][j-k-1];
		r4[k][j]=r4[k][j-1]+s4[k+k-1][j]-s4[k-1][j+k]-s1[k+k-1][j-1]+s1[k-1][j-1];
	}
	for(int i=k+1;i<=n-k+1;++i)
		for(int j=k;j<=m-k+1;++j)
		{
			r1[i][j]=r1[i-1][j]+s2[i][j]-s2[i][j-k]-s4[i-1][j-k+1]+s4[i-k-1][j+1];
			r2[i][j]=r2[i-1][j]+s2[i][j+k-1]-s2[i][j-1]-s3[i-1][j+k-1]+s3[i-k-1][j-1];
			r3[i][j]=r3[i-1][j]+s3[i+k-1][j]-s3[i-1][j-k]-s2[i-1][j]+s2[i-1][j-k];
			r4[i][j]=r4[i-1][j]+s4[i+k-1][j]-s4[i-1][j+k]-s2[i-1][j+k-1]+s2[i-1][j-1];
		}
}
void work()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			sum[k][k]+=a[i][j]*max(0,k-abs(i-k)-abs(j-k));
	for(int j=k+1;j<=m-k+1;++j)
		sum[k][j]=sum[k][j-1]-r1[k][j-1]-r3[k][j-1]+r2[k][j]+r4[k][j]
				+s2[k][j-1]-s2[k][j-k-1] -s2[k][j+k-1]+s2[k][j-1];
	for(int i=k+1;i<=n-k+1;++i)
		for(int j=k;j<=m-k+1;++j)
			sum[i][j]=sum[i-1][j]-r1[i-1][j]-r2[i-1][j]+r3[i][j]+r4[i][j]
					+s1[i-1][j]-s1[i-k-1][j] -s1[i+k-1][j]+s1[i-1][j];
	long long ans=0;
	int ansx=k,ansy=k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(sum[i][j]>ans)
				ans=sum[i][j],ansx=i,ansy=j;
	cout<<ansx<<' '<<ansy<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}