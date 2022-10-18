#include<bits/stdc++.h>
using namespace std;
const int N=3e5,M=101,I=1e9+1;
struct S
{
	int x,y,i;
};
int T,n,m,a[N],x,y,z,f[N][M],C,V,A[N],t;
vector<S>v[N];
int main()
{
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],v[i].clear();
		for(int i=1;i<=m;i++)
			cin>>x>>y>>z,v[x].push_back({y,z,i});
		t=C=V=0;
		for(int i=1;i<=n;i++)
		{
			if(!v[i].size())
			{
				V=1;
				break;
			}
			for(int j=0;j<v[i].size();j++)
				for(int k=1;k<=100;k++)
					f[j][k]=I;
			f[0][v[i][0].y]=v[i][0].x;
			for(int j=1;j<v[i].size();j++)
				for(int k=0;k<=100;k++)
					f[j][k]=min(f[j][k],f[j-1][k]),x=min(100,k+v[i][j].y),f[j][x]=min(f[j][x],f[j-1][k]+v[i][j].x);
			if((C+=f[v[i].size()-1][x=100])>a[i])
			{
				V=1;
				break;
			}
			for(int j=v[i].size()-1;j;j--)
				for(int k=0;k<=100;k++)
					if(abs(k-x)<=v[i][j].y&&f[j-1][k]+v[i][j].x==f[j][x])
						A[++t]=v[i][j].i,x=k,k=100;
			if(x)
				A[++t]=v[i][0].i;
		}
		if(V)
		{
			puts("-1");
			continue;
		}
		cout<<t<<'\n';
		for(int i=1;i<=t;i++)
			cout<<A[i]<<' ';
		cout<<'\n';
	}
}