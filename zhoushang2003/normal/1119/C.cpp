#include<iostream>
using namespace std;
const int N=501;
int n,m,a[N][N],b[N][N],x[N],y[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]^=b[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			x[i]+=a[i][j],y[j]+=a[i][j];
	for(int i=1;i<=n;i++)
		if(x[i]&1)
		{
			cout<<"No";
			return 0;
		}
	for(int i=1;i<=m;i++)
		if(y[i]&1)
		{
			cout<<"No";
			return 0;
		}
	cout<<"Yes";
	return 0;
}