#include<bits/stdc++.h>
using namespace std;
const int N=101,K=3e4+1;
int n,a[N],b[N],f[2][N][K],t,p,A[N],x,y;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i],a[i]-=b[i],a[i]*=2,b[i]*=2;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=30000;j++)
			f[0][i][j]=-1e9;
	f[0][0][20000]=0;
	for(int i=0;i<n;i++)
	{
		x=i&1,y=1-x;
		for(int j=0;j<=n;j++)
			for(int k=0;k<=30000;k++)
				f[y][j][k]=-1e9;
		for(int j=0;j<=i;j++)
			for(int k=200;k<=29900;k++)
			{
				t=0,p=k-20000;
				if(p<0)
					t=min(-p,b[i+1]/2);
				f[y][j][k+b[i+1]/2]=max(f[y][j][k+b[i+1]/2],f[x][j][k]+t),t=0;
				if(p>0)
					t=min(p,a[i+1]);
				f[y][j+1][k-a[i+1]]=max(f[y][j+1][k-a[i+1]],f[x][j][k]+t+b[i+1]);
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=30000;j++)
			A[i]=max(A[i],f[n&1][i][j]);
	for(int i=1;i<=n;i++)
		cout<<0.5*A[i]<<' ';
	return 0;
}