#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3;
int n,m,a[N],f[N][N];
int S(int l,int r)
{
	if(l>r)
		return 0;
	int k=l;
	for(int i=l;i<=r;i++)
		if(a[i]<a[k])
			k=i;
	int I=S(l,k-1),J=S(k+1,r);
	for(int i=0;i<=k-l;i++)
		for(int j=0;j<=r-k;j++)
			f[k][i+j]=max(f[k][i+j],f[I][i]+f[J][j]-2*i*j*a[k]),f[k][i+j+1]=max(f[k][i+j+1],f[I][i]+f[J][j]+((m-1)-2*(i*j+i+j))*a[k]);
	return k;
}
main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<f[S(1,n)][m];
}