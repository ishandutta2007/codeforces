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
const int N=3030,D=3030;
int n,m,v[D]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a=0,b=0;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		v[a]+=b;
	}
}
void work()
{
	int ans=0;
	for(int i=1;i<=3001;++i)
	{
		int x=m;
		int tmp=min(v[i-1],x);
		v[i-1]-=tmp;
		x-=tmp;
		ans+=tmp;
		tmp=min(v[i],x);
		v[i]-=tmp;
		x-=tmp;
		ans+=tmp;
	}
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}