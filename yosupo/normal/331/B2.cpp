#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <deque>

using namespace std;
const int MAX_N = 300000;
int bit[MAX_N + 1], n;

int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x) {
    if (!i) return;
	while (i <= n) {
		bit[i] += x;
		i += i & -i;
	}
}

int main() {
	cin >> n;
	int a[MAX_N+1], pos[MAX_N+2];
	fill(pos, pos+MAX_N+2, 1e9);
    pos[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		if (pos[i] > pos[i+1]) {
			add(i, 1);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int p, x, y;
		cin >> p >> x >> y;
		if (p == 1) {
			if (x > y) {
				swap(x, y);
			}
			cout << sum(y-1) - sum(x-1) + 1 << endl;
		} else {
            int xb = x, yb = y;
            x = a[x];
            y = a[y];
            swap(a[xb], a[yb]);
			add(x-1, sum(x-2)-sum(x-1));
			add(x, sum(x-1)-sum(x));
			add(x+1, sum(x)-sum(x+1));
			add(y-1, sum(y-2)-sum(y-1));
			add(y, sum(y-1)-sum(y));
			add(y+1, sum(y)-sum(y+1));
			swap(pos[x], pos[y]);
            set<int> s;
            s.insert(x-1);
            s.insert(x);
            s.insert(x+1);
            s.insert(y-1);
            s.insert(y);
            s.insert(y+1);
            for (int j: s) {
                if (pos[j] > pos[j+1]) {
                    add(j, 1);
                }
            }
		}
	}
	return 0;
}