#include<bits/stdc++.h>
using namespace std;
const int N=17,M=65536,K=2001;
int n,k,a[N],f[M][K],x,y,z,q[N],t,g[N],v[N];
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	f[0][0]=-2;
	for(int i=0;i<(1<<n);i++)
		for(int j=K-1;j>=0;j--)
			if(f[i][j])
			{
				for(int k=0;k<n;k++)
					if(!(i&(1<<k)))
						f[i|(1<<k)][j+a[k]]=k+1;
				if(j&&j%k==0)
					f[i][j/k]=-1;
			}
	x=(1<<n)-1,y=1;
	if(!f[x][y])
	{
		cout<<"NO";
		return 0;
	}
	while(x)
	{
		while(f[x][y]==-1)
			y*=k,z++;
		q[++t]=f[x][y]-1,g[t]=z,x^=(1<<q[t]),q[t]=a[q[t]],y-=q[t];
	}
	cout<<"YES"<<'\n';
	for(int i=1;i<n;i++)
	{
		x=0;
		vector<int>p;
		for(int j=1;j<=n;j++)
			if(!v[j])
				x=max(x,g[j]);
		for(int j=1;j<=n;j++)
			if(!v[j]&&g[j]==x)
				p.push_back(j);
		x=p[0],y=p[1];
		cout<<q[x]<<' '<<q[y]<<'\n';
		q[x]+=q[y],v[y]=1;
		while(q[x]%k==0)
			q[x]/=k,g[x]--;
	}
	return 0;
}