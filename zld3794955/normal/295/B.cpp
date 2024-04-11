#include<bits/stdc++.h>
using namespace std;
const int N=505,Inf=1<<30;
int n,f[N][N]={},v[N][N]={},a[N]={};
long long s[N]={};
bool in[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&f[i][j]);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int k=n;k>=1;--k)
	{
		int d=a[k];
		s[k]=s[k+1];
		in[d]=true;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				if(i!=j && (f[i][j]==0 || f[i][d]+f[d][j]<f[i][j]))
					f[i][j]=f[i][d]+f[d][j];
				if(in[i] && in[j])
				{
					s[k]+=f[i][j]-v[i][j];
					v[i][j]=f[i][j];
				}
			}
	}
	for(int k=1;k<=n;++k)
		printf("%I64d ",s[k]);
	printf("\n");
	return 0;
}