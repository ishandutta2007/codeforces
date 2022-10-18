#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,m,h,a[N],b[N],c[N][N],A[N][N];
int main()
{
	cin>>n>>m>>h;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(c[i][j])
				A[i][j]=min(b[i],a[j]);
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=m;j++)
			cout<<A[i][j]<<" ";
	return 0;
}