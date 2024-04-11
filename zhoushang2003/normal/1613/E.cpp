#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,X[]={-1,0,0,1},Y[]={0,-1,1,0};
int t,n,m,x,y,u,v,c;
string s[N];
int C(int x,int y)
{
	return 0<=x&&x<n&&0<=y&&y<m&&s[x][y]=='.';
}
void D(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		u=x+X[i],v=y+Y[i],c=0;
		for(int j=0;j<4;j++)
			c+=C(u+X[j],v+Y[j]);
		if(C(u,v)&&c<2)
			s[u][v]='+',D(u,v);
	}
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(s[i][j]=='L')
					x=i,y=j;
		D(x,y);
		for(int i=0;i<n;i++)
			cout<<s[i]<<'\n';
	}
	return 0;
}