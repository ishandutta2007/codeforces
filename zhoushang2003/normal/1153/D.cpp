#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
bool v[N];
int n,g[N],x,c[N],f[N],q[N],t,X,z[N];
vector<int>a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>g[i];
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		a[i].push_back(x),a[x].push_back(i),c[i]++,c[x]++;
	}
	for(int i=1;i<=n;i++)
		if(g[i])
			f[i]=1e9;
	for(int i=1;i<=n;i++)
		if(c[i]==1)
			q[++t]=i,f[i]=1,z[i]=1,v[i]=true;
	while(t)
	{
		X=q[t--];
		for(int i=0;i<a[X].size();i++)
			if(!v[a[X][i]])
			{
				if(g[a[X][i]])
					f[a[X][i]]=min(f[a[X][i]],f[X]);
				else
					f[a[X][i]]+=f[X];
				z[a[X][i]]+=z[X];
				c[a[X][i]]--;
				if(c[a[X][i]]==1&&a[X][i]!=1)
					q[++t]=a[X][i],v[a[X][i]]=true;
			}
	}
	cout<<z[1]+1-f[1];
	return 0;
}