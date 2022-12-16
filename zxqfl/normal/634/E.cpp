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

template <typename T, T MOD>
struct ModInt
{
	T value;
	ModInt() : value(0)
	{}
	ModInt(T x)
	{
		x %= MOD;
		if (x < 0)
			x += MOD;
		value = x;
	}

private:
T __________________(T ___, T ____) {
if (!____) return ___;
return __________________

(____,___%____);} T _____________(T _, T __, T ____, T ___) {
T _____,______,_______=____-_;
assert(!(_______%
__________________(__,___)));for(_____=______=0;_____-______!=_______;){
	_____=(_______+______+__-1)/
__*__;______=(_____-_______+___-1)/___*___;}return _____+_;}
public:
	ModInt& operator += (ModInt x)
	{
		value += x.value;
		if (value >= MOD)
			value -= MOD;
		return *this;
	}
	ModInt& operator -= (ModInt x)
	{
		value -= x.value;
		if (value < 0)
			value += MOD;
		return *this;
	}
	ModInt& operator *= (ModInt x)
	{
		value *= x.value;
		value %= MOD;
		return *this;
	}
	ModInt& operator /= (ModInt x)
	{
		x.invert();
		return *this *= x;
	}

	ModInt operator + (ModInt x) const
	{
		ModInt o = *this;
		o += x;
		return o;
	}
	ModInt operator - (ModInt x) const
	{
		ModInt o = *this;
		o -= x;
		return o;
	}
	ModInt operator * (ModInt x) const
	{
		ModInt o = *this;
		o *= x;
		return o;
	}
	ModInt operator / (ModInt x) const
	{
		ModInt o = *this;
		o /= x;
		return o;
	}
	bool operator == (ModInt x) const
	{
		return value == x.value;
	}
	bool operator != (ModInt x) const
	{
		return !(*this == x);
	}

	ModInt operator - () const
	{
		return ModInt(0) - *this;
	}

	ModInt operator ^ (long long x) const
	{
		ModInt ret = 1;
		ModInt mul = *this;
		while (x)
		{
			if (x & 1)
				ret *= mul;
			mul *= mul;
			x >>= 1;
		}
		return ret;
	}
	ModInt& operator ^= (long long x)
	{
		return *this = *this ^ x;
	}

private:
	void invert()
	{
		*this ^= MOD-2;
	}
public:
	void answer()
	{
		std::cout << value << std::endl;
	}
};
typedef ModInt<long long, 1000000007> mint;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

const int MX = 2.1e5;

int N, K;
int ai[MX];
VI E[MX];
VI child[MX];
bool light[MX];
ll dp[MX][5];
/*
0 -> root
1 -> unknown, but parent is dark
2 -> in the light set, on the path
3 -> in the light set, NOT on the path, no path available
4 -> in the light set, NOT on the path, path available
*/

const int NINF = -1e9;

void solve(int x)
{
	foreach(o, child[x])
		solve(o);
	ll useNow = NINF;
	{
		ll& ans = dp[x][4];
		ans = NINF;
		if (light[x])
		{
			{
				// SAVE THE PATH FOR LATER
				ll sum = 1;
				ll bestDelta = 0;
				foreach(o, child[x])
				{
					sum += dp[o][3];
					bestDelta = max(bestDelta, dp[o][4] - dp[o][3]);
				}
				sum += bestDelta;
				ans = max(ans, sum);
			}
			{
				// USE IT NOW
				ll sum = 1;
				ll bestA = 0;
				ll bestB = 0;
				foreach(o, child[x])
				{
					ll v1 = max(0LL, dp[o][3]);
					ll v2 = dp[o][2];
					sum += v1;
					ll delta = v2 - v1;
					if (delta > bestA)
					{
						bestB = bestA;
						bestA = delta;
					}
					else
						bestB = max(bestB, delta);
				}
				useNow = sum + bestA + bestB;
				ans = max(ans, useNow);
			}
		}
	}
	{
		ll& ans = dp[x][3];
		ans = NINF;
		if (light[x])
		{
			ll sum = 1;
			foreach(o, child[x])
				sum += dp[o][3];
			ans = max(ans, sum);
		}
	}
	{
		ll& ans = dp[x][2];
		ans = NINF;
		if (light[x])
		{
			ll sum = 1;
			ll bestDelta = 0;
			foreach(o, child[x])
			{
				ll v1 = max(0LL, dp[o][3]);
				ll v2 = dp[o][2];
				sum += v1;
				bestDelta = max(bestDelta, v2 - v1);
			}
			sum += bestDelta;
			ans = max(ans, sum);
		}
	}
	{
		ll& ans = dp[x][1];
		ans = useNow;
		foreach(o, child[x])
			ans = max(ans, dp[o][1]);
	}
	// printf("%d [%s] -> %lld %lld %lld %lld\n", x, light[x] ? "light" : "dark", dp[x][1], dp[x][2], dp[x][3], dp[x][4]);
}

int ROOT = 0;

bool ok(int threshold)
{
	// printf("Testing OK with threshold %d\n", threshold);
	ji(N) light[i] = ai[i] >= threshold;
	if (light[ROOT])
		return true;
	solve(ROOT);
	return dp[ROOT][1] >= K;
}

void init(int x, int par)
{
	foreach(o, E[x]) if (o != par)
	{
		child[x].pb(o);
		init(o, x);
	}
	// printf("%d:", x);
	// foreach(o, child[x]) printf(" %d", o);
	// printf("\n");
}

int main()
{
	rint(N);
	rint(K);
	ji(N) rint(ai[i]);
	jk(N-1)
	{
		int u, v;
		rint(u); rint(v);
		--u, --v;
		E[u].pb(v);
		E[v].pb(u);
	}
	ji(N) if (ai[i] < ai[ROOT])
		ROOT = i;
	init(ROOT, -1);
	VI vals(N);
	ji(N) vals[i] = ai[i];
	sort(vals.begin(), vals.end());
	reverse(vals.begin(), vals.end());
	int lo = K-1;
	int hi = N-1;
	while (lo != hi)
	{
		// printf("[%d %d]\n", vals[lo], vals[hi]);
		int mid = (lo + hi) / 2;
		if (ok(vals[mid]))
			hi = mid;
		else
			lo = mid+1;
	}
	printf("%d\n", vals[lo]);
}