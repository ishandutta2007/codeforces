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
const int N=70000;
struct node
{
	int d,s;
}a[N]={};
int n,m=0,p[N]={},u[N]={},v[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d%d",&a[i].d,&a[i].s);
	queue<int>q;
	for(int i=0;i<n;++i)
		if(a[i].d==1)
			q.push(i);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(a[now].d==0)
			continue;
		++m;
		u[m]=now;
		v[m]=a[now].s;
		a[v[m]].s^=now;
		--a[v[m]].d;
		if(a[v[m]].d==1)
			q.push(v[m]);
	}
	printf("%d\n",m);
	for(int i=1;i<=m;++i)
		printf("%d %d\n",u[i],v[i]);
	return 0;
}