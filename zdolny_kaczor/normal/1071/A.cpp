# include <bits/stdc++.h>
using namespace std;
#define FORBITS(i,m)  for(decltype(m)lP6N4Slr=(m),i=lP6N4Slr?ctz(lP6N4Slr):0;lP6N4Slr;lP6N4Slr^=((decltype(m))1<<i),i=ctz(lP6N4Slr))
#define FORDBITS(i,m) for(decltype(m)_6Im=(m),i=_6Im?8*sizeof(m)-clz(_6Im)-1:0;_6Im;_6Im^=((decltype(m))1<<i),i=8*sizeof(m)-clz(_6Im)-1)
#define sim template <class t
#define dor > debug & operator<<(
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<t>(0)) r 1, debug&>::type operator<<(t h) {
sim> struct rge {t h, n;};
sim> rge<t> range(t h, t n) {return rge<t>{h, n};}
sim> auto dud(t *r) -> decltype(cerr << *r, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
	~debug() {cerr << endl;}
	eni(!=) cerr << boolalpha << h; ris;}
	eni(==) ris << range(begin(h), end(h));}
	sim dor rge<t> u) {
		cerr << '{';
		for (t a = u.h; a!= u.n; ++a)
			*this << ", " + 2 * (a == u.h) << *a;
		ris << '}';
	}
	sim, class n dor pair <n,t> r) {ris << "<" << r.first << ", " << r.second << ">";}
	#else
	sim dor const t&) {ris;}
	#endif
};
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
vector <int> A, B;
bool split(int l, int a, int b) {
	if (l == 0) return true;
	if (a >= l) {
		int r = split(l - 1, a - l, b);
		if (r) {
			A.push_back(l);
			return true;
		}
	}
	if (b >= l) {
		int r = split(l - 1, a, b - l);
		if (r) {
			B.push_back(l);
			return true;
		}
	}
	return false;
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int largest = 0;
	while ((largest + 1) * (largest + 2ll) / 2 <= a + b)
		largest++;
	debug << imie(largest);
	while (true) {
		bool r = split(largest, a, b);
		if (r)
			break;
		largest--;
	}
	printf("%d\n", (int)A.size());
	for (int a : A)
		printf("%d ", a);
	printf("\n%d\n", (int)B.size());
	for (int b : B)
		printf("%d ", b);
	printf("\n");
}