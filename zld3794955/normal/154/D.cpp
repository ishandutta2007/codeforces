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
int main()
{	
	long long x1,x2,d,a,b;
	bool flag=false;
	cin>>x1>>x2>>a>>b;
	d=x2-x1;
	if(d<0)
	{
		d=-d;
		swap(x1,x2);
		a=-a;
		b=-b;
		swap(a,b);
		flag=true;
	}
	if(a<=d && d<=b)
	{
		puts("FIRST");
		if(flag)
			cout<<x1<<endl;
		else
			cout<<x2<<endl;
	}
	else
		if(a<=0)
			puts("DRAW");
		else
		{
			long long r=d%(a+b);
			if(r==0)
				puts("SECOND");
			else if(a<=r && r<=b)
			{
				puts("FIRST");
				//long long k=d/(a+b);
				if(flag)
					cout<<x2-r<<endl;
				else
					cout<<x1+r<<endl;
			}
			else
				puts("DRAW");
		}
	return 0;
}