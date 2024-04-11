#include<bits/stdc++.h>
using namespace std;
const int N=110,M=110;
int n,m,a[N][M]={},s[N][M]={};
char ch[N][M]={};
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>(ch[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=ch[i][j]=='B' ? 1 : -1;
}
void work()
{
	int ans=0;
	for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
			ans+=bool(a[i][j]+a[i+1][j+1]-a[i+1][j]-a[i][j+1]);
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}