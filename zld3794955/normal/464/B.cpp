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
const int P=8,SP=10;
long long x[SP]={},y[SP]={},z[SP]={};
long long ansx[SP]={},ansy[SP]={},ansz[SP]={};
bool ans=false;
inline long long sqr(long long x) { return x*x; }
void check()
{
	for(int i=1;i<=P;++i)
	{
		long long a[SP]={},mindis=1ll<<60;
		for(int j=1;j<=P;++j)
			a[j]=sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]);
		for(int j=1;j<=P;++j)
			if(a[j])
				mindis=min(mindis,a[j]);
		int t[5]={};
		for(int j=1;j<=P;++j)
		{
			if(a[j]%mindis || a[j]/mindis>3)
				return;
			++t[a[j]/mindis];
		}
		if(t[0]!=1 || t[1]!=3 || t[2]!=3 || t[3]!=1)
			return;
	}
	ans=true;
	for(int i=1;i<=P;++i)
		ansx[i]=x[i] , ansy[i]=y[i] , ansz[i]=z[i];
}
void tryy(int t)
{
	if(t>P)
		check();
	else
	{
		tryy(t+1);
		if(ans)
			return;
		swap(y[t],z[t]);
		tryy(t+1);
		if(ans)
			return;
		swap(x[t],y[t]);
		tryy(t+1);
		if(ans)
			return;
		swap(y[t],z[t]);
		tryy(t+1);
		if(ans)
			return;
		swap(x[t],y[t]);
		tryy(t+1);
		if(ans)
			return;
		swap(y[t],z[t]);
		tryy(t+1);
		if(ans)
			return;
		swap(x[t],y[t]);
	}
}
int main()
{	
	for(int i=1;i<=P;++i)
		cin>>x[i]>>y[i]>>z[i];
	tryy(1);
	if(ans)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=P;++i)
			cout<<ansx[i]<<' '<<ansy[i]<<' '<<ansz[i]<<endl;
	}
	else
		cout<<"NO"<<endl;
	//cout<<clock()<<endl;
	return 0;
}