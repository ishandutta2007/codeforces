#include <cstdio>
#include <set>
#include <algorithm>
using std::set;
const int N=100005;
int n, a[N], b[N], cnt;
struct cmp{
	bool operator ()(int x, int y) { return b[x]==b[y]?x<y:b[x]<b[y]; }
};
set<int, cmp> st;
int main()
{
	scanf("%d", &n);
	if(n==1) return puts("1"), 0;
	st.insert(0);
	for(int i=1; i<=n; ++i) b[i]=0x3f3f3f3f, st.insert(i);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", a+i);
		if(a[i]!=a[i-1])
		{
			++cnt;
//			if(i>2)
			{
				st.erase(a[i-1]);
				b[a[i-1]]=std::min({b[*st.begin()], b[a[i]]-1, b[a[i-1]]});
				st.insert(a[i-1]);
			}
		}
	}
	printf("%d\n", cnt+b[*st.begin()]);
	return 0;
}