#include<bits/stdc++.h>
using namespace std;
const int K=20,L=100,N=1e4+2,M=1048576,I=1e9;
bool v[N];
int n,k,l,x[K],a[L],d[N],q[N],s,t,X,g[K][N],h[K],p,f[M];
void R(int x)
{
	if(0<x&&x<=n&&!d[x])
		d[x]=d[X]+1,q[t++]=x;
}
int main()
{
	cin>>n>>k>>l;
	for(int i=0;i<k;i++)
		cin>>x[i];
	for(int i=0;i<l;i++)
		cin>>a[i];
	for(int i=0;i<k;i++)
		v[x[i]]=true;
	for(int i=0;i<=n;i++)
		if(v[i]!=v[i+1])
		{
			memset(d,0,sizeof(d)),s=t=0,q[t++]=i,d[i]=1;
			while(s<t)
			{
				X=q[s++];
				for(int i=0;i<l;i++)
					R(X+a[i]),R(X-a[i]);
			}
			for(int j=0;j<=n;j++)
				if(d[j]>0)
					g[p][j]=d[j]-1;
				else
					g[p][j]=I;
			h[p++]=i;
		}
	for(int i=1;i<1<<p;i++)
		f[i]=I;
	for(int i=0;i<1<<p;i++)
		for(int j=0;j<p;j++)
			if((~i>>j)&1)
				for(int k=j+1;k<p;k++)
					if((~i>>k)&1)
						f[i|(1<<j)|(1<<k)]=min(f[i|(1<<j)|(1<<k)],f[i]+g[j][h[k]]);
	if(f[(1<<p)-1]!=I)
		cout<<f[(1<<p)-1];
	else
		cout<<-1;
	return 0;
}