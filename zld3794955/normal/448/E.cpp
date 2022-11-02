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
const int N=100010,Sup=100000;
long long x,k,a[N]={},fac[N]={},f[N]={};
int tot=0,factot=0;
void init()
{
	cin>>x>>k;
	if(k>Sup)
		k=Sup;
	long long i=1;
	for(;i*i<x;++i)
		if(x%i==0)
			fac[++factot]=i,fac[++factot]=x/i;
	if(i*i==x)
		fac[++factot]=i;
	sort(fac+1,fac+factot+1);
}
void write_seq(int now,int d)
{
	//cout<<"now="<<now<<" d="<<d<<endl;
	if(d>k || now==1)
	{
		a[++tot]=fac[now];
		return;
	}
	for(int i=1;i<=now;++i)
	{
		if(fac[now]%fac[i]==0)
			write_seq(i,d+1);
		if(tot==Sup)
			return;
	}
}
void work()
{
	write_seq(factot,1);
	for(int i=1;i<=tot;++i)
		printf("%I64d ",a[i]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}