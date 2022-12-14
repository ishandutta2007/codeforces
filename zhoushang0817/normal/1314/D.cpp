#include<bits/stdc++.h>
using namespace std;
const int N=82,I=1e9;
long long v[N],n,K,a[N][N],f[N][N][N],g[N][N][N],p,w[N],A=I,t;
priority_queue<pair<int,int> >q;
void D(int x)
{
	if(!x)
	{
		t=0;
		for(int i=0;i<K;i++)
			for(int j=1;j<=n;j++)
				if(!v[f[w[i]][w[i+1]][j]])
					t+=g[w[i]][w[i+1]][j],j=n;
		A=min(A,t);
		return;
	}
	for(int i=1;i<=n;i++)
		w[x]=i,v[i]++,D(x-1),v[i]--;
}
int main()
{
	cin>>n>>K;
	K/=2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			for(int k=2;k<=n;k++)
				if(k!=i&&k!=j)
					q.push(make_pair(-a[i][k]-a[k][j],k));
			p=0;
			while(!q.empty())
				f[i][j][++p]=q.top().second,g[i][j][p]=-q.top().first,q.pop();
			for(int k=p+1;k<=n;k++)
				g[i][j][k]=I;
		}
	w[0]=w[K]=1;
	D(K-1);
	cout<<A;
	return 0;
}