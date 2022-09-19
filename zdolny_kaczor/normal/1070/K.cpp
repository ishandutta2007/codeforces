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

using ll=long long;
using pii=pair<int,int>;
const int nax=1000*1007;

int n, k;
ll sum;
ll tab[nax];

int wyn[nax];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		tab[i]+=tab[i-1];
	}
	if (tab[n]%k)
	{
		printf("No\n");
		return 0;
	}
	sum=tab[n]/k;
	for (int i=1; i<=n; i++)
	{
		if (!(tab[i]%sum))
		{
			wyn[tab[i]/sum]=i;
		}
	}
	for (int i=1; i<=k; i++)
	{
		if (!wyn[i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i=1; i<=k; i++)
		printf("%d ", wyn[i]-wyn[i-1]);
	printf("\n");
	return 0;
}