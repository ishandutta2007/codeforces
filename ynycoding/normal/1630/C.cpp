#include <cstdio>
#include <set>
#include <algorithm>
using std::set;
const int N=200005;
int n, a[N], pos[N], cur;
set<int> st;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), pos[a[i]]=i;
	int mx=0;
	for(int i=1; i<=n; ++i)
	{
		st.insert(pos[a[i]]-1);
		int v=*st.rbegin();
		if(i>mx)
		{
			st.erase(prev(st.end()));
			if(v>=i) cur+=v-i, mx=v;
		}
	}
	printf("%d\n", cur);
	return 0;
}