#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n,m,x,y,z,p;
int main()
{	
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
	int n_=n,m_=m;
	x%=4;
	y%=2;
	z%=4;
	int a,b;
	for(int i=1;i<=p;++i)
	{
		n=n_;
		m=m_;
		scanf("%d%d",&a,&b);
		if(x==0)
			;
		if(x==1)
		{
			int a_=a,b_=b;
			a=b_;
			b=n+1-a_;
			swap(n,m);
		}
		if(x==2)
		{
			a=n+1-a;
			b=m+1-b;
		}
		if(x==3)
		{
			int a_=a,b_=b;
			b=a_;
			a=m+1-b_;
			swap(n,m);
		}
		if(y==0)
			;
		if(y==1)
		{
			b=m+1-b;
		}
		if(z==0)
			;
		if(z==1)
		{
			int a_=a,b_=b;
			b=a_;
			a=m+1-b_;
			swap(n,m);
		}
		if(z==2)
		{
			a=n+1-a;
			b=m+1-b;
		}
		if(z==3)
		{
			int a_=a,b_=b;
			a=b_;
			b=n+1-a_;
			swap(n,m);
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}