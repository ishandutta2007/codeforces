#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int T,n,a[N],x,t,q[N];
int main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		map<int,int>p,c;
		for(int i=1;i<=n;i++)
			cin>>a[i],p[a[i]]=i;
		x=t=0;
		for(int i=1;i<=n;i++)
		{
			c[a[i]]++;
			while(c[x])
				x++;
			if(i>p[x])
				q[++t]=x,x=0,c.clear();
		}
		cout<<t<<'\n';
		for(int i=1;i<=t;i++)
			cout<<q[i]<<' ';
		puts("");
	}
}