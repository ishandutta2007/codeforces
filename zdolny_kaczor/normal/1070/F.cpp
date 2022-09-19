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

int n;
char wcz[10];

vector <ll> wek[5];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%s%d", wcz, &x);
		int w=('1'-wcz[0])*2+('1'-wcz[1]);
		wek[w].push_back(x);
	}
	for (int i=0; i<4; i++)
	{
		wek[i].push_back(0);
		reverse(wek[i].begin(), wek[i].end());
		sort(wek[i].begin()+1, wek[i].end());
		reverse(wek[i].begin()+1, wek[i].end());
		for (int j=1; j<(int)wek[i].size(); j++)
			wek[i][j]+=wek[i][j-1];
	}
	ll wyn=0;
	int a=wek[0].size()-1;
	int b=wek[1].size()-1;
	int c=wek[2].size()-1;
	int d=wek[3].size()-1;
	if (b<c)
	{
		swap(b, c);
		swap(wek[1], wek[2]);
	}
	for (int i=0; i<=d && i<=a; i++)
	{
		int luz=a-i;
		int x=b;
		int y=c;
		if (x>y+luz)
			x=y+luz;
		wyn=max(wyn, wek[0][a]+wek[3][i]+wek[1][x]+wek[2][y]);
	}
	
	printf("%lld\n", wyn);
	return 0;
}