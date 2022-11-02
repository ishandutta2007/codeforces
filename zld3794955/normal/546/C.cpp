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
const int N=30;
int n,k1,k2;
deque<int> a,b;
set<pair<deque<int>,deque<int> > > s;
int main()
{	
	cin>>n;
	cin>>k1;
	for(int i=1,x=0;i<=k1;++i)
	{
		cin>>x;
		a.push_back(x);
	}
	cin>>k2;
	for(int i=1,x=0;i<=k2;++i)
	{
		cin>>x;
		b.push_back(x);
	}
	int tot=0;
	while(!a.empty() && !b.empty())
	{
		if(s.count(make_pair(a,b)))
		{
			puts("-1");
			return 0;
		}
		s.insert(make_pair(a,b));
		int x=a.front(),y=b.front();
		a.pop_front(),b.pop_front();
		++tot;
		if(x>y)
		{
			a.push_back(y);
			a.push_back(x);
		}
		else
		{
			b.push_back(x);
			b.push_back(y);
		}
	}
	cout<<tot<<' '<<(a.empty() ? 2 : 1)<<endl;
	return 0;
}