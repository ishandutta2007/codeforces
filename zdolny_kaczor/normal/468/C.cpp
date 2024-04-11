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
const int ML = 19;
LL pow(LL b, int e) {
	if (e == 0)
		return 1;
	else if (e % 2)
		return pow(b, e - 1) * b;
	return pow(b * b, e / 2);
}
LL sum_under(LL a) {
	LL res = 0;
	int digits[ML];
	for (int i = 0; i < ML; ++i) {
		digits[i] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < ML; ++i) {
		int l = 0;
		for (int k = i + 1; k < ML; ++k)
			l += digits[k];
		for (int k = 0; k < digits[i]; ++k) {
			res += (l + k) * pow(10, i) + 4.5 * i * pow(10, i);
		}
	}
	for (int i = 0; i < ML; ++i)
		res += digits[i];
	return res;
}
int digsum(LL a) {
	int res = 0;
	while (a) {
		res += a % 10;
		a /= 10;
	}
	return res;
}
const LL bound = 1.4e16;
int main() {
	LL n;
	scanf("%lld", &n);
	LL low = 0, high = bound, ans = 0;
	while (low <= high) {
		LL med = (low + high) / 2;
		if (sum_under(med) <= n) {
			ans = med;
			low = med + 1;
		}
		else
			high = med - 1;
	}
	low = 1, high = ans;
	LL range = sum_under(ans);
	while (true) {
		if (range == n) {
			printf("%lld %lld\n", low, high);
			assert(n == sum_under(high) - sum_under(low - 1));
			return 0;
		}
		else if (range > n) {
			range -= digsum(low);
			low++;
		}
		else {
			high++;
			range += digsum(high);
		}
	}
}