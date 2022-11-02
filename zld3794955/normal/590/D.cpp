#include<bits/stdc++.h>
using namespace std;
const int N=155,V=N*N/2,Inf=1<<30;
int n,k,s,a[N]={},f[N][V]={};
void init()
{
	scanf("%d%d%d",&n,&k,&s);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
void work()
{
	if(s>=n*(n-1)/2)
	{
		nth_element(a+1,a+k,a+n+1);
		printf("%d\n",accumulate(a+1,a+k+1,0));
		return;
	}
	for(int i=0;i<=k;++i)
		for(int j=0;j<=s;++j)
			f[i][j]=Inf;
	f[0][s]=0;
	for(int i=1;i<=n;++i)
		for(int j=min(k,i);j>=1;--j)
			for(int l=s-i+j;l>=0;--l)
				f[j][l]=min(f[j-1][l+i-j]+a[i],f[j][l]);
	int ans=Inf;
	for(int i=0;i<=s;++i)
		ans=min(ans,f[k][i]);
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}