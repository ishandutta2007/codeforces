#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 50000 + 10;
const int MOD = 1000000007;
int n;
long long m;
int a[MAX_N];

struct Trie {
	int cnt, sum;
	Trie*ch[2];
	int cntb[2][32];
	Trie() {
		cnt = 0;
		memset(ch, 0, sizeof ch);
		sum = 0;
		memset(cntb, 0, sizeof cntb);
	}
}*root = new Trie;

void add(int x) {
	Trie*a = root;
	for (int i = 30; i >= -1; --i) {
		int me = x >> i & 1;
		++a->cnt;
		a->sum += x;
		if (a->sum >= MOD)
			a->sum -= MOD;
		for (int j = 0; j <= 30; ++j) {
			a->cntb[x >> j & 1][j]++;
		}
		if (i == -1)
			break;
		if (a->ch[me] == 0) {
			a->ch[me] = new Trie;
		}
		a = a->ch[me];
	}
}

long long evalSet(int x, Trie*a) {
	long long ans = 0;
	for (int i = 0; i <= 30; ++i) {
		int me = x >> i & 1;
		ans += (1LL * a->cntb[!me][i]) << i;
		ans %= MOD;
	}
	return ans;
}

long long calc(int mid) {
	long long cnt = 0;
	for (int i = 0; i < n; ++i) {
		Trie*u = root;
		for (int j = 30; j >= 0; --j) {
			int me = (a[i] >> j & 1);
			if (~mid >> j & 1) { //0
				cnt += u->ch[!me] ? u->ch[!me]->cnt : 0;
				u = u->ch[me];
			} else { //1
				u = u->ch[!me];
			}
			if (!u)
				break;
		}
		if (u) {
			cnt += u->cnt;
		}
	}
	if (mid == 0)
		cnt -= n;
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		add(a[i]);
	}
	int l = 0, r = (1 << 30) + 2;
	while (l + 1 < r) {
		int mid = (1LL * l + r) / 2;
		//count those >=mid
		long long cnt = calc(mid);
		if (cnt >= m * 2)
			l = mid;
		else
			r = mid;
	}
	//>=l
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		Trie*u = root;
		for (int j = 30; j >= 0; --j) {
			int me = (a[i] >> j & 1);
			if (~l >> j & 1) { //0
//				cnt += u->ch[!me] ? u->ch[!me]->cnt : 0;
				if (u->ch[!me]) {
					ans += evalSet(a[i], u->ch[!me]);
					ans %= MOD;
				}
				u = u->ch[me];
			} else { //1
				u = u->ch[!me];
			}
			if (!u)
				break;
		}
		if (u) {
			ans += evalSet(a[i], u);
			ans %= MOD;
		}
	}
	long long bad = calc(l) - m * 2;
	ans -= bad * l;
	ans %= MOD;
	if (ans < 0)
		ans += MOD;
	ans *= (MOD + 1) / 2;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}