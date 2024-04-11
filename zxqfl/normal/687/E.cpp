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
#define INF ((int) 1e9+10)
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
typedef v2d<int> VVI;
typedef vector<ll> VLL;
typedef v2d<ll> VVLL;
typedef vector<char> VCH;
typedef v2d<char> VVCH;


class PBSCC {
	stack<int, vector<int> > A, B;
	vector<vector<int> > E;
	vector<char> seen;
	vector<char> active;
	vector<vector<int> > ans;
	int n;
	int nxt;
	vector<int> id;

	void dfs(int x)
	{
		if (seen[x])
			return;
		id[x] = nxt++;
		seen[x] = true;
		active[x] = true;
		A.push(x);
		B.push(x);
		for (int i = 0; i < E[x].size(); i++)
		{
			int o = E[x][i];
			if (active[o]) {
				while (id[B.top()] > id[o])
					B.pop();
			} else if (!seen[o]) {
				dfs(o);
			}
		}
		if (B.top() == x) {
			B.pop();
			VI component;
			do {
				active[A.top()] = false;
				component.push_back(A.top());
				A.pop();
			} while (component.back() != x);
			ans.push_back(component);
		}
	}

	void solve()
	{
		for (int i = 0; i < n; i++) {
			dfs(i);
		}
	}

public:
	static VVI components(const VVI& E)
	{
		PBSCC algo;
		algo.n = E.size();
		algo.E = E;
		algo.seen = algo.active = vector<char>(algo.n);
		algo.nxt = 0;
		algo.id = vector<int>(algo.n);
		algo.solve();
		return algo.ans;
	}
};

int shcycle(int x, const VVI& E) {
	int n = E.size();
	VI dist(n, -1);
	dist[x] = 0;
	queue<int> Q;
	Q.push(x);
	while (!Q.empty()) {
		int y = Q.front();
		Q.pop();
		foreach(o, E[y]) {
			if (o == x)
				return dist[y] + 1;
			if (dist[o] < 0) {
				dist[o] = dist[y] + 1;
				Q.push(o);
			}
		}
	}
	return -1;
}

int main()
{
	int n, m;
	rint(n); rint(m);
	VVI E(n);
	jk(m) {
		int u, v;
		rint(u); rint(v);
		--u; --v;
		E[u].pb(v);
	}
	VI compIdx(n);
	VVI comps = PBSCC::components(E);
	ji(comps.size()) foreach(x, comps[i]) compIdx[x] = i;
	VI hasExit(comps.size());
	ji(comps.size()) foreach(x, comps[i]) foreach(o, E[x]) {
		if (compIdx[o] != i)
			hasExit[i] = 1;
	}
	int ans = n;
	ji(comps.size()) if (!hasExit[i]) {
		int best = n;
		foreach(x, comps[i]) {
			int q = shcycle(x, E);
			if (q < 0)
				goto en;
				best = min(best, q);
		}
		ans += 998 * best + 1;
		en:;
	}
	printf("%d\n", ans);
}