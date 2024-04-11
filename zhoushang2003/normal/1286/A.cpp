#include<bits/stdc++.h>
using namespace std;
const int N=101,I=1e9;
int n,a[N],f[N][N][N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<=n;k++)
				f[i][j][k]=I;
	f[0][0][0]=f[0][1][0]=0;
	for(int i=1;i<=n;i++)
		if(a[i])
			for(int j=0;j<n;j++)
				f[i][a[i]%2][j+(a[i]%2==0)]=min(f[i-1][0][j]+(a[i]%2==1),f[i-1][1][j]+(a[i]%2==0));
		else
			for(int j=0;j<n;j++)
				f[i][0][j+1]=min(f[i-1][0][j],f[i-1][1][j]+1),f[i][1][j]=min(f[i-1][0][j]+1,f[i-1][1][j]);
	cout<<min(f[n][0][n/2],f[n][1][n/2]);
	return 0;
}