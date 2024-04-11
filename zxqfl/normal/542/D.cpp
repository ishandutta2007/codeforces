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
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
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

const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pi;

const int MX = 1e6 + 10;
bool composite[MX];

ll isprimepower(ll x)
{
	if (x < 2) return -1;
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			do {
				x /= i;
			} while (x % i == 0);
			return x == 1 ? i : -1;
		}
	}
	return x;
}

bool isprime(ll x)
{
	if (x < 2) return false;
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	for (int i = 2; i < MX; i++) if (!composite[i])
	{
		for (int j = i + i; j < MX; j += i)
			composite[j] = true;
	}
	nrlong(A);
	vector<ll> V;
	for (ll i = 1; i * i <= A; i++) if (A % i == 0)
	{
		V.pb(i);
		if (i * i != A)
			V.pb(A / i);
	}
	unordered_map<ll, ll> M;
	M[A] = 1;
	unordered_set<ll> tried;
	foreach(factor, V)
	{
		ll prime = isprimepower(factor - 1);
		if (prime < 0 || tried.count(prime))
			continue;
		tried.insert(prime);
		vector<pair<ll, ll> > V;
		ll q = prime;
		while (q + 1 <= A)
		{
			ll z = q + 1;
			q *= prime;
			foreach(p, M)
			{
				if (p.first % z == 0)
					V.pb({p.first / z, p.second});
			}
		}
		foreach(x, V)
			M[x.first] += x.second;
	}
	printf("%lld\n", M[1]);
}