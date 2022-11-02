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
int n,k,p,a[100010]={};
multiset<int>odd,even;
vector<int> way[100010];
void init()
{
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		(a[i]%2 ? odd : even).insert(a[i]);
	}
}
void work()
{
	for(int i=1;i<=p;++i)
		if(even.empty())
		{
			if(odd.empty())
			{
				puts("NO");
				return;
			}
			way[i].push_back(*odd.begin());
			odd.erase(odd.begin());
			if(odd.empty())
			{
				puts("NO");
				return;
			}
			way[i].push_back(*odd.begin());
			odd.erase(odd.begin());
		}
		else
		{
			way[i].push_back(*even.begin());
			even.erase(even.begin());
		}
	for(int i=p+1;i<=k;++i)
	{
		if(odd.empty())
		{
			puts("NO");
			return;
		}
		way[i].push_back(*odd.begin());
		odd.erase(odd.begin());
	}
	if(odd.size()%2)
	{
		puts("NO");
		return;
	}
	while(!even.empty())
	{
		way[1].push_back(*even.begin());
		even.erase(even.begin());
	}
	while(!odd.empty())
	{
		way[1].push_back(*odd.begin());
		odd.erase(odd.begin());
	}
	puts("YES");
	for(int i=1;i<=k;++i)
	{
		cout<<way[i].size();
		for(int j=0;j<int(way[i].size());++j)
			cout<<' '<<way[i][j];
		cout<<endl;
	}
		
}
int main()
{	
	init();
	work();
	return 0;
}