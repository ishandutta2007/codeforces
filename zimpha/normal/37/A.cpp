#include <cstdio>
#include <cstring>

int cnt[10000];
int n;

int main() {
	scanf("%d", &n);
	memset(cnt, 0, sizeof(cnt));
	for (int i=0; i<n; i++) {
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	int ret1=0, ret2=0;
	for (int i=1; i<=1000; i++) {
		if (cnt[i]>0) {
			ret2++;
			if (cnt[i]>ret1) ret1=cnt[i];
		}
	}
	printf("%d %d\n", ret1, ret2);
	return 0;
}