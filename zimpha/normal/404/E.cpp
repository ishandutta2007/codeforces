#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;

char st[MAXN];
int a[MAXN], n;

bool check(int lim) {
	int p = 0, ends = 0, flag;
	for (int i = 0; i < n; ++ i) {
		flag = 0;
		if (a[i]) p ++;
		else if (p - 1 > -lim) p --;
		if (p > ends) ends = p, flag = 1;
	}
	return flag;
}

int main() {
	scanf("%s", st); n = strlen(st);
	for (int i = 0; i < n; ++ i) a[i] = (st[i] == 'R');
	if (!a[n - 1]) for (int i = 0; i < n; ++ i) a[i] ^= 1;
	int left = 0, right = n + 1;
	while (left < right) {
		int mid = (left + right + 1) >> 1;
		if (check(mid)) left = mid;
		else right = mid - 1;
	}
	if (left == n + 1) puts("1");
	else printf("%d\n", left);
	return 0;
}