#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;
typedef long long int64;

int n, d, S;
int c[MAX_N], f[MAX_N], l[MAX_N];

pair<int, int> calc1() {
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		if (l[i] >= d && c[i] == 0)
			a.push_back(f[i]);
	}
	sort(a.begin(), a.end());
	int S = ::S;
	int mxMove = 0, minNeed = 0;
	for (vector<int>::iterator e = a.begin(); e != a.end(); ++e) {
		S -= *e;
		if (S >= 0)
			++mxMove, minNeed += *e;
		else
			break;
	}
	return make_pair(mxMove, minNeed);
}

pair<int, int> calc2() {
	int S = ::S;

	int mxMove = 0;
	int minNeed = 0;
	int sumC = 0;

	for (int i = 0; i < n; ++i) {
		sumC += c[i];
		if (sumC > n)
			sumC = n;
	}
	//find mxNeed

	vector<int> cA, cB; //==0,>0
	for (int i = 0; i < n; ++i) {
		if (l[i] >= d) {
			if (c[i] == 0)
				cA.push_back(f[i]);
			else
				cB.push_back(f[i]);
		}
	}
	if (!cB.empty())
		sort(cB.begin(), cB.end());
	if (cB.size() == 0 || cB[0] > S) {
		sort(cA.begin(), cA.end());
		for (vector<int>::iterator e = cA.begin(); e != cA.end(); ++e) {
			S -= *e;
			if (S >= 0) {
				++mxMove;
				minNeed += *e;
			} else
				break;
		}
		return make_pair(mxMove, minNeed);
	}

	int oldS = S;
	S -= cB[0];
	int nRoot = 1;
	for (int i = 1; i < cB.size(); ++i) {
		cA.push_back(cB[i]);
	}
	sort(cA.begin(), cA.end());
	for (vector<int>::iterator e = cA.begin(); e != cA.end(); ++e) {
		S -= *e;
		if (S >= 0) {
			++nRoot;
		} else
			break;
	}

	mxMove = min(n, nRoot + sumC);

	int rootNeed = max(mxMove - sumC, 1);

	cA.clear();
	cB.clear();
	for (int i = 0; i < n; ++i) {
		if (l[i] >= d) {
			if (c[i] == 0)
				cA.push_back(f[i]);
			else
				cB.push_back(f[i]);
		}
	}
	sort(cB.begin(), cB.end());
	minNeed += cB[0];
	for (int i = 1; i < cB.size(); ++i) {
		cA.push_back(cB[i]);
	}
	sort(cA.begin(), cA.end());
	for (int i = 0; i < rootNeed - 1; ++i) {
		minNeed += cA[i];
	}

	return make_pair(mxMove, minNeed);
}

int main() {
	cin >> n >> d >> S;

	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", c + i, f + i, l + i);
	}

	pair<int, int> a = calc1(), b = calc2();
	if (b.first > a.first || (b.first == a.first && b.second < a.second))
		a = b;

	cout << a.first << " " << a.second << endl;

	return 0;
}