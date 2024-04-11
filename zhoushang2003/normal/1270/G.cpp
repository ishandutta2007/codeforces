#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
bool v[N];
int T,n,a[N],p[N],x,q[N],t;
int main()
{
	cin>>T;
	while(T--&&scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			p[i]=i-a[i],v[i]=false;
		x=1;
		while(!v[x])
			v[x]=true,x=p[x];
		t=q[1]=0;
		while(x!=q[1])
			q[++t]=x,x=p[x];
		cout<<t<<'\n';
		for(int i=1;i<=t;i++)
			cout<<q[i]<<' ';
		cout<<'\n';
	}
	return 0;
}