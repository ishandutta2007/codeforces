#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=55;
int n,a[N][N]={},p[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			p[i]=max(a[i][j],p[i]);
			p[j]=max(a[i][j],p[j]);
		}
	for(int i=1;i<=n;++i)
		if(p[i]==n-1)
		{
			p[i]=n;
			break;
		}
	for(int i=1;i<=n;++i)
		cout<<p[i]<<' ';
	cout<<endl;
	return 0;
}