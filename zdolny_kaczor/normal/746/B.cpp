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
#define left satnoheu
const int MN = 2e3 + 44;
int per[MN];
int left[MN];
char word[MN];
int main() {
	int n;
	scanf("%d%s", &n, word);
	for (int i = 0; i < n; ++i) {
		left[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		int size = n - i;
		int curr = (size - 1) / 2;
		debug("in %d\n", i);
		for (int k = 0; k < size; ++k) {
			debug("%d ", left[k]);
		}
		debug("\n");
		per[left[curr]] = i;
		for (int i = curr; i < size; ++i) {
			left[i] = left[i + 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%c", word[per[i]]);
	}
	printf("\n");
}