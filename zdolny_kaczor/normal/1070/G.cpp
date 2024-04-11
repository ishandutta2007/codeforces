# include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define sim template <class c
#define dor >debug & operator<< (
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug &>::type operator<< (c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c * x) -> decltype(cerr << *x, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << endl;}
eni(==) ris << range(begin(i), end(i));}
eni(!=) cerr << i; ris;}
sim dor rge<c> x) {
	cerr << "[";
	for (c it = x.b; it != x.e; ++it)
		*this << ", " + 2 * (x.b == it) << *it;
	ris << "]";
}
sim, class b dor pair <c,b> x) {ris << "(" << x.first << ", " << x.second << ")";}
#else
sim dor const c&) {ris;}
#endif
};
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) << ": " << a[i] << "] " 
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] " 
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "

int n, m;
const int M = 107;
int poz[M];
int h[M];

int war[M];
int tab[M];

bool daSie(int u, int s) {
	int bil = h[u];
	u = poz[u];
	while (u != s) {
		bil += tab[u];
		if (bil < 0) return false;
		if (u > s) u--;
		else u++;
	}
	
	bil += tab[u];
	if (bil < 0) return false;
	return true;
}

void zeruj(int i, int j) {
	if (i > j) swap(i, j);
	for (int k = i; k <= j; ++k) tab[k] = 0;
}

vector <int> solve(int s) {
	for (int i = 1; i <= n; ++i) tab[i] = war[i];
	vector <int> boh;
	for (int i = 1; i <= m; ++i) boh.push_back(i);
	vector <int> res;
	
	while (!boh.empty()) {
		int kto = 0;
		for (int u : boh) {
			if (daSie(u, s)) {
				kto = u;
				break;
			}
		}
		
		if (!kto) return vector <int> ();
		
		boh.erase(find(boh.begin(), boh.end(), kto));
		zeruj(poz[kto], s);
		res.push_back(kto);
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &poz[i], &h[i]);
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &war[i]);
	
	for (int s = 1; s <= n; ++s) {
		vector <int> res = solve(s);
		if (!res.empty()) {
			printf("%d\n", s);
			for (int u : res) printf("%d ", u);
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}