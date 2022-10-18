#include<bits/stdc++.h>
using namespace std;
const int N=61;
bool v;
int T,n,m,c,f[N],g[N],x,y,X,Y;
string s[N];
int main()
{
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>s[i];
		c=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				c+=(s[i][j-1]=='A');
		if(c==0)
		{
			cout<<"MORTAL"<<'\n';
			continue;
		}
		if(c==n*m)
		{
			cout<<0<<'\n';
			continue;
		}
		x=y=X=Y=0;
		for(int i=1;i<=n;i++)
			x+=(s[i][0]=='A'),y+=(s[i][m-1]=='A');
		for(int i=1;i<=m;i++)
			X+=(s[1][i-1]=='A'),Y+=(s[n][i-1]=='A');
		if(x==n||y==n||X==m||Y==m)
		{
			cout<<1<<'\n';
			continue;
		}
		memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				f[i]+=(s[i][j-1]=='A'),g[j]+=(s[i][j-1]=='A');
		v=false;
		for(int i=1;i<=n;i++)
			if(f[i]==m)
				v=true;
		for(int i=1;i<=m;i++)
			if(g[i]==n)
				v=true;
		if(v||s[1][0]=='A'||s[1][m-1]=='A'||s[n][0]=='A'||s[n][m-1]=='A')
		{
			cout<<2<<'\n';
			continue;
		}
		if(x||y||X||Y)
		{
			cout<<3<<'\n';
			continue;
		}
		cout<<4<<'\n';
	}
	return 0;
}