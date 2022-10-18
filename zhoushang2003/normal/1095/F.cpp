#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=4e5;
struct S
{
	int a,b;
	long long c;
};
int n,m,I=1,c,x,y,f[N];
long long a[N],z,A;
S w[M];
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
bool C(S x,S y)
{
	return x.c<y.c;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]<a[I])
			I=i;
	for(int i=0;i<n;i++)
		w[c].a=i+1,w[c].b=I,w[c++].c=a[i+1]+a[I];
	while(m--&&cin>>x>>y>>z)
		w[c].a=x,w[c].b=y,w[c++].c=z;
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(w,w+c,C);
	for(int i=0;i<c;i++)
	{
		x=F(w[i].a),y=F(w[i].b);
		if(x!=y)
			f[x]=y,A+=w[i].c;
	}
	cout<<A;
	return 0;
}