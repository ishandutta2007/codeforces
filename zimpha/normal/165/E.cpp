#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=1<<22;

int n, a[MAXN], dp[MAXN];

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		dp[a[i]]=a[i];
	}
	for (int i=0; i<MAXN; i++) {
		for (int j=1; j<MAXN; j<<=1) {
			if (i&j) dp[i]=max(dp[i], dp[i^j]);
		}
	}
	for (int i=0; i<n; i++) {
		printf("%d%c", dp[(MAXN-1)^a[i]], (i<n-1)?' ':'\n');
	}
	return 0;
}