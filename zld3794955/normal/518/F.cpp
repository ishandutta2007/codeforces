#include<bits/stdc++.h>
using namespace std;
const int N=2020,M=2020;
int n,m,u[N][M]={},d[N][M]={},l[N][M]={},r[N][M]={};
long long ans=0;
char ch[N][M]={};
void init()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s\n",ch[i]+1);
	for(int i=0;i<=n+1;++i)
		l[i][0]=r[i][m+1]=1;
	for(int j=0;j<=m+1;++j)
		u[0][j]=d[n+1][j]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			l[i][j]=l[i][j-1] && ch[i][j]!='#';
			u[i][j]=u[i-1][j] && ch[i][j]!='#';
		}
	for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
		{
			r[i][j]=r[i][j+1] && ch[i][j]!='#';
			d[i][j]=d[i+1][j] && ch[i][j]!='#';
		}
}
void turn0()
{
	for(int i=2;i<n;++i)
		ans+=l[i][m];
	for(int j=2;j<m;++j)
		ans+=u[n][j];
	//cout<<"ans="<<ans<<endl;
}
void turn1()
{
	for(int i=2;i<n;++i)
		for(int j=2;j<m;++j)
		{
			ans+=(l[i][j] && u[i][j]);
			ans+=(l[i][j] && d[i][j]);
			ans+=(r[i][j] && u[i][j]);
			ans+=(r[i][j] && d[i][j]);
		}
	//cout<<"ans="<<ans<<endl;
}
void turn2()
{
	for(int i=2;i<n;++i)
	{
		int s=0;
		for(int j=2;j<m;++j)
		{
			if(ch[i][j]=='#')
			{
				s=0;
				continue;
			}
			int t=d[i][j]+u[i][j];
			ans+=s*t;
			s+=t;
		}
		for(int j=3;j<m;++j)
			ans-=d[i][j-1]*d[i][j] + u[i][j-1]*u[i][j];
	}
	//cout<<"ans="<<ans<<endl;
	for(int j=2;j<m;++j)
	{
		int s=0;
		for(int i=2;i<n;++i)
		{
			if(ch[i][j]=='#')
			{
				s=0;
				continue;
			}
			int t=l[i][j]+r[i][j];
			ans+=s*t;
			s+=t;
		}
		for(int i=3;i<n;++i)
			ans-=l[i-1][j]*l[i][j] + r[i-1][j]*r[i][j];
	}
}
int main()
{	
	init();
	turn0();
	turn1();
	turn2();
	cout<<ans<<endl;
	return 0;
}