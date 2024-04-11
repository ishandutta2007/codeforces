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
#define cerr if(0) cerr
#endif
#define cc(x) x.f, x.s
int nn() {
	static int x = 0;
	return ++x;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int hub = nn();
	vector <int> in;
	for (int i = 0; i < k; ++i)
		in.push_back(nn());
	int pos = 0;
	int len = 2;
	VPII ans;
	while (true) {
		for (auto c : in)
			debug("%d ", c);
		debug("\n");
		int w = nn();
		if (w > n)
			break;
		if (pos == 0 || pos == 1)
			len++;
		ans.PB(MP(in[pos], w));
		in[pos] = w;
		pos++;
		if (pos >= in.size())
			pos = 0;
	}
	for (auto x : in) {
		ans.emplace_back(x, hub);
	}
	printf("%d\n", len);
	for (auto x : ans)
		printf("%d %d\n", cc(x));
}