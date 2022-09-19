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
#else
#define debug(...)
#define cerr if(0) cout
#endif
#define cc(x) x.f, x.s
const int MN = 1010, NONE = 0;
int curr[MN];
int main() {
	int m, n, c;
	scanf("%d%d%d", &n, &m, &c);
	int used = 0;
	while (used < n) {
		int x;
		scanf("%d", &x);
		int place = -1;
		if (x <= c / 2) {
			REP(i, n) {
				if (curr[i] == 0) {
					place = i;
					curr[i] = x;
					used++;
					break;
				}
				else if (curr[i] > x) {
					place = i;
					curr[i] = x;
					break;
				}
			}
		}
		else {
			FORD(i, n - 1, 0) {
				if (curr[i] == 0) {
					place = i;
					curr[i] = x;
					used++;
					break;
				}
				else if (curr[i] < x) {
					place = i;
					curr[i] = x;
					break;
				}
			}
		}
		printf("%d\n", place + 1);
		fflush(stdout);
	}
	return 0;
}