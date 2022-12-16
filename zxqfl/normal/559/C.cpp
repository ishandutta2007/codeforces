#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rint(x);
#define rfloat(x) scanf("%lf", &(x))

#ifndef ONLINE_JUDGE
const bool DEBUG = true;
#define Db(x...)   ({ if (DEBUG) { cout << "Debug["; DB, #x, ":", x, "]\n"; } })
template<class T> void Dbrng(T lo, T hi, string note = "", int w = 0) {
  if (DEBUG) {  
    cout << "Debug[ ";
    if (!note.empty()) cout << setw(3) << note << " : ";
    for (; lo != hi; ++lo) cout << setw(w) << *lo << " ";
    cout << "]" << endl;
  }
}
struct Debugger { template<class T> Debugger& operator ,
  (const T & v) { cout << " " << v << flush; return *this; } } DB;
#else
const bool DEBUG = false;
#define Db(x...)
#endif

#define rint readInteger
template<typename T>
bool readInteger(T& x)
{
	char c,r=0,n=0;
	x=0;
	for (ever)
	{
		c=getchar();
		if ((c<0) && (!r))
			return(0);
		else if ((c=='-') && (!r))
			n=1;
		else if ((c>='0') && (c<='9'))
			x=x*10+c-'0',r=1;
		else if (r)
			break;
	}
	if (n)
		x=-x;
	return(1);
}

const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

ll modPow(ll a, ll b)
{
	a %= MOD;
	ll ans = 1;
	while (b)
	{
		if (b % 2 == 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}

const int MX = 2.1e5;

ll fact[MX];
ll ifact[MX];

ll choose(int a, int b)
{
	return fact[a] * ifact[b] % MOD * ifact[a-b] % MOD;
}

ll paths(int r, int c)
{
	return choose(r + c - 2, r - 1);
}

ll paths(pi a, pi b)
{
	int dx = b.first - a.first;
	int dy = b.second - a.second;
	if (dx < 0 || dy < 0)
		return 0;
	return paths(dx + 1, dy + 1);
}

int R, C;
vector<pi> cells;
vector<ll> vals;

int main()
{
	fact[0] = 1;
	jjs(i, 1, MX) fact[i] = fact[i-1] * i % MOD;
	ji(MX) ifact[i] = modPow(fact[i], MOD - 2);

	int N;
	rint(R); rint(C); rint(N);
	cells.pb({1, 1});
	cells.pb({R, C});
	jk(N)
	{
		int a, b;
		rint(a); rint(b);
		cells.pb({a, b});
	}
	sort(cells.begin(), cells.end());
	vals.pb(MOD-1);
	jjs(i, 1, cells.size())
	{
		ll v = 0;
		jj(i)
		{
			ll x = (MOD - vals[j]) % MOD;
			v += x * paths(cells[j], cells[i]) % MOD;
			v %= MOD;
		}
		vals.pb(v);
	}
	printf("%lld\n", vals.back());
}