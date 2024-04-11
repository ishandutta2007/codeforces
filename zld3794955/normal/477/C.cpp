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
const int N=2020,M=505,Inf=1<<20;
int n,m,a[N]={},b[M]={},last[N]={},f[N][N]={};
char s[N]={},p[M]={};
void init()
{
	gets(s+1);
	gets(p+1);
	n=strlen(s+1);
	m=strlen(p+1);
	for(int i=1;i<=n;++i)
		a[i]=s[i]-'a';
	a[n+1]=-1;
	for(int i=1;i<=m;++i)
		b[i]=p[i]-'a';
	b[m+1]=-1;
}
void get_last()
{
	for(int i=1;i<=n;++i)
		if(a[i]==b[1])
		{
			int posb=2,end=0;
			for(end=i+1;end<=n && posb<=m;++end)
				if(a[end]==b[posb])
					++posb;
			if(posb>m)
				last[end-1]=max(last[end-1],i);
		}
	//for(int i=1;i<=n;++i)
	//	cout<<last[i]<<' ';
	//cout<<endl;
}
void work()
{
	for(int i=0;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			f[i][j]=-Inf;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=n;++j)
		{
			f[i][j]=f[i-1][j];
			if(j)
				f[i][j]=max(f[i][j],f[i-1][j-1]);
			if(last[i])
			{
				int cost=i-last[i]+1-m;
				if(j>=cost)
					f[i][j]=max(f[i][j],f[last[i]-1][j-cost]+1);
			}
		}
	/*
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}*/
	for(int i=0;i<=n;++i)
		cout<<f[n][i]<<' ';
	cout<<endl;
}
int main()
{	
	init();
	get_last();
	work();
	return 0;
}