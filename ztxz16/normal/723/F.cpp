#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 500005;
const int M = 500005;

int n, m, f[N], a[M], b[M], toS[N], toT[N], val[N], cnt[16];
int s, t, ds, dt;
vector <pair <int, int> > ans;

int find(int i) {
	return f[i] == i ? i : f[i] = find(f[i]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a[i], &b[i]); 
	}
	
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	
	int need = n - 1;
	scanf("%d %d %d %d", &s, &t, &ds, &dt);
	for (int i = 1; i <= m; i++) {
		int aa = find(a[i]), bb = find(b[i]);
		if (aa == s || aa == t || bb == s || bb == t) {
			continue;
		}
		
		if (aa != bb) {
			ans.push_back(make_pair(a[i], b[i]));
			f[aa] = bb;
			need--;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		int aa = find(a[i]), bb = find(b[i]); 
		if (aa == s && bb != t) {
			val[bb] |= 1;
			toS[bb] = b[i];
		}
		
		if (aa == t && bb != s) {
			val[bb] |= 2;
			toT[bb] = b[i];
		}
		
		if (aa != t && bb == s) {
			val[aa] |= 1;
			toS[aa] = a[i];
		}
		
		if (aa != s && bb == t) {
			val[aa] |= 2;
			toT[aa] = a[i];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (i == s || i == t || find(i) != i) {
			continue;
		}
		
		cnt[val[i]]++;
	}
	
	if (cnt[3] == 0) {
		if (cnt[1] + 1 > ds || cnt[2] + 1 > dt) {
			printf("No\n");
		} else {
			printf("Yes\n%d %d\n", s, t);
			for (int i = 0; i < (int)ans.size(); i++) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
			
			for (int i = 1; i <= n; i++) {
				if (i == s || i == t || find(i) != i) {
					continue;
				}
				
				if (val[i] == 1) {
					printf("%d %d\n", s, toS[i]);
				} else {
					printf("%d %d\n", t, toT[i]);
				}
			}
		}
	} else {
		if (cnt[1] + 1 > ds || cnt[2] + 1 > dt || cnt[1] + cnt[2] + cnt[3] + 1 > ds + dt) {
			printf("No\n");
		} else {
			printf("Yes\n");
			for (int i = 0; i < (int)ans.size(); i++) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
			
			bool first = true;
			ds -= (cnt[1] + 1);
			for (int i = 1; i <= n; i++) {
				if (i == s || i == t || find(i) != i) {
					continue;
				}
				
				if (val[i] == 1) {
					printf("%d %d\n", s, toS[i]);
				} else if (val[i] == 2) {
					printf("%d %d\n", t, toT[i]);
				} else if (first) {
					printf("%d %d\n", s, toS[i]);
					printf("%d %d\n", t, toT[i]);
					first = false;
				} else {
					if (ds > 0) {
						ds--;
						printf("%d %d\n", s, toS[i]);
					} else {
						printf("%d %d\n", t, toT[i]);
					}
				}
			}
		}
	}
	
	return 0;
}