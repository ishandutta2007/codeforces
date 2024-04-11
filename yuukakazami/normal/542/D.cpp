#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

typedef long long int64;
const int64 INF = 1e14;

const int MAX_N = int(1e6) + 10;
bool is[MAX_N];

int64 MUL(int64 a, int64 b) {
	if (a > INF / b)
		return INF;
	return a * b;
}

bool isPrime(int64 x) {
	if (x < MAX_N)
		return is[x];

	for (int64 i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int64 pow(int64 x, int pw) {
	int64 ret = 1;
	for (int i = 0; i < pw; ++i) {
		ret *= x;
		if (ret > INF)
			return INF;
	}
	return ret;
}

int64 sqrt(int64 x, int pw) {
	double u = pow(x, 1.0 / pw);
	int64 v = int64(u) - 2;
	if (v < 0)
		v = 0;
	while (pow(v, pw) < x)
		++v;
	if (pow(v, pw) == x)
		return v;
	else
		return -1;
}

map<int, vector<int> > mp;
vector<int64> divs;

int64 calcJ(int64 x) {
	int64 ans = 1;
	for (int64 i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			int64 pw = 1;
			while (x % i == 0)
				pw *= i, x /= i;
			ans *= (1 + pw);
		}
	}
	if (x > 1)
		ans *= (1 + x);
	return ans;
}

int main() {
//	int64 x;
//	cin >> x;
//	cout << calcJ(x) << endl;
	int64 A;
	cin >> A;
//	A = calcJ(x);

	fill(is + 2, is + MAX_N, true);
	for (int i = 2; i < MAX_N; ++i) {
		if (is[i])
			for (int j = i + i; j < MAX_N; j += i)
				is[j] = false;
	}

	for (int64 i = 1; i * i <= A; ++i) {
		if (A % i == 0) {
			divs.push_back(i);
			if (i * i < A)
				divs.push_back(A / i);
		}
	}

	sort(divs.begin(), divs.end());
//	cout << divs.size() << endl;

	for (int i = 0; i < divs.size(); ++i) {
//		cout << "HI" << endl;
		int64 x = divs[i];

		int64 ppw = x - 1;
		for (int pw = 1; pw < 50; ++pw) {
			if ((1LL << pw) > ppw)
				break;
			int64 u = sqrt(ppw, pw);
			if (u == -1)
				continue;
			if (isPrime(u)) {
				mp[u].push_back(i);
			}
		}
	}

	vector<int64> am(divs.size(), 0);
	am[0] = 1;

	for (map<int, vector<int> >::iterator e = mp.begin(); e != mp.end(); ++e) {
		vector<int> cur = e->second;

		vector<int64> nam = am;

		for (int it = 0; it < cur.size(); ++it) {
			int64 me = divs[cur[it]];
			int b = 0;
			for (int a = 0; a < am.size(); ++a) {
				int64 v = MUL(divs[a], me);
				while (b < divs.size() && divs[b] < v)
					++b;
				if (b < divs.size() && divs[b] == v) {
					nam[b] += am[a];
				}
			}
		}

		am = nam;
	}

	cout << am.back() << endl;
}