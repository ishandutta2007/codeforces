#import<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,m,a[N],b[N],c[N],f[N][N]; 
main()
{
	cin>>n>>m,m+=n;
	for(int i=n;i;i--)
		cin>>a[i];
	for(int i=n;i;i--)
		cin>>b[i];
	memset(f,0xaf,sizeof(f));
	for(int i=1;i<=m;i++)
		cin>>c[i],f[i][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j;j--)
			f[a[i]][j]=max(f[a[i]][j],f[a[i]][j-1]+c[a[i]]-b[i]);
		for(int j=a[i];j<=m;j++)
			for(int k=0;k<=n>>(j-a[i]);k++)
				f[j+1][k/2]=max(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
	}
	cout<<f[m][0];
}