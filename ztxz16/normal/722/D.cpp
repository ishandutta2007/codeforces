#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100005;

multiset <int> lastAns;
priority_queue <int> val;
 
int n, y[N];
 
int ok(int ans) {
	lastAns.clear();
	while (val.size()) {
		val.pop();
	}

	for (int i = 1; i <= n; i++) {
		val.push(y[i]);
	}
	
	while (val.size() > 0) {
		int now = val.top();
		val.pop();
		if (now <= ans && lastAns.find(now) == lastAns.end()) {
			lastAns.insert(now);
		} else if (now == 1) {
			return 0;
		} else {
			val.push(now / 2);
		}
	}
	
	return 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &y[i]);
	}
	
	int ans = 0;
	for (int i = 30; i >= 0; i--) {
		if (!ok(ans + (1 << i) - 1)) {
			ans += (1 << i);
		}
	}

	ok(ans);
	for (set <int> :: iterator it = lastAns.begin(); it != lastAns.end(); ++it) {
		printf("%d ", *it);
	}
	
	printf("\n");
	return 0;
}