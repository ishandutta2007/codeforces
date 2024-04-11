#include<iostream>
using namespace std;
const int M=50;
long long n,b,p[M],d[M],t,s,l[M],A=1e18;
int main()
{
	cin>>n>>b;
	for(long long i=2;i*i<=b;i++)
		if(b%i==0)
		{
			p[++t]=i;
			while(b%i==0)
				b/=i,d[t]++;
		}
	if(b>1)
		p[++t]=b,d[t]=1;
	for(int i=1;i<=t;i++)
	{
		s=p[i];
		while(s<=n)
		{
			l[i]+=n/s;
			if(n/p[i]>=s)
				s*=p[i];
			else
				break;
		}
	}
	for(int i=1;i<=t;i++)
		A=min(A,l[i]/d[i]);
	cout<<A;
	return 0;
}