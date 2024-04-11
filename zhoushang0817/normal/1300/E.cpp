#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
long long n,a[N],s,c,p[N],q[N],t;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		s=a[i],c=1;
		while(t&&p[t]*c>=s*q[t])
			s+=p[t],c+=q[t--];
		p[++t]=s,q[t]=c;
	}
	for(int i=1;i<=t;i++)
		for(int j=1;j<=q[i];j++)
			printf("%.9lf\n",(double)p[i]/q[i]);
	return 0;
}