#include <cstdio>
#include <set>
#include <algorithm>
#define x first
#define y second
using std::multiset;
using std::pair;
const int N=1000005;
int n, d, ans;
multiset<pair<int, int> > s, t, s1, t1;
int main()
{
	scanf("%d%d", &n, &d);
	for(int i=1, x, y; i<=n; ++i)
	{
		scanf("%d%d", &x, &y);
		if(x>=y) s.insert({x, y}), t.insert({y, x});
		else s1.insert({x, y}), t1.insert({y, x});
	}
	while(1)
	{
		while(!s.empty()&&s.begin()->x<d) t.erase(t.find({s.begin()->y, s.begin()->x})), s.erase(s.begin());
		while(!s1.empty()&&s1.begin()->x<d) t1.erase(t1.find({s1.begin()->y, s1.begin()->x})), s1.erase(s1.begin());
		if(s.empty()&&s1.empty()) break;
		++ans;
		if(!s.empty()&&(s1.empty()||t1.begin()->x>s.begin()->x))
		{
			auto v=*t.begin();
			d=std::max(d, v.x);
			t.erase(t.find(v));
			s.erase(s.find({v.y, v.x}));
		}
		else
		{
			auto v=*t1.begin();
			d=std::max(d, v.x);
			t1.erase(t1.find(v));
			s1.erase(s1.find({v.y, v.x}));
		}
	}
	printf("%d\n", ans);
	return 0;
}