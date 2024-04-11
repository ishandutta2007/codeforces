#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=100000+10;
int s[MAXN];
int n;

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", s+i);
	sort(s, s+n);
	int l=0, r=n-1, ret=0;
	while (l<=r) {
		int sum=0;
		while (l<r && sum+s[l]+s[r]<=4) l++, sum+=s[l];
		if (l>r) break;
		r--; ret++;
	}
	printf("%d\n", ret);
	return 0;
}