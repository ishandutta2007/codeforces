#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,f[N],c[N],a[N],x,y,s=1,A;
int F(int x)
{
	return f[x]==x?x:x=F(f[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i,c[i]=1;
	while(m--&&cin>>x>>y)
	{
		x=F(x),y=F(y),A=0;
		if(x!=y)
			f[y]=x,c[x]+=c[y];
		else
			s++;
		for(int i=1;i<=n;i++)
			a[i]=(i==F(i))*c[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=s;i++)
			A+=a[n-i+1];
		cout<<A-1<<'\n';
	}
}