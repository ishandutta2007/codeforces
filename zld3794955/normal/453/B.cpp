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
const int N=110,S=16,v=60,V=80,Inf=1<<20;
const int p[S]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n,a[N]={},tot=0,f[N][1<<S]={},num[N][1<<S]={},s[V]={};
int calc(int v)
{
	int s=0;
	for(int i=0;i<S;++i)
		if(v%p[i]==0)
			s|=1<<i;
	return s;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<=n;++i)
		for(int j=0;j<(1<<S);++j)
			f[i][j]=Inf;
	for(int i=1;i<=v;++i)
		s[i]=calc(i);
}
void get_ans(int t,int pos)
{
	if(!t)
		return;
	get_ans(t-1,pos|s[num[t][pos]]);
	printf("%d ",num[t][pos]);
}
void dp()
{
	f[0][(1<<S)-1]=0;
	for(int i=0;i<n;++i)
		for(int j=(1<<S)-1;j>=0;--j)
			for(int k=1;k<=v;++k)
			{
				if(s[k]&(~j))
					continue;
				int news=j^s[k];
				if(f[i][j]+abs(a[i+1]-k)<f[i+1][news])
				{
					f[i+1][news]=f[i][j]+abs(a[i+1]-k);
					num[i+1][news]=k;
				}
			}
	int pos=0;
	for(int i=1;i<(1<<S);++i)
		if(f[n][i]<f[n][pos])
			pos=i;
	get_ans(n,pos);
	printf("\n");
}
int main()
{	
	init();
	dp();
	return 0;
}