#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,I=1e18;
int n,k,x,y,z[N],s[N],v[N],q[N],t,w,A=I;
vector<int>a[N];
void D(int x,int f)
{
	z[x]=1;
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
		{
			D(a[x][i],x);
			if(z[x]<z[a[x][i]]+1)
				z[x]=z[a[x][i]]+1,s[x]=a[x][i];
		}
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
		cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
	D(1,0);
	for(int i=1;i<=n;i++)
		v[s[i]]=1;
	for(int i=1;i<=n;i++)
		if(!v[i])
			q[++t]=z[i];
	sort(q+1,q+t+1);
	if(k>=t)
	{
		k=min(k,max(t,n/2));
		cout<<k*(n-k);
		return 0;
	}
	for(int i=t;i>=t-k+1;i--)
		w+=q[i]-1;
	for(int i=0;i<=n-k-w;i++)
		A=min(A,(n-i-k)*(k-i));
	cout<<A;
}