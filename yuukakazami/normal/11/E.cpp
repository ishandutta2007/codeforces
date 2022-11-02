#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

double eval(string s) {
	int n = s.size(), p = 0, q = 0, cnt = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		char ch = (q & 1) ? 'R' : 'L';
		if (s[i] == 'X')
			q++;
		else if (s[i] == ch)
			p++, q++, cur = 0;
		else
			p++, q += 2, cnt += cur, cur = !cur;
	}
	if (q & 1)
		q++, cnt += cur;
	if (p * 2 > q)
		p -= cnt, q -= 2 * cnt;
	return 1.0 * p / q;
}

int main() {
	string s, t;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (i > 0 && s[i] == s[i - 1] && s[i] != 'X')
			t += 'X';
		t += s[i];
	}
	double ans;
	if (s[0] == s[s.size() - 1] && s[0] != 'X')
		ans = max(eval(t + 'X'), eval('X' + t));
	else
		ans = eval(t);
	ans = floor(ans * 1e8) / 1e8;
	printf("%0.6lf\n", ans * 1e2);
	return 0;
}