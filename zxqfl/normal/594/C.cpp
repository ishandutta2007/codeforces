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

const int MX = 1.1e5;

int n, k;
pair<ll, ll> pts[MX];
bool potRem[MX];
bool removed[MX];

ll gx(int n)
{
	return pts[n].first;
}

ll gy(int n)
{
	return pts[n].second;
}

struct state
{
	ll loX, loY, hiX, hiY;
};

state baseState()
{
	return {-1, -1, -1, -1};
}

state comb(state s, int i)
{
	if (s.loX < 0)
		return {gx(i), gy(i), gx(i), gy(i)};
	state ret = s;
	ret.loX = min(ret.loX, gx(i));
	ret.loY = min(ret.loY, gy(i));
	ret.hiX = max(ret.hiX, gx(i));
	ret.hiY = max(ret.hiY, gy(i));
	return ret;
}

ll ans = -1;

void submit(state s)
{
	ll w = max(1LL, (s.hiX - s.loX + 1) / 2);
	ll h = max(1LL, (s.hiY - s.loY + 1) / 2);
	ll sz = w*h;
	if (ans < 0 || sz < ans)
		ans = sz;
	ans = max(ans, 1LL);
}

VI vprs;

ll brute()
{
	ans = -1;
	ji(1 << n) if (__builtin_popcount(i) <= k)
	{
		state z = baseState();
		jj(n) if (!(i & (1 << j)))
		{
			z = comb(z, j);
		}
		submit(z);
	}
	ll ret = ans;
	ans = -1;
	return ret;
}

int main()
{
	rint(n); rint(k);
	ji(n)
	{
		ll x1, y1, x2, y2;
		rint(x1);
		rint(y1);
		rint(x2);
		rint(y2);
		pts[i].first  = x1 + x2;
		pts[i].second = y1 + y2;
	}
	vector<pair<pair<ll, ll>, int > > A;
	vector<pair<pair<ll, ll>, int > > B;
	ji(n)
	{
		A.push_back({{pts[i].first, pts[i].second}, i});
		B.push_back({{pts[i].second, pts[i].first}, i});
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ji(k)
	{
		potRem[A[i].second] = true;
		potRem[B[i].second] = true;
		potRem[A[n-i-1].second] = true;
		potRem[B[n-i-1].second] = true;
	}
	state mys = baseState();
	ji(n) if (potRem[i])
		vprs.pb(i);
	else
		mys = comb(mys, i);
	jjl(a, k+1)
	jjl(b, k+1)
	jjl(c, k+1)
	jjl(d, k+1)
	{
		ji(k)
		{
			removed[A[i].second] = false;
			removed[B[i].second] = false;
			removed[A[n-i-1].second] = false;
			removed[B[n-i-1].second] = false;
		}
		ji(a) removed[A[i].second] = true;
		ji(b) removed[B[i].second] = true;
		ji(c) removed[A[n-i-1].second] = true;
		ji(d) removed[B[n-i-1].second] = true;
		int cnt = 0;
		state cst = mys;
		foreach(z, vprs)
			if (removed[z])
				++cnt;
			else
				cst = comb(cst, z);
		if (cnt <= k)
			submit(cst);
	}
	printf("%lld\n", ans);
}