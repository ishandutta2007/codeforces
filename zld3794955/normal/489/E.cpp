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
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=1010;
int n,l,x[N]={},b[N]={},d[N]={};
double f[N]={};
void init()
{
	cin>>n>>l;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>b[i];
}
bool check(double rate)
{
	fill(f+1,f+n+1,1e+64);
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j)
		{
			double tmp=f[j]+sqrt(fabs(x[i]-x[j]-l))-rate*b[i];
			if(tmp<f[i])
			{
				f[i]=tmp;
				d[i]=j;
			}
		}
	/*
	cout<<"r="<<rate<<endl;
	for(int i=1;i<=n;++i)
		cout<<f[i]<<' ';
	cout<<endl;
	*/
	return f[n]<-eps;
}
void print(int now)
{
	if(d[now])
		print(d[now]);
	cout<<now<<' ';
}
void work()
{
	double l=0,r=1000;
	while(r-l>eps)
	{
		double mid=(l+r)*0.5;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	check(l);
	//cout<<"l="<<l<<endl;
	print(n);
	//for(int i=1;i<=n;++i)
	//	cout<<f[i]<<' ';
	//cout<<endl;
	//cout<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}