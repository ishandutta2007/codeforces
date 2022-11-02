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
const double eps(1e-8);
const double pi(3.14159265358979);
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
const int V=5000050;
double a[V]={};
int prime[V]={},ptot=0,t[V]={};
bool del[V]={};
void init()
{
	const int n=5000000;
	for(int i=2;i<=n;++i)
	{
		if(!del[i])
			prime[++ptot]=i,t[i]=1;
		for(int j=1;j<=ptot && i*prime[j]<=n;++j)
		{
			del[i*prime[j]]=true;
			t[i*prime[j]]=t[i]+1;
			if(i%prime[j]==0)
				break;
		}
	}
	for(int i=1;i<=n;++i)
		t[i]+=t[i-1];
}
void work()
{
	int T=getint();
	while(T--)
	{
		int a=getint(),b=getint();
		printf("%d\n",t[a]-t[b]);
	}
}
int main()
{
	init();
	work();
}