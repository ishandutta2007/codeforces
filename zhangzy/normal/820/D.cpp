#include<cstdio>
#include<iostream>
#define xxx 1001000
using namespace std;

long long tot[xxx],cg,n,p[xxx],tt,ans,anw;

long long abss(long long x)
{
	return x>0?x:-x;
}

int main()
{
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>p[i];
		if (p[i]>=i)
		{
			cg--;
			tot[p[i]-i]++;
			tt+=p[i]-i;
		}
		else
		{
			cg++;
			tot[p[i]-i+n]++;
			tt+=i-p[i];
		}
	}
	ans=tt;
	anw=0;
	for (long long i=1;i<n;i++)
	{
		cg+=tot[i-1]*2-2;
		tt+=cg+abss(p[n-i+1]-1)-abss(p[n-i+1]-n)+1;
		if (tt<ans)
		{
			ans=tt;
			anw=i;
		}
	}
	cout<<ans<<' '<<anw<<endl;
}