//Maciej Houbowicz
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
#define div astnhoe
const int MN = 1e6 + 44;
bool div[MN];
void sieve() {
	for (int i = 2; i < MN; ++i)
		if (!div[i]) {
			for (int k = i * 2; k < MN; k += i)
				div[k] = true;
		}
}
bool prime(int x) {
	return !div[x];
}
int inv(int x) {
	int res = 0;
	while (x) {
		res = res * 10 + (x % 10);
		x /= 10;
	}
	return res;
}
int main() {
	sieve();
	int n;
	scanf("%d", &n);
	int p = 1;
	while (n) {
		p++;
		if (prime(p) && prime(inv(p)) && p != inv(p))
			n--;
	}
	printf("%d\n", p);
}