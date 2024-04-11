#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;
const int MAX_LEN = 70000 + 10;
int n, s;
bitset<MAX_LEN>* dp[MAX_LEN];
bitset<MAX_LEN> am;
bitset<MAX_LEN> memo[5000], *cur;

struct Bag {
	int idx, size;
	bool operator<(const Bag&o) const {
		return size < o.size;
	}
};

int a[MAX_LEN];
Bag bags[MAX_LEN];
int child[MAX_LEN];

void update(int l, int r) {
	cur = memo, am = *dp[l];
	for (int k = l + 1; k < r; ++k) {
		am |= am << bags[k - 1].size;
		dp[k] = cur++;
		*dp[k] = am;
	}
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
//		cin >> a[i];
		bags[i].idx = i;
		cin >> bags[i].size;
		a[i] = bags[i].size;
	}
	sort(bags, bags + n);
	int mx = bags[n - 1].size;
	if (s < mx) {
		puts("-1");
		return 0;
	}
	am.reset(), am[0] = true;
	--n;

	int sqrtN = sqrt(n) + 1;
	for (int i = 0; i < n; ++i) {
		if (i % sqrtN == 0) {
			dp[i] = new bitset<MAX_LEN>;
			*dp[i] = am;
		}
		am |= am << bags[i].size;
	}

	int rem = s - mx;
	if (n == 0 && rem > 0) {
		puts("-1");
		return 0;
	}
//	cerr << rem << endl;
	vector<Bag> used;

	for (int i = n - 1; i >= 0; --i) {
		if (dp[i] == 0) {
			update(i / sqrtN * sqrtN, i + 1);
		}
		bitset<MAX_LEN>&ref = *dp[i];
		if (ref[rem])
			continue;
		int cur = bags[i].size;
		if (rem >= cur && ref[rem - cur]) {
//			arr.push_back();
			used.push_back(bags[i]);
			rem -= cur;
			continue;
		}

//		cout << i << " " << rem << endl;
		puts("-1");
		return 0;
	}

	used.push_back(bags[n]);
	//construct
	static bool usedIdx[MAX_LEN];

	for (int i = 0; i < used.size(); ++i) {
		usedIdx[used[i].idx] = true;
	}

	memset(child, -1, sizeof child);

	vector<Bag> other;
	for (int i = 0; i < n; ++i) {
		if (!usedIdx[bags[i].idx])
			other.push_back(bags[i]);
	}

//	cerr << other.size() << endl;
	for (int i = 0; i < other.size(); ++i) {
		if (i + 1 < other.size()) {
			child[other[i + 1].idx] = other[i].idx;
		} else {
			child[bags[n].idx] = other[i].idx;
		}
	}

	for (int i = 0; i <= n; ++i) {
		if (child[i] == -1) {
			cout << a[i] << " " << 0 << endl;
		} else {
			cout << a[i] - a[child[i]] << " " << 1 << " " << child[i] + 1
					<< endl;
		}
	}

	return 0;
}