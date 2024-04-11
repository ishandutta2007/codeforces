#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3;
int n, m;
char s[maxn + 3], t[maxn + 3];
bool vis[maxn + 3];
vector<int> S[maxn + 3];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int k = 1; ; k++) {
		memset(vis, false, sizeof(vis));
		int p = 1, q = n;
		bool flag = false;
		while (p < q) {
			while (p <= n && s[p] != '(') p++;
			while (q >= 1 && s[q] != ')') q--;
			if (p < q && s[p] == '(' && s[q] == ')') {
				flag = true;
				S[k].push_back(p), S[k].push_back(q);
				vis[p] = vis[q] = true;
				p++, q--;
			} else {
				break;
			}
		}
		if (flag) {
			sort(S[k].begin(), S[k].end());
			m = 0;
			for (int i = 1; i <= n; i++) {
				if (!vis[i]) t[++m] = s[i];
			}
			n = m, memcpy(s, t, sizeof(s));
		} else {
			printf("%d\n", k - 1);
			for (int i = 1; i < k; i++) {
				printf("%lu\n", S[i].size());
				for (int j = 0; j < S[i].size(); j++) {
					printf("%d%c", S[i][j], " \n"[j == S[i].size() - 1]);
				}
			}
			break;
		}
	}
	return 0;
}