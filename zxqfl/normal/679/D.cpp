#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); ++i)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
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

typedef ModInt<long long, 1000000007> mint;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<double> VD;

const int MX = 405;

VI E[MX];
int D[MX][MX];

int n, m;

template<typename T>
void uniquify(vector<T>& v)
{
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
}

vector<pair<int, double>> process(vector<pair<int, double>>& v)
{
	vector<pair<int, double>> ret;
	sort(v.begin(), v.end());
	foreach(pr, v) {
		if (ret.empty() || pr.first != ret.back().first) {
			ret.push_back(pr);
		} else {
			ret.back().second += pr.second;
		}
	}
	return ret;
}

double dpr[MX];
int stamp[MX];

double f(int x)
{
	double base = 1.0 / n;
	VD pdist(n);
	VI countAt(n);
	ji(n) pdist[D[x][i]] += base;
	ji(n) ++countAt[D[x][i]];
	vector<vector<pair<int, double>>> possLoc(n);
	ji(n) foreach(o, E[i]) possLoc[D[x][i]].pb({o, base / E[i].size()});
	double tot = 0;
	ji(n) {
		if (countAt[i] == 0)
			continue;
		double catchChance = 1.0 / countAt[i] * pdist[i];
		possLoc[i] = process(possLoc[i]);
		jj(n) stamp[j] = -1;
		jj(n) {
			double ccatch = 0;
			foreach(pr, possLoc[i]) {
				auto& q = dpr[D[j][pr.first]];
				if (stamp[D[j][pr.first]] != j) {
					stamp[D[j][pr.first]] = j;
					q = 0;
				}
				auto r = pr.second;
				if (r > q) {
					ccatch += r - q;
					q = r;
				}
			}
			catchChance = max(catchChance, ccatch);
		}
		tot += catchChance;
		// printf("%d %d %f %f\n", x, i, pdist[i], catchChance);
	}
	return tot;
}

int main()
{
	jij(MX, MX) D[i][j] = INF;
	rint(n); rint(m);
	ji(n) D[i][i] = 0;
	jk(m) {
		int a, b;
		rint(a); rint(b);
		--a; --b;
		D[a][b] = min(D[a][b], 1);
		D[b][a] = min(D[b][a], 1);
		E[a].pb(b);
		E[b].pb(a);
	}
	ji(n) jj(n) jk(n) D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
	double ans = 0;
	ji(n) ans = max(ans, f(i));
	printf("%.10f\n", ans);
}