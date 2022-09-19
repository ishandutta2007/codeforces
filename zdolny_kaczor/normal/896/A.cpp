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
char first[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char in[] = "What are you doing while sending \"@\"? Are you busy? Will you send \"@\"\?";
const int MN = 1e5 + 44;
LL lens[MN];
char find(int deg, long long pos) {
	if (pos > lens[deg])
		return '.';
	if (deg == 0)
		return first[pos - 1];
	else {
		long long sub_len = lens[deg - 1];
		for (int i = 0; in[i]; ++i) {
			if (in[i] == '@') {
				if (pos <= sub_len)
					return find(deg - 1, pos);
				else
					pos -= sub_len;
			}
			else {
				pos--;
				if (pos == 0)
					return in[i];
			}
		}
	}
}
int main() {
	debug("%d %d\n", strlen(in), strlen(first));
	lens[0] = strlen(first);
	FOR(i, 1, MN - 1)
		lens[i] = min((LL)2e18, (LL)(lens[i - 1] * 2 + strlen(in) - 2));
	for (int i = 1; i <= 300; ++i)
		debug("%c", find(1, i));
	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		LL k;
		scanf("%d%lld", &n, &k);
		printf("%c", find(n, k));
	}
	printf("\n");
	return 0;
}