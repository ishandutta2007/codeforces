#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,D=1e9+7;
int T,n,m,s,t,x,y,d[N],e[N],f[N],g[N],q[N],l,r,A,B;
vector<int>a[N];
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>m>>s>>t)
	{
		for(int i=1;i<=n;i++)
			a[i].clear(),d[i]=e[i]=f[i]=g[i]=0;
		while(m--&&cin>>x>>y)
			a[x].push_back(y),a[y].push_back(x);
		q[d[s]=f[s]=l=r=1]=s;
		while(l<=r)
		{
			x=q[l++];
			for(int i=0;i<a[x].size();i++)
				if(!d[y=a[x][i]])
					d[y]=d[x]+1,f[y]=f[x],q[++r]=y;
				else if(d[y]==d[x]+1)
					(f[y]+=f[x])%=D;
		}
		q[e[t]=g[t]=l=r=1]=t,A=f[t],B=d[t]+1;
		while(l<=r)
		{
			x=q[l++];
			for(int i=0;i<a[x].size();i++)
				if(!e[y=a[x][i]])
					e[y]=e[x]+1,g[y]=g[x],q[++r]=y;
				else if(e[y]==e[x]+1)
					(g[y]+=g[x])%=D;
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<a[i].size();j++)
				if(d[i]+e[i]==B&&d[i]+e[x=a[i][j]]==B)
					(A+=f[i]*g[x])%=D;
		cout<<A<<'\n';
	}
}