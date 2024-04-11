#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int a[MAXN], b[MAXN], p[MAXN], n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]); p[-- a[i]] = i;
	}
	multiset<int> l, r; l.clear(); r.clear();
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &b[i]);
		b[i] --;
		l.insert(p[b[i]] - i);
	}
	int ld = 0, rd = n;
	for (int i = 0; i < n; ++ i) {
		multiset<int>::iterator it;
		int ret = n;
		if (l.size()) {
			it = l.lower_bound(-ld);
			if (it != l.end()) ret = min(ret, abs(*it + ld));
			if (it != l.begin()) ret = min(ret, abs(*(-- it) + ld));
		}
		
		if (r.size()) {
			it = r.lower_bound(rd);
			if (it != r.end()) ret = min(ret, abs(*it - rd));
			if (it != r.begin()) ret = min(ret, abs(*(-- it) - rd));
		}

		l.erase(l.find(p[b[i]] - i));
		r.insert(p[b[i]] - i);
		ld ++, rd --;
		printf("%d\n", ret);
	}
	return 0;
}