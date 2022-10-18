#include<iostream>
using namespace std;
const int N=1e6+1,M=7;
int n,x,a[N],m,f[N][M][M],t,A;
int main()
{
	cin>>n>>m;
	while(n--&&cin>>x)
		a[x]++;
	for(int i=1;i<=m;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<M;k++)
				f[i][j][k]=-1;
	f[1][0][a[1]%3]=a[1]/3;
	if(a[1]%3+3<M&&a[1]>2)
		f[1][0][a[1]%3+3]=a[1]/3-1;
	if(a[1]%3+6<M&&a[1]>5)
		f[1][0][a[1]%3+6]=a[1]/3-2;
	for(int i=2;i<=m;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<M;k++)
				for(int l=0;l<3;l++)
					if(f[i-1][j][k]!=-1&&a[i]>=l&&j>=l&&k>=l)
					{
						t=a[i]-l;
						f[i][k-l][t%3]=max(f[i][k-l][t%3],f[i-1][j][k]+t/3+l);
						if(t%3+3<M&&t>2)
							f[i][k-l][t%3+3]=max(f[i][k-l][t%3+3],f[i-1][j][k]+t/3-1+l);
						if(t%3+6<M&&t>5)
							f[i][k-l][t%3+6]=max(f[i][k-l][t%3+6],f[i-1][j][k]+t/3-2+l);
					}
	for(int i=1;i<=m;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<M;k++)
				A=max(A,f[i][j][k]);
	cout<<A;
	return 0;
}