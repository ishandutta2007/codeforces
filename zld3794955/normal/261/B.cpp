#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=55,P=55;
int n,p,a[N]={},t[N]={};
double v[N][P]={},C[N][N]={},d[N]={1};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		++t[a[i]];
	}
	scanf("%d",&p);
	for(int i=1;i<=n;++i)
		d[i]=d[i-1]*i;
	for(int i=0;i<=n;++i)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	double ans=0;
	for(int s=1;s<=n;++s)
	{
		for(int i=0;i<N;++i)
			for(int j=0;j<P;++j)
				v[i][j]=0;
		v[0][0]=1;
		--t[a[s]];
		for(int i=1;i<=p;++i)
			for(int j=n-1;j>=1;--j)
				for(int k=p;k>=0;--k)
					for(int l=1;j-l>=0 && k-l*i>=0 && l<=t[i];++l)
						v[j][k]+=v[j-l][k-l*i]*C[t[i]][l];
		for(int i=0;i<n;++i)
			for(int j=0;j<=p-a[s];++j)
				ans+=v[i][j]*d[i]*d[n-i-1]/d[n];
		++t[a[s]];/*
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<=p;++j)
				cout<<v[i][j]<<' ';
			cout<<endl;
		}
		cout<<"ans="<<ans<<endl;*/
	}
	printf("%.12f\n",ans);
	return 0;
}