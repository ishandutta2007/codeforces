#include <cstdio>
#include <set>
#include <algorithm>
#define N 100005
using std::set;
int n, s1, s2, a[N], l, r;
set<int> s;
bool check(int k)
{
	s.clear();
	s.insert(s1), s.insert(s2);
	for(int i=1; i<=n; ++i)
	{
		while(!s.empty()&&*s.begin()<a[i]-k) s.erase(s.begin());
		while(!s.empty()&&*prev(s.end())>a[i]+k) s.erase(prev(s.end()));
		if(s.empty()) return 0;
		s.insert(a[i]);
	}
	return 1;
}
int main()
{
	scanf("%d%d%d", &n, &s1, &s2);
	r=std::max(s1, s2);
	l=r-std::min(s1, s2);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), r=std::max(r, a[i]);
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n", l);
	return 0;
}