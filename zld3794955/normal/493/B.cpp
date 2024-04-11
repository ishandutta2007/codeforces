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
const int N=200020;
int n,x,a[N]={},b[N]={},t1=0,t2=0;
int main()
{	
	cin>>n;
	bool flag=false;
	for(int i=1;i<=n;++i)
	{
		cin>>x;
		if(x<0)
			b[++t2]=-x;
		else
			a[++t1]=x;
	}
	flag=x>0;
	long long s1=0,s2=0;
	for(int i=1;i<=t1;++i)
		s1+=a[i];
	for(int i=1;i<=t2;++i)
		s2+=b[i];
	if(s1<s2)
		puts("second");
	else
	{
		if(s1>s2)
			puts("first");
		else
		{
			for(int i=1;i<=max(t1,t2);++i)
			{
				if(a[i]>b[i])
				{
					puts("first");
					return 0;
				}
				if(a[i]<b[i])
				{
					puts("second");
					return 0;
				}
			}
			puts(flag ? "first" : "second");
		}
	}
	return 0;
}