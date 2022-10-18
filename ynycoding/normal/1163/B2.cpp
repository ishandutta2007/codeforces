#include <cstdio>
#include <set>
#define MAXN 100005
using std::multiset;
int n, t[MAXN], ans;
multiset<int> st;
int main()
{
	scanf("%d", &n);
	for(int i=1, a; i<=n; ++i)
	{
		scanf("%d", &a);
		if(st.find(t[a])!=st.end()) st.erase(st.find(t[a]));
		++t[a];
		// for(int i=1; i<=5; ++i) printf("%d\n", t[i]);
		st.insert(t[a]);
		if(st.size()==1) ans=i;
		if(st.size()==2) { if(*(st.begin())+1==*prev(st.end())) ans=i; continue; }
		if(*(st.begin())==*prev(st.end())&&*(st.begin())!=1) continue;
		if((*next(st.begin())==*prev(st.end())&&(*(st.begin())==*next(st.begin())+1||*(st.begin())==1))||
		(*(st.begin())==*prev(prev(st.end()))&&(*prev(st.end())==*(st.begin())+1||*prev(st.end())==1))) ans=i;
	}
	printf("%d", ans);
	return 0;
}