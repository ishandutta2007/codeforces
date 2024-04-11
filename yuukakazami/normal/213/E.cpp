#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_L_STR = int(2e5) + 10;
int str[MAX_L_STR], pet[MAX_L_STR];
int strLen, petLen, n, m;
inline void scanInt(int&x) {
	char ch;
	while (ch = getchar(), ch < '0' || ch > '9')
		;
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0';
}

void readInput() {
	cin >> petLen >> strLen;
	for (int i = 0; i < petLen; ++i) {
		int x;
		scanInt(x);
		pet[x - 1] = i;
	}
	for (int i = 0; i < strLen; ++i) {
		int x;
		scanInt(x);
		str[x - 1] = i;
	}
}

struct TA {
	int a[MAX_L_STR], n;
	void init(int _n) {
		n = _n;
		memset(a, 0, sizeof(int) * n);
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	int calc(int p) {
		int ret = 0;
		for (p++; p; p -= p & -p)
			ret += a[p - 1];
		return ret;
	}
};
TA ta;
int cntSmall[MAX_L_STR];

void debug(int a[], int n) {
//  for (int i = 0; i < n; ++i) {
//      cout << a[i] << " ";
//  }
//  cout << endl;
}

void prepare() {
	ta.init(petLen);
	for (int i = 0; i < petLen; ++i) {
		cntSmall[i] = ta.calc(pet[i] - 1);
		ta.add(pet[i], 1);
	}
	debug(pet, petLen);
}

int next[MAX_L_STR];
int L, R; //[L,R)
void moveTo(int seq[], int newL, int newR) {
	for (int i = L; i < newL; ++i) {
		ta.add(seq[i], -1);
	}
	for (int i = R; i < newR; ++i) {
		ta.add(seq[i], 1);
	}
	L = newL, R = newR;
}

void calcNext() {
	next[0] = -1;
	L = 0, R = 0;
	ta.init(petLen);
	for (int i = 1; i < petLen; ++i) {
		int t = next[i - 1];
		while (t != -1) {
			moveTo(pet, i - t - 1, i);
			if (cntSmall[t + 1] == ta.calc(pet[i] - 1)) {
				++t;
				break;
			}
			t = next[t];
		}
		if (t == -1)
			t = 0;
		next[i] = t;
	}
	debug(next, petLen);
}

void calcKMP() {
	L = 0, R = 0;
	int t = -1;
	static int ans[MAX_L_STR], nAns;
	nAns = 0;
	ta.init(strLen);
	for (int i = 0; i < strLen; ++i) {
		while (t != -1) {
			moveTo(str, i - t - 1, i);
			if (cntSmall[t + 1] == ta.calc(str[i] - 1)) {
				++t;
				break;
			}
			t = next[t];
		}
		if (t == -1)
			t = 0;
		if (t == petLen - 1) {
			ans[nAns++] = i - petLen + 2;
			t = next[t];
		}
	}

	printf("%d\n", nAns);
}

void work() {
	prepare();
	calcNext();
	calcKMP();
}

int main() {
	readInput();
	work();
	return 0;
}