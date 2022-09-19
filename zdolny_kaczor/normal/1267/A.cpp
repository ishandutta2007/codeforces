#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair <m,c>r){ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c&){ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair <int, int>;
using ll = long long;
typedef pair<ll, ll> Pll;
int n;
const int maxn = 3e5;
ll T[maxn];
ll A[maxn];
ll B[maxn];
int main() {
	scanf("%d", &n);
	vector<Pll> events;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld%lld%lld", &A[i], &B[i], &T[i]);
		events.push_back({A[i], i});
	}
	T[0] = 1;
	events.push_back({(ll)1e18, 0});
	sort(events.begin(), events.end());
	ll res = 0;
	ll tm = 0; // kiedy skoczyem klepa ostatni miecz
	ll tm2 = -1; // kiedy skocz kolejny;
	typedef priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
	pq kolejka;
	for(Pll ev : events)
	{
		if(tm2 == -1 || tm2 <= ev.first)
		{
			if(tm2 != -1)
			{
				++res;
				tm = tm2;
			}
			while(true)
			{
				while(!kolejka.empty() && tm + kolejka.top().first > B[kolejka.top().second])
					kolejka.pop();
				if(kolejka.empty())
				{
					tm = ev.first;
					tm2 = -1;
					break;
				}
				ll koniec = min(ev.first, B[kolejka.top().second]);
				ll miecze = (koniec - tm) / kolejka.top().first;
				if(miecze == 0)
				{
					tm2 = tm + kolejka.top().first;
					break;
				}
				res += miecze;
				tm += miecze * kolejka.top().first;
			}
		}
		if(tm2 == -1 || tm2 > ev.first + T[ev.second])
		{
			tm = ev.first;
			tm2 = ev.first + T[ev.second];
		}
		kolejka.push({T[ev.second], ev.second});
	}
	printf("%lld\n", res);
}