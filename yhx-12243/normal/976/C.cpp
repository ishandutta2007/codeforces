#include <bits/stdc++.h>
#define N 300005
using namespace std;

struct seg {
	int l, r, id;
	seg * read(int id0) {scanf("%d%d", &l, &r); id = id0; return this;}
	inline bool operator < (const seg &B) const {return l < B.l || l == B.l && r > B.r;}
}s[N];

int n;

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) s[i].read(i + 1);
	sort(s, s + n);
	for (i = 1; i < n; ++i)
		if (s[i - 1].r >= s[i].r)
			return printf("%d %d\n", s[i].id, s[i - 1].id), 0;
	puts("-1 -1");
	return 0;
}