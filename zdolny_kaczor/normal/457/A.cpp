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
#define getwait getchar
#else
#define debug(...)
#define debug2(...)
#define getwait()
#endif
#define next nexstaoe
const int MN = 1e5 + 44;
char a[MN], b[MN];
void parse(char in[]) {
	int n = strlen(in);
	for (int i = 0; i < n; ++i)
		in[i] -= '0';
	reverse(in, in + n);
	for (int i = n - 1; i > 0; --i) {
		for (int k = i; in[k] && in[k - 1]; k += 2) {
			in[k] = in[k - 1] = 0;
			in[k + 1] = 1;
		}
	}
}
int main() {
	scanf("%s%s", a, b);
	parse(a);
	parse(b);
	for (int i = MN - 1; i >= 0; --i) {
		if (a[i] != b[i]) {
			if (a[i] > b[i])
				printf(">\n");
			else
				printf("<\n");
			return 0;
		}
	}
	printf("=\n");
}