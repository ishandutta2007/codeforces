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
int w,h,n;
set<int> h1,w1;
multiset<long long> h2,w2;
int main()
{	
	cin>>w>>h>>n;
	h1.insert(0),h1.insert(h),h2.insert(h);
	w1.insert(0),w1.insert(w),w2.insert(w);
	for(int i=1;i<=n;++i)
	{
		char ch;
		int x;
		cin>>ch>>x;
		if(ch=='H')
		{
			auto l=h1.lower_bound(x);
			auto r=l--;
			h2.erase(h2.find(*r-*l));
			h2.insert(x-*l);
			h2.insert(*r-x);
			h1.insert(x);
		}
		else
		{
			auto l=w1.lower_bound(x);
			auto r=l--;
			w2.erase(w2.find(*r-*l));
			w2.insert(x-*l);
			w2.insert(*r-x);
			w1.insert(x);
		}
		cout<<*h2.rbegin()**w2.rbegin()<<endl;
	}
	return 0;
}