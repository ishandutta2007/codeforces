#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 4e5 + 5;
const int kMid = 2e5 + 2;

char s[kMaxN];
int s1[kMaxN], s2[kMaxN];
std::map<ll, int> pos;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int ansl = 0, ansr = n + 1;
		pos.clear(); pos[0] = 0;
		scanf("%s", s + 1);
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
		for(int i = 1; i <= n; ++i) {
			s1[i] = s1[i - 1]; s2[i] = s2[i - 1];
			if(s[i] == 'U') s1[i] = s1[i - 1] + 1;
			if(s[i] == 'D') s1[i] = s1[i - 1] - 1;
			if(s[i] == 'L') s2[i] = s2[i - 1] + 1;
			if(s[i] == 'R') s2[i] = s2[i - 1] - 1;
			ll hash = s1[i] * kMaxN + s2[i];
			if(pos.count(hash)) {
				int l = pos[hash];
				if(i - l < ansr - ansl)
					ansr = i, ansl = l;
			}
			pos[hash] = i;
		}
		if(ansr != n + 1) printf("%d %d\n", ansl + 1, ansr);
		else printf("-1\n");
	}
	return 0;
}