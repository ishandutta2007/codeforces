#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=100000+10;

set<int> s[MAXN];
int col[MAXN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%d", col+i);
	for (int a, b, i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		if (col[a]!=col[b]) {
			s[col[a]].insert(col[b]);
			s[col[b]].insert(col[a]);
		}
	}
	sort(col+1, col+1+n);
	int ans=col[1];
	for (int i=1; i<=n; i++)
		if (s[col[i]].size()>s[ans].size()) ans=col[i];
	printf("%d\n", ans);
	return 0;
}