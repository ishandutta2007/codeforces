#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

const int N = 100005;
const int INF = 1000000000;

int left[N << 2], right[N << 2], tag[N << 2], minValue[N << 2], leftValue[N << 2];
int n, a[N], b[N], c[N], val[N];
map <int, int> setA, setB, setC;

void make(int l, int r, int i) {
	int mid = ((l + r) >> 1), lc = (i << 1), rc = (lc | 1);
	left[i] = l, right[i] = r;
	if (l == r) {
		minValue[i] = l + val[l];
		leftValue[i] = val[l];
		return;
	}
	
	make(l, mid, lc);
	make(mid + 1, r, rc);
	leftValue[i] = val[l];
	minValue[i] = min(minValue[lc], minValue[rc]);
}

void cover(int i, int v) {
	leftValue[i] = v;
	minValue[i] = left[i] + v;
	tag[i] = v;
}

void down(int i) {
	if (tag[i]) {
		int lc = (i << 1), rc = (lc | 1);
		cover(lc, tag[i]);
		cover(rc, tag[i]);
		tag[i] = 0;
	}
}

void modify(int l, int r, int i, int v) {
	if (l > right[i] || r < left[i]) {
		return;
	}
	
	if (l <= left[i] && r >= right[i] && v >= leftValue[i]) {
		cover(i, v);
		return;
	}
	
	if (left[i] == right[i]) {
		return;
	}
	
	down(i);
	int lc = (i << 1), rc = (lc | 1);
	if (leftValue[rc] < v) {
		modify(l, r, lc, v);
	}
	
	modify(l, r, rc, v);
	minValue[i] = min(minValue[lc], minValue[rc]);
	leftValue[i] = leftValue[lc];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		if (setA.find(a[i]) == setA.end()) {
			setA[a[i]] = i;
		}
		
		if (setB.find(b[i]) == setB.end()) {
			setB[b[i]] = i;
		}
		
		if (setC.find(c[i]) == setC.end()) {
			setC[c[i]] = i;
		}
	}
	
	for (int i = n; i >= 1; i--) {
		if (setC[c[i]] == i && setA.find(c[i]) == setA.end() && setB.find(c[i]) == setB.end()) {
			val[n] = i;
			break;
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		val[i] = val[i + 1];
		if (setA.find(b[i + 1]) == setA.end() && setB[b[i + 1]] == i + 1) {
			if (setC.find(b[i + 1]) == setC.end()) {
				val[i] = INF;
			} else {
				val[i] = max(val[i], setC[b[i + 1]]);
			}
		}
	}
	
	make(0, n, 1);
	int ans = n + minValue[1];
	for (int i = n; i >= 1; i--) {
		if (setA[a[i]] == i) {
			if (setB.find(a[i]) != setB.end()) {
				if (setC.find(a[i]) != setC.end()) {
					modify(0, setB[a[i]] - 1, 1, setC[a[i]]);
				} else {
					modify(0, setB[a[i]] - 1, 1, INF);
				}
			} else if (setC.find(a[i]) != setC.end()) {
				modify(0, n, 1, setC[a[i]]);
			} else {
				break;
			}
		}
		
		ans = min(ans, i - 1 + minValue[1]);
	}
	
	printf("%d\n", ans);
	return 0;
}