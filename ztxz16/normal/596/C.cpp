#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;

int n, w[N], ans[N], x[N], y[N], deg[N];
vector <int> v[N];
map <int, int> sNow;
map <pair <int, int>, int> s;

void add(int a, int b) {
	deg[b]++;
	v[a].push_back(b);
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		s[make_pair(x[i], y[i])] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		pair <int, int> now = make_pair(x[i], y[i]);
		if (now.first > 0) {
			add(i, s[make_pair(now.first - 1, now.second)]);
		}
		
		if (now.second > 0) {
			add(i, s[make_pair(now.first, now.second - 1)]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			sNow[y[i] - x[i]] = i;
		}
	}
	
	for (int i = n; i >= 1; i--) {
		if (sNow.find(w[i]) == sNow.end()) {
			printf("NO\n");
			return 0;
		}
		
		int now = sNow[w[i]];
		sNow.erase(w[i]);
		ans[i] = now;
		for (int j = 0; j < (int)v[now].size(); j++) {
			int z = v[now][j];
			if ((--deg[z]) == 0) {
				sNow[y[z] - x[z]] = z;
			}
		}
	}
	
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", x[ans[i]], y[ans[i]]);
	}
	
	return 0;
}