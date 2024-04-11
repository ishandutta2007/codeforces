#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+1;
struct S
{
	int a,b,c;
};
int m,n,a[N],b[N],k,x,y,f[N],t,A;
S w[N];
bool C(S x,S y)
{
	return x.c<y.c;
}
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
signed main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		while(k--&&cin>>x)
			w[++t]=(S){i+n,x,a[i]+b[x]};
	}
	for(int i=1;i<=n+m;i++)
		f[i]=i;
	sort(w+1,w+t+1,C);
	for(int i=t;i>=1;i--)
	{
		x=F(w[i].a),y=F(w[i].b);
		if(x!=y)
			f[x]=y;
		else
			A+=w[i].c;
	}
	cout<<A;
	return 0;
}