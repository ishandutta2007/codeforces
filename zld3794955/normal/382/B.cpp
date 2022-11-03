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
int a,b,w,x,c,t1=0,t2=0,t3=0;
long long tot=0;
int da=0,dc=0;
int main()
{	
	cin>>a>>b>>w>>x>>c;
	da=x;
	dc=w;
	t1=dc;
	int d=c-a;
	if(d<=0)
		printf("0\n");
	else
	{
		int y=(d-1)/(dc-da);
		c-=dc*y;
		a-=da*y;
		tot+=(long long)t1*(long long)y;
		while(c>a)
		{
			if(b>=x)
				b-=x;
			else
				b=w+b-x,--a;
			--c;
			++tot;
		}
		cout<<tot<<endl;
	}
	return 0;
}