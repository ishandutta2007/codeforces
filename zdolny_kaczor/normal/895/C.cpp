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
bool isprime(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}
int primes[19];
int make_mask(int n) {
	int res = 0;
	for (int i = 0; i < 19; ++i)
		while (n % primes[i] == 0) {
			n /= primes[i];
			res ^= (1 << i);
		}
	return res;
}
vector <int> matrix;
const int mod = 1e9 + 7;
int main() {
	int n;
	scanf("%d", &n);
	int cou = 0;
	for (int i = 2; i < 70; ++i)
		if (isprime(i))
			primes[cou++] = i;
	
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		int add = make_mask(x);
		debug("make_mask = %d\n", add);
		for (auto r : matrix)
			mini(add, add ^ r);
		if (add != 0) {
			matrix.push_back(add);
			sort(ALL(matrix));
			reverse(ALL(matrix));
		}
	}
	int ans = 1;
	for (int i = 0; i < n - matrix.size(); ++i) {
		ans *= 2;
		ans %= mod;
	}
	ans--;
	printf("%d\n", ans);
}