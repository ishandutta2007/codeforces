#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=2000000+10;

int cnt[MAXN];
int n, k;

inline bool check(int d, int m) {
	int ret=0;
	for (int i=1; i<=m/d; i++) {
		ret+=cnt[i*d+k]-cnt[i*d-1];
	}
	return (ret==n);
}

int main() {
	int ans=1e6, m=0;
	scanf("%d%d", &n, &k);
	memset(cnt, 0, sizeof(cnt));
	for (int i=0, x; i<n; i++) {
		scanf("%d", &x); cnt[x]++;
		ans=min(ans, x); m=max(m, x);
	}
	for (int i=1; i<=2000000; i++) cnt[i]+=cnt[i-1];
	for (; ans>k+1; ans--) {
		if (check(ans, m)) break;
	}
	printf("%d\n", ans);
	return 0;
}