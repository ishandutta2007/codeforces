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

int main() {
	int n;
	scanf("%d", &n);
	vector<vi > v(n);
	vector<vi > r(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
		r[a - 1].push_back(c);
		r[b - 1].push_back(-c);
		sum += c;
	}
	int prev = 0;
	int cur = v[0][0];
	int s = max(r[0][0], 0);
	while (cur != 0) {
		int l = 0;
		if (v[cur][l] == prev)
			l = 1;
		s += max(0, r[cur][l]);
		prev = cur;
		cur = v[cur][l];
	}
	printf("%d\n", min(s, sum - s));
	return 0;
}