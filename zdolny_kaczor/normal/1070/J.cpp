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
const int d=26;

int n, m, k;

char wcz[nax];
int ile[nax];

ll wyn;

int dp[nax];

void check(int v)
{
	for (int i=0; i<=n; i++)
		dp[i]=0;
	dp[0]=1;
	for (int i=0; i<d; i++)
	{
		if (i==v)
			continue;
		for (int j=n; j>=0; j--)
			if (dp[j] && j+ile[i]<=n)
				dp[j+ile[i]]=1;
	}
	int wol=k-n-m;
	for (int i=n; i>=0 && i+ile[v]>=n; i--)
	{
		if (!dp[i])
			continue;
		int tu=n-i;
		int tam=max(ile[v]-tu-wol, 0);
		wyn=min(wyn, (ll)tu*tam);
	}
}

void test()
{
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", wcz+1);
	for (int i=0; i<d; i++)
		ile[i]=0;
	for (int i=1; i<=k; i++)
		ile[wcz[i]-'A']++;
	wyn=((ll)n)*m;
	for (int i=0; i<d; i++)
		check(i);
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}