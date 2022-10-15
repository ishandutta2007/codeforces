#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;

void out() {
	cout << "IMPOSSIBLE\n";
}

vector<vi> v;

bool check(int i, int j) {
	return i >= 0 && j >= 0 && i < (int)v.size() && j < (int)v[0].size();
}

int choose (const vii & x) {
	int t = -1;
	for (int i = 0; i < x.size(); ++i)
		if (v[x[i].first][x[i].second] != -1)
			t = v[x[i].first][x[i].second];
	if (t != -1)
		return t;
	vector<int> st(26, 0);
	for (int i = 0; i < x.size(); ++i) {
		int l1 = x[i].first, l2 = x[i].second;
		for (int k1 = -1; k1 <= 1; k1 += 1) for (int k2 = -1; k2 <= 1; k2 += 1)
			if ((k1 + k2 + 4) % 2 == 1 && check(l1 + k1, l2 + k2)) if (v[l1 + k1][l2 + k2] != -1)
				st[v[l1 + k1][l2 + k2]] = 1;
	}
	for (int i = 0; i < st.size(); ++i)
		if (st[i] == 0)
			return i;
	return 25;
}

void write (const vii & x) {
	int t = choose(x);
	for (int i = 0; i < x.size(); ++i)
		v[x[i].first][x[i].second] = t;
}

int main() {
	int n, m, a, b, c;
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	if (n % 2 == 1 && m % 2 == 1) {
		out();
		return 0;
	}
	v.resize(n);
	for (int i = 0; i < n; ++i)
		v[i].assign(m, -1);
	if (n % 2 == 1) {
		if (a < m / 2) {
			out();
			return 0;
		}
		a -= m / 2;
		for (int i = 0; i < m; i += 2) {
			vii toPush;
			toPush.push_back(make_pair(n - 1, i));
			toPush.push_back(make_pair(n - 1, i + 1));
			write(toPush);
		}
		--n;
	}
	if (m % 2 == 1) {
		if (b < n / 2) {
			out();
			return 0;
		}
		b -= n / 2;
		for (int i = 0; i < n; i += 2) {
			vii toPush;
			toPush.push_back(make_pair(i, m - 1));
			toPush.push_back(make_pair(i + 1, m - 1));
			write(toPush);
		}
		--m;
	}
	for (int i = 0; i < n; i += 2) for (int j = 0; j < m; j += 2) {
		vii toPush;
		if (c > 0) {
			--c;
			toPush.push_back(make_pair(i, j));
			toPush.push_back(make_pair(i + 1, j));
			toPush.push_back(make_pair(i, j + 1));
			toPush.push_back(make_pair(i + 1, j + 1));
			write(toPush);
		} else if (a > 1) {
			a -= 2;
			toPush.push_back(make_pair(i, j));
			toPush.push_back(make_pair(i, j + 1));
			write(toPush);
			toPush.resize(0);
			toPush.push_back(make_pair(i + 1, j));
			toPush.push_back(make_pair(i + 1, j + 1));
			write(toPush);
		} else if (b > 1) {
			b -= 2;
			toPush.push_back(make_pair(i, j));
			toPush.push_back(make_pair(i + 1, j));
			write(toPush);
			toPush.resize(0);
			toPush.push_back(make_pair(i, j + 1));
			toPush.push_back(make_pair(i + 1, j + 1));
			write(toPush);
		} else {
			out();
			return 0;
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j)
			printf("%c", (char)(v[i][j] + 'a'));
		cout << endl;
	}
	return 0;
}