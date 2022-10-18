#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#define ll long long
using std::priority_queue;
const int N=300005;
int T, n, m, cnt[N], c[N];
priority_queue<int, std::vector<int>, std::greater<int> > q;
ll ans;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &m, &n);
		for(int i=1, k; i<=m; ++i) scanf("%d", &k), ++cnt[k];
		for(int i=1; i<=n; ++i) scanf("%d", c+i);
		while(!q.empty()) q.pop();
		ans=0;
		for(int i=1; i<=n; ++i)
		{
			q.push(c[i]);
			while(cnt[i]--)
			{
				ans+=q.top();
				q.pop();
				q.push(c[i]);
			}
			cnt[i]=0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}