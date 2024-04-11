#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long t,n,p[N],x,a,y,b,m,c[N],s,l,r;
bool C(int k)
{
	for(int i=1;i<=k;i++)
	{
		c[i]=0;
		if(i%a==0)
			c[i]=x;
		if(i%b==0)
			c[i]+=y;
	}
	sort(c+1,c+k+1),s=0;
	for(int i=1;i<=k;i++)
		s+=c[i]*p[n-k+i];
	if(s<m)
		return false;
	return true;
}
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
			p[i]/=100;
		}
		sort(p+1,p+n+1);
		cin>>x>>a>>y>>b>>m;
		if(!C(n))
		{
			cout<<-1<<'\n';
			continue;
		}
		l=1,r=n;
		while(l<r)
			if(C((l+r)/2))
				r=(l+r)/2;
			else
				l=(l+r)/2+1;
		cout<<l<<'\n';
	}
	return 0;
}