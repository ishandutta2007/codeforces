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
const int N=30;
int n,a[N]={},next[N]={},t[N]={};
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		++t[a[i]];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i)
		next[i]=upper_bound(a+1,a+n+1,a[i])-a;
}
void tryy(int d,int s,int last)
{
	if(s==0)
		s=a[++d]-1,last=1;
	if(d==n+1)
	{
		for(int i=1;i<n;i=next[i])
			if(t[a[i]])
				return;
		puts("YES");
		exit(0);
	}
	for(int i=last;a[i]<a[d]-1;i=next[i])
	{
		for(int j=0;j<=t[a[i]];++j)
		{
			if(a[i]*j>s)
				break;
			t[a[i]]-=j;
			tryy(d,s-a[i]*j,next[i]);
			t[a[i]]+=j;
		}
	}
}
void work()
{
	if(t[1]<(n+1)/2 || t[2])
	{
		puts("NO");
		return;
	}
	if(n>=2)
		tryy(next[1],a[next[1]]-1,1);
	else
		if(a[n]==1)
		{
			puts("YES");
			return;
		}
	puts("NO");
}
int main()
{	
	init();
	work();
	return 0;
}