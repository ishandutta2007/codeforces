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
const int N=100100;
int n,k,a[N]={};
set<int>s;
inline int calc(int x)
{
	int t=0;
	for(;x;x-=(x&(-x)))
		++t;
	return t;
}
int main()
{	
	cin>>n>>k;
	int pos=n;
	if(n==1)
	{
		if(k==0)
			puts("10000");
		else
			puts("-1");
		return 0;
	}
	if(n&1)
	{
		a[n--]=1000000000;
		s.insert(1000000000);
	}
	int g=k/(n/2),l=k%(n/2);
	if(g==0)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i+=2)
	{
		a[i]=g*i;
		a[i+1]=a[i]+g;
		s.insert(a[i]);
		s.insert(a[i+1]);
	}
	s.erase(a[1]);
	s.erase(a[2]);
	g+=l;
	int b=1;
	while(s.count(g*b) || s.count(g*(b+1)))
		++b;
	a[1]=g*b;
	a[2]=g*(b+1);
	for(int i=1;i<=pos;++i)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}