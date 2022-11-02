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
const int N=100010;
pair<int,int> exams[N];
int n,r,avg;
long long sum;
void init()
{
	scanf("%d%d%d",&n,&r,&avg);
	sum=(long long)avg*n;
	for(int i=1,a=0,b=0;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		sum-=a;
		exams[i]=make_pair(b,r-a);
	}
	sort(exams+1,exams+n+1);
}
void work()
{
	long long ans=0;
	for(int i=1;i<=n && sum>0;++i)
	{
		long long delta=min(sum,(long long)exams[i].second);
		ans+=delta*exams[i].first;
		sum-=delta;
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}