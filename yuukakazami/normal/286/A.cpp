#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;
const int MAX_N = int(1e5) + 10;

int p[MAX_N];

int main() {
	int n;
	cin >> n;
	int nGroup = n / 2;
	if (nGroup % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int l = 0, r = n - 1; l + 1 < r - 1; l += 2, r -= 2) {
		//[l,r] and [l+1,r-1]
		//l->l+1->r->r-1->l
		p[l] = l + 1;
		p[l + 1] = r;
		p[r] = r - 1;
		p[r - 1] = l;
	}
	if (n % 2 == 1) {
		p[n / 2] = n / 2;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", p[i] + 1);
	}
	for (int i = 0; i < n; ++i) {
//		if (p[p[i]] != n - i - 1)
//			cerr << "FUCK!" << endl;
		assert(p[p[i]] == n - i - 1);
	}
	puts("");
	return 0;
}