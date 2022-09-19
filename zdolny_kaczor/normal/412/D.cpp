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
const int MN = 3e4 + 44;
VI V[MN];
bool poss(int a, int b) {
	int l = 0, h = siz(V[a]) - 1;
	while (l <= h) {
		int m = (l + h) / 2;
		if (V[a][m] == b)
			return false;
		else if (V[a][m] > b)
			h = m - 1;
		else
			l = m + 1;
	}
	return true;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
	}
	FOR(i, 1, n)
		sort(ALL(V[i]));
	VI ans;
	FOR(i, 1, n) {
		VI rest;
		while (!ans.empty()) {
			if (!poss(ans.back(), i)) {
				rest.PB(ans.back());
				ans.pop_back();
			}
			else
				break;
		}
		ans.PB(i);
		while (!rest.empty()) {
			ans.PB(rest.back());
			rest.pop_back();
		}
	}
	for (auto x : ans)
		printf("%d ", x);
	printf("\n");
}