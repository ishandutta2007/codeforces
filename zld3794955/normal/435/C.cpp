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
int n,s1[N]={},s2[N]={};
char ch[N][N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		s1[i]=s1[i-1]+x;
		s2[i]=s2[i-1] + (i%2 ? x : -x);
	}
	int minv=0x7fffffff,maxv=-0x7fffffff;
	for(int i=0;i<=n;++i)
		minv=min(minv,s2[i]),maxv=max(maxv,s2[i]);
	for(int i=0;i<=n;++i)
		s2[i]-=minv;
	maxv-=minv;
	for(int i=1;i<=maxv;++i)
		for(int j=1;j<=s1[n];++j)
			ch[i][j]=' ';
	for(int i=0,v=0;i<n;++i)
	{
		if(i%2==0)
			for(int j=s1[i]+1;j<=s1[i+1];++j)
			{
				v=s2[i]+j-s1[i];
				ch[v][j]='/';
			}
		else
			for(int j=s1[i]+1;j<=s1[i+1];++j)
			{
				v=s2[i]-(j-1-s1[i]);
				ch[v][j]='\\';
			}
	}
	for(int i=maxv;i>=1;--i)
		printf("%s\n",ch[i]+1);
	return 0;
}