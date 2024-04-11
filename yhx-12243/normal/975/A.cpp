#include <bits/stdc++.h>
#define N 1005
using namespace std;

int n;
string s[N];

int main() {
	int i;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
		s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
	}
	sort(s, s + n);
	printf("%d\n", unique(s, s + n) - s);
	return 0;
}