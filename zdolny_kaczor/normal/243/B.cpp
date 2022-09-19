#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int MN = 1e5 + 44;
VI graf[MN];
PII e[MN];
int main() {
	int n, m, h, t;
	scanf("%d%d%d%d", &n, &m, &h, &t);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].PB(b);
		graf[b].PB(a);
		e[i] = MP(a, b);
	}
	for (int i = 1; i <= n; ++i)
		sort(graf[i].begin(), graf[i].end());
	for (int i = 0; i < m; ++i) {
		int a = e[i].f;
		int b = e[i].s;
		for (int k = 0; k < 2; ++k) {
			if (graf[a].size() > h && graf[b].size() > t) {
				int inter = 0;
				for (int p = 0, q = 0; p < graf[a].size() && q < graf[b].size(); ) {
					if (graf[a][p] < graf[b][q])
						p++;
					else if (graf[a][p] == graf[b][q]) {
						inter++;
						p++;
						q++;
					}
					else
						q++;
				}
				if (graf[a].size() + graf[b].size() - inter >= h + t + 2) {
					VI aa, bb, both;
					int p, q;
					for (p = 0, q = 0; p < graf[a].size() && q < graf[b].size(); ) {
						if (graf[a][p] < graf[b][q]) {
							aa.PB(graf[a][p]);
							p++;
						}
						else if (graf[a][p] == graf[b][q]) {
							both.PB(graf[a][p]);
							p++;
							q++;
						}
						else {
							bb.PB(graf[b][q]);
							q++;
						}
					}
					for (int i = p; i < graf[a].size(); ++i)
						aa.PB(graf[a][i]);
					for (int i = q; i < graf[b].size(); ++i)
						bb.PB(graf[b][i]);
					printf("YES\n");
					printf("%d %d\n", a, b);
					for (int i = 0; i < h; ++i) {
						int x;
						if (aa.size()) {
							x = aa.back();
							aa.pop_back();
						}
						else {
							x = both.back();
							both.pop_back();
						}
						if (x == a || x == b) {
							i--;
						}
						else {
							printf("%d ", x);
						}
					}
					printf("\n");
					for (int i = 0; i < t; ++i) {
						int x;
						if (both.size()) {
							x = both.back();
							both.pop_back();
						}
						else {
							x = bb.back();
							bb.pop_back();
						}
						if (x == a || x == b)
							i--;
						else
							printf("%d ", x);
					}
					return 0;
				}
			}
			swap(a, b);
		}
	}
	printf("NO\n");
}