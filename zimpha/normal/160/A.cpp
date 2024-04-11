#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n, a[1000], s1=0, sum=0;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", a+i);
		sum+=a[i];
	}
	sort(a, a+n);
	int ret=0;
	for (int i=n-1; i>=0; i--) {
		s1+=a[i]; ret++;
		if (s1>sum-s1) break;
	}
	printf("%d\n", ret);
	return 0;
}