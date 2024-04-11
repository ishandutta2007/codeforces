#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-12);
const double pi(3.14159265358979);
const int N=5050,T=5050;
int n,m,t[N]={};
double u1[T]={},p[N]={},u2[T]={},ans=0;
void init()
{
	cin>>n>>m;
	for(int i=1,x=0;i<=n;++i)
	{
		cin>>x>>t[i];
		p[i]=x/100.0;
	}
}
void work()
{
	double *f=u1,*s=u2;
	f[0]=1;
	for(int i=1;i<=n;++i)
	{
		double p1=1;
		for(int j=1;j<=t[i];++j)
			p1*=1-p[i];
		if(p1<eps)
			p1=0;
		s[0]=0;
		for(int j=1;j<t[i];++j)
		{
			s[j]=s[j-1]*(1-p[i])+f[j-1]*p[i];
			if(s[j]<eps)
				s[j]=0;
		}
		s[t[i]]=s[t[i]-1]*(1-p[i])+f[t[i]-1]*p[i]+p1*f[0];
		if(s[t[i]]<eps)
			s[t[i]]=0;
		for(int j=t[i]+1;j<=m;++j)
		{
			s[j]=s[j-1]*(1-p[i])+f[j-1]*p[i]+p1*(f[j-t[i]]-f[j-t[i]-1]);
			if(s[j]<eps)
				s[j]=0;
		}
		for(int j=0;j<=m;++j)
			ans+=s[j];
		swap(f,s);
	}
	printf("%.9f\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}