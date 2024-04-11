#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); ++i)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define jij2d(v) jij((v).size(), (v)[i].size())
#define jjdescent(i, s, e) for (int i = (s)-1; i >= int(e); --i)
#define jjrev(i, s) jjdescent(i, s, 0)
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1.5e9)
#define LINF ((long long) 1e16)
#define pb push_back
#define mp make_pair

#define rint readInteger
template<typename T>
bool readInteger(T& x)
{
	char c, r = 0, n = 0;
	x = 0;
	while (true)
	{
		c = getchar();
		if (c < 0 && !r)
			return 0;
		else if (c == '-' && !r)
			n = 1;
		else if (c >= '0' && c <= '9')
			x = x * 10 + c - '0', r = 1;
		else if (r)
			break;
	}
	if (n)
		x = -x;
	return 1;
}

template<typename T>
vector<T> readIntegral(int n)
{
	vector<T> ret(n);
	for (int i = 0; i < n; i++)
		readInteger(ret[i]);
	return ret;
}

auto readInts = readIntegral<int>;
auto readLongs = readIntegral<long long>;

template<typename T>
vector<vector<T>> make2d(size_t r, size_t c)
{
	return vector<vector<T>>(r, vector<T>(c));
}

template<typename T>
vector<vector<T>> make2d(size_t r, size_t c, const T& def)
{
	return vector<vector<T>>(r, vector<T>(c, def));
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
		ModInt ret = 1 % MOD;
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

template<typename T>
using v2d = vector<vector<T>>;

typedef ModInt<long long, 1000000007> mint;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<char> VCH;
typedef vector<VLL> VVCH;

const int MX = 1.1e5;
int n, k;

typedef tuple<int, int, int> t3;

ll current_time = -INF;

struct Square
{
	ll total;
	ll members;
	ll lastModify;

	Square() : total(0), members(0), lastModify(0)
	{}

	void modify(ll delta)
	{
		total += members * (current_time - lastModify);
		members += delta;
		lastModify = current_time;
	}
} squares[MX];

vector<pair<ll, ll>> occ;

void process(ll pos, ll delta)
{
	ll start = pos - k + 1;
	auto front = lower_bound(occ.begin(), occ.end(), mp(start, -1LL));
	auto back = front;
	ll cnt = 0;
	for (ll x = start; x <= pos; x++)
	{
		while (front != occ.end() && x + k - 1 >= front->first) {
			cnt += front->second;
			++front;
		}
		while (back != occ.end() && back->first < x) {
			cnt -= back->second;
			++back;
		}
		squares[cnt].modify(-abs(delta));
		squares[cnt+delta].modify(abs(delta));
	}
	assert(back->first == pos);
	back->second += delta;
}

int main()
{
	rint(n); rint(k);
	VI x(n), y(n);
	ji(n) {
		rint(x[i]);
		rint(y[i]);
	}
	vector<t3> events;
	ji(n) {
		events.pb(make_tuple(y[i] - k + 1, x[i], 1));
		events.pb(make_tuple(y[i]     + 1, x[i], 0));
	}
	VI compress = x;
	sort(compress.begin(), compress.end());
	foreach(q, compress) {
		if (occ.empty() || q != occ.back().first)
			occ.pb(mp(ll(q), 0LL));
	}
	sort(events.begin(), events.end());
	foreach(eve, events)
	{
		ll t = get<0>(eve);
		ll xpos = get<1>(eve);
		ll type = get<2>(eve);
		// cout << t << ' ' << xpos << ' ' << type << endl;
		current_time = t;
		if (type == 1) {
			process(xpos, 1);
		}
		else
		{
			process(xpos, -1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", squares[i].total);
	}
}