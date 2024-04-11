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

long long modPow(long long a, long long b, int mod = MOD)
{
	assert(b >= 0);
	long long ret = 1 % mod;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

bool ok(ll n, ll m, ll h)
{
	ll b1 = h / 6;
	if (h % 6 >= 3)
		++b1;
	ll b2 = h / 6 * 2;
	if (h % 6 >= 2)
		++b2;
	if (h % 6 >= 4)
		++b2;
	m -= b1;
	n -= b2;
	m = max(m, 0LL);
	n = max(n, 0LL);
	return m + n <= h / 6;
}

int main()
{
	ll lo = 0;
	ll hi = (ll) 1e16;
	int n, m;
	cin >> n >> m;
	while (lo != hi)
	{
		ll mid = (lo + hi) / 2;
		if (ok(n, m, mid))
			hi = mid;
		else
			lo = mid+1;
	}
	cout << lo << endl;
}