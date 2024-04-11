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
	friend ostream& operator << (ostream& out, const ModInt& x)
	{
		return out << x.value;
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

int n;
const int MXN = 2 * 100000 + 100;
multiset<int> nei[MXN];
int input_a[MXN];
int input_b[MXN];
bool seen[MXN];
bool taboo[MXN];
bool issame[MXN];
int from[MXN];
vector<int> child[MXN];
mint dp[MXN][3];

void add_edge(int a, int b) {
	if (taboo[a] && taboo[b]) {
		return;
	}
	if (taboo[a]) {
		a = b;
	}
	if (taboo[b]) {
		b = a;
	}
	nei[a].insert(b);
	nei[b].insert(a);
	if (a == b) {
		issame[a] = true;
	}
}

void remd(int a, int b) {
	auto it = nei[a].find(b);
	nei[a].erase(it);
}

void remove_edge(int a, int b) {
	remd(a, b);
	remd(b, a);
}

void init() {
	ji(MXN) {
		nei[i].clear();
		child[i].clear();
		seen[i] = false;
		from[i] = -1;
		issame[i] = false;
	}
	ji(n) {
		add_edge(input_a[i], input_b[i]);
	}
}

std::vector<int> burn(int x) {
	vector<int> result;
	while (!nei[x].empty()) {
		auto o = *nei[x].begin();
		remove_edge(x, o);
		result.push_back(o);
	}
	return result;
}

std::vector<int> component(int x) {
	std::queue<int> q;
	q.push(x);
	vector<int> result;
	from[x] = -1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (seen[x]) {
			continue;
		}
		seen[x] = true;
		result.push_back(x);
		for (int o : nei[x]) {
			if (!seen[o]) {
				q.push(o);
				from[o] = x;
				child[x].pb(o);
			}
		}
	}
	return result;
}

void filldp(int x) {
	// 0 -> must fill
	// 1 -> no responsibilities
	mint* a = dp[x];

	a[0] = 1;
	for (int o : child[x]) {
		a[0] *= dp[o][0];
		assert(dp[o][0] == 0 || dp[o][0] == 1);
	}

	int forcer = -1;
	int num_forcers = 0;
	for (int o : child[x]) {
		if (dp[o][0] == 0) {
			forcer = o;
			num_forcers++;
		}
	}

	assert(num_forcers <= 1);

	if (num_forcers == 1) {
		a[1] = dp[forcer][1];
	} else {
		a[1] = 1;
		for (int o : child[x]) {
			a[1] += dp[o][1];
		}
	}

	if (issame[x]) {
		a[1] = a[0];
		a[0] = 0;
	}
}

mint ways(int root, vector<int> comp) {
	ji(comp.size()) {
		int x = comp[comp.size()-i-1];
		filldp(x);
	}
	// if (comp.size() >= 2 || dp[root][1] != 1) {
	// 	for (int x : comp) {
	// 		cout << x << endl;
	// 	}
	// 	cout << "-> " << dp[root][1] << endl;
	// 	cout << endl;
	// }
	return dp[root][1];
}

int main()
{
	rint(n);
	ji(n) {
		rint(input_a[i]);
		rint(input_b[i]);
	}
	std::queue<int> q;
	auto check = [&](int x) {
		if (nei[x].size() == 1) {
			q.push(x);
		}
	};
	init();
	ji(MXN) check(i);
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		auto neis = burn(x);
		for (auto y : neis) {
			check(y);
		}
	}
	mint running_total = 1;
	ji(MXN) {
		if (nei[i].empty()) {
			continue;
		}
		auto vs = component(i);
		if (vs.size() >= 2) {
			running_total *= 2;
			// cout << "* 2 or " << i << endl;
		}
		for (int x : vs) {
			taboo[x] = true;
		}
	}
	// cout << "midpoint" << running_total << endl;
	init();
	ji(MXN) {
		if (nei[i].size() >= 1) {
			// cout << i << endl;
		}
		auto vs = component(i);
		if (vs.size() >= 1) {
			running_total *= ways(i, vs);
		}
	}
	cout << running_total << endl;
}