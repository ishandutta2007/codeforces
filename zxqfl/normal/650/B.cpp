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

int n, a, b, T;
char s[(int)1.1e6];

int main()
{
	rint(n); rint(a); rint(b); rint(T);
	++b;
	scanf("%s", s);
	ji(n) s[i+n] = s[i];
	int c0;
	if (s[n] == 'w')
		c0 = b;
	else
		c0 = 1;
	if (T < c0)
	{
		printf("0\n");
		return 0;
	}
	int idx = n;
	int best = 0;
	ll c1 = 0;
	ll c2 = 0;
	for (int r = n; r < 2*n; r++)
	{
		if (s[r] == 'w')
			c1 += b;
		else
			c1 += 1;
		int left = n - idx;
		int right = r - n;
		c2 = (ll) a * (left + right + min(left, right));
		while (idx > 0 && c1 + c2 <= T)
		{
			--idx;
			if (s[idx] == 'w')
				c1 += b;
			else
				c1 += 1;
			// printf("-> %d %lld\n", idx, c1);
			int left = n - idx;
			int right = r - n;
			c2 = (ll) a * (left + right + min(left, right));
		}
		while (idx < n && c1 + c2 > T)
		{
			if (s[idx] == 'w')
				c1 -= b;
			else
				c1 -= 1;
			// printf("-> %d %lld\n", idx, c1);
			++idx;
			int left = n - idx;
			int right = r - n;
			c2 = (ll) a * (left + right + min(left, right));
		}
		// printf("%d %d %lld %lld\n", r, idx, c1, c2);
		if (c1 + c2 > T)
			break;
		best = max(best, r - idx + 1);
	}
	printf("%d\n", min(best, n));
}