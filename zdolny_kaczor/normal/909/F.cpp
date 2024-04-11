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
#define debug cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
#define debug if(0) cout
#endif
template <typename T, typename C>
ostream & operator<<(ostream &os, pair<T, C> x) {
	return os << "<" << x.f << ", " << x.s << ">";
}
template <typename T>
auto operator<<(ostream&os, T x) -> typename enable_if<is_same<decltype(x.begin()), decltype(x.end())>::value && !is_same<T, string>::value, ostream &>::type {
	os << "{";
	int cou = 0;
	for (auto c : x) {
		if (cou++)
			os << ", ";
		os << c;
	}
	return os << "}";
}
#define cr << "][" << 
#define rr << "] = " << 
#define cc << "[" <<
#define ao << ' ' 
#define name(a) #a << " = " << (a) ao
#define arr(a, i) #a cc #i rr #a cc i rr a[i] ao
#define arr2(a, i, j) #a cc #i cr #j rr #a cc i cr j rr a[i][j] ao
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc i cr j cr k rr a[i][j][k] ao
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc i cr j cr k cr q rr a[i][j][k][q] ao
template <typename T>
string strmask(T r) {
	string ans;
	REP(i, 8 * (int)sizeof(T)) {
		ans += '0' + !!(((T)1 << i) & r);
		if (i % 5 == 4)
			ans += '.';
	}
	return ans;
}
#if 0 
ostream & operator<< (ostream & os, __int128_t x) {
	if (x < 0) {
		os << '-';
		x = -x;
	}
	if (x >= 10)
		os << x / 10;
	return os << (int)x % 10;
}
ostream & operator<< (ostream & os, __uint128_t x) {
	if (x >= 10)
		os << x / 10;
	return os << (int)x % 10;
}
#endif
#define nmask(a) #a << " = " << strmask(a) ao
void show(const VI & x) {
	if (x.empty())
		printf("NO\n");
	else {
		printf("YES\n");
		FOR(i, 1, siz(x) - 1)
			printf("%d ", x[i]);
		printf("\n");
	}

}
const int LOG = 17;
const int MN = 1 << LOG;
int ans[MN];
int larg(int n) {
	int pow = 1;
	while (pow <= n)
		pow *= 2;
	return pow;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n <= 10) {
		VI all;
		FOR(i, 0, n)
			all.PB(i);
		VI p1, p2;
		do {
			bool zero = false, nonzero = false;
			bool fixed = false;
			FOR(i, 1, n) {
				if (i & all[i])
					nonzero = true;
				else
					zero = true;
				if (all[i] == i)
					fixed = true;
			}
			if (!zero && !fixed)
				p1 = all;
			if (!nonzero && !fixed)
				p2 = all;
		}
		while (next_permutation(1 + ALL(all)));
		show(p2);
		show(p1);
		return 0;
	}
	if (n % 2)
		printf("NO\n");
	else {
		printf("YES\n");
		int nn = n;
		while (nn > 0) {
			int pow = larg(nn);
			debug << name(pow) << name(nn) << endl;
			for (int i = nn; pow - i - 1 <= nn; --i) {
				ans[i] = pow - i - 1;
				debug << "set " << arr(ans, i) << endl;
			}
			nn = pow - nn - 2;
		}
		FOR(i, 1, n) {
			printf("%d ", ans[i]);
			assert((i & ans[i]) == 0);
		}
		printf("\n");
	}
	if ((n & (n - 1)) == 0) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		VI type[LOG];
		FOR(i, 1, n) {
			if (i == 7)
				type[0].PB(i);
			else {
				int highest = 0;
				while (1 << (highest + 1) <= i)
					highest++;
				type[highest].PB(i);
			}
		}
		REP(i, LOG) {
			debug << arr(type, i) << endl;
			REP(k, siz(type[i])) {
				ans[type[i][k]] = type[i][(k + 1) % siz(type[i])];
			}
		}
		FOR(i, 1, n) {
			printf("%d ", ans[i]);
			assert(i & ans[i]);
		}
		printf("\n");
	}
}