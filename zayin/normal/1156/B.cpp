#include <bits/stdc++.h>
using namespace std;
const int N = 120;

char s[N];
int cnt[26];
vector<int> vec;
int m;
int ans[26];
int used[26];

bool dfs(int depth = 0, int pre = 100) {
	if (depth == m) return true;
	for (auto i: vec) {
		if (!used[i] && i != pre+1 && i != pre-1) {
			used[i] = true;
			ans[depth] = i;
			if (dfs(depth+1, i)) return true;
			used[i] = false;
		}
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i++) cnt[s[i]-'a']++;
		vec.clear();
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) vec.push_back(i);	
		}
		m = vec.size();
		memset(used, 0, sizeof used);
		if (dfs()) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < cnt[ans[i]]; j++) {
					putchar('a'+ans[i]);
				}
			}
			puts(""); 
		}
		else {
			puts("No answer");	
		}
	}
}