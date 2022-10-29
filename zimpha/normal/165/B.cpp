#include <cstdio>
#include <cstring>
#include <algorithm>

int n, k;

bool check(int v) {
	long long p=1, ret=0;
	while (1) {
		ret+=v/p;
		if (v/p==0) break;
		p*=k;
	}
	if (ret>=n) return true;
	else return false;
}

int main() {
	scanf("%d%d", &n, &k);
	int left=1, right=n+1;
	while (left<right) {
		int mid=(left+right)>>1;
		if (check(mid)) right=mid;
		else left=mid+1;
	}
	printf("%d\n", right);
	return 0;
}