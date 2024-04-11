#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1,X[4]={-1,0,0,1},Y[4]={0,-1,1,0};
int n,m,c,v,x,y,A,p[N*N],q[N*N],t,P,Q,U,V;
string s[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		c=0;
		if(s[i][0]=='#')
			c++;
		for(int j=1;j<m;j++)
			if(s[i][j]!=s[i][j-1])
				c++;
		if(c>2)
			v=1;
		if(c==0)
			x=1;
	}
	for(int i=0;i<m;i++)
	{
		c=0;
		if(s[1][i]=='#')
			c++;
		for(int j=1;j<n;j++)
			if(s[j][i]!=s[j+1][i])
				c++;
		if(c>2)
			v=1;
		if(c==0)
			y=1;
	}
	if(v||x!=y)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='#')
			{
				A++,s[i][j]='.',p[++t]=i,q[t]=j;
				while(t)
				{
					P=p[t],Q=q[t--];
					for(int k=0;k<4;k++)
					{
						U=P+X[k],V=Q+Y[k];
						if(1<=U&&U<=n&&0<=V&&V<m&&s[U][V]=='#')
							s[U][V]='.',p[++t]=U,q[t]=V;
					}
				}
			}
	cout<<A;
	return 0;
}