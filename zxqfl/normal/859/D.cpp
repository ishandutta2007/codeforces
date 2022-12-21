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

int n, teams;
const int MXN = 300;
double winprob[MXN][MXN];

struct node {
	node *left, *right;
	int id;
	double dp[MXN];
	double phere[MXN];
	vector<int> contained;

	void fillhere() {
		ji(teams) phere[i] = 0;
		if (id != -1) {
			phere[id] = 1;
		} else {
			left->fillhere();
			right->fillhere();
			jij(teams, teams) {
				phere[i] += left->phere[i] * right->phere[j] * winprob[i][j];
				phere[j] += left->phere[i] * right->phere[j] * winprob[j][i];
			}
		}
	}

	void solve() {
		ji(teams + 1) {
			dp[i] = 0;
		}
		if (id == -1) {
			left->solve();
			right->solve();
			ji(teams) {
				dp[i] += phere[i] * contained.size() / 2;
				dp[i] += left->dp[i];
				dp[i] += right->dp[i];
				dp[teams] = max(dp[teams], dp[i]);
			}
			ji(teams) {
				if (find(contained.begin(), contained.end(), i) == contained.end()) {
					dp[i] = dp[teams];
				}
			}
		}
	}
};

node* make(std::vector<int> v) {
	node* r = new node;
	if (v.size() == 1) {
		r->id = v[0];
		r->left = r->right = 0;
	} else {
		std::vector<int> a, b;
		ji(v.size()) {
			if (i < (int) v.size() / 2) {
				a.push_back(v[i]);
			} else {
				b.push_back(v[i]);
			}
		}
		r->id = -1;
		r->left = make(a);
		r->right = make(b);
	}
	r->contained = v;
	return r;
}

int main()
{
	cin >> n;
	teams = 1 << n;
	jij(teams, teams) {
		cin >> winprob[i][j];
		winprob[i][j] /= 100;
	}
	vector<int> vv;
	ji(teams) vv.push_back(i);
	auto n = make(vv);
	n->fillhere();
	n->solve();
	printf("%.20f\n", n->dp[teams]);
}