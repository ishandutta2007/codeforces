#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

int cnt[5000];

int main() {
	int x, n;
	scanf("%d%d", &x, &n);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++ i) {
		int a, n1, n2;
		scanf("%d%d", &a, &n1);
		cnt[n1] = 1;
		if (a == 1) {
			scanf("%d", &n2);
			cnt[n2] = 1;
		}
	}
	int Max = 0, Min = 0;
	vector<int> v; v.clear();
	for (int i = 1; i < x; ++ i) 
		if (!cnt[i]) {
			Max ++;
			v.push_back(i);
		}
	for (int i = 0, j; i < (int)v.size(); i = j) {
		for (j = i + 1; j < (int)v.size() && v[j] == v[i] + 1; ++ j);
		Min += (j - i + 1) / 2;
	}
	printf("%d %d\n", Min, Max);
	return 0;
}