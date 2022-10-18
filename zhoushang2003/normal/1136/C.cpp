#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,m,x[N][N],y[N][N],a[N][N],b[N][N],t[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>x[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>y[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i+j][t[i+j]]=x[i][j],b[i+j][t[i+j]++]=y[i][j];
	for(int i=2;i<=n+m;i++)
		sort(a[i],a[i]+t[i]),sort(b[i],b[i]+t[i]);
	for(int i=2;i<=n+m;i++)
		for(int j=0;j<t[i];j++)
			if(a[i][j]!=b[i][j])
			{
				cout<<"NO";
				return 0;
			}
	cout<<"YES";
	return 0;
}