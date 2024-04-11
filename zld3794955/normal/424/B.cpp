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
const int N=1010,T=1000000;
struct point
{
	int x,y,a;
}p[N]={};
bool cmp(const point &p1,const point &p2)
{
	return p1.x*p1.x+p1.y*p1.y<p2.x*p2.x+p2.y*p2.y;
}
int n,s;
void init()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].a);
	}
	sort(p+1,p+n+1,cmp);
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		s+=p[i].a;
		if(s>=T)
		{
			printf("%.8f\n",sqrt(p[i].x*p[i].x+p[i].y*p[i].y));
			return;
		}
	}
	printf("-1\n");
}
int main()
{	
	init();
	work();
	return 0;
}