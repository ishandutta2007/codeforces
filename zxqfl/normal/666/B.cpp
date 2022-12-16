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

const int MX = 3100;

void offer(pair<int, VI>& p, int v, int x)
{
	if (v > p.first) {
		p.first = v;
		p.second = {x};
	}
	else if (v == p.first) {
		p.second.pb(x);
	}
}

VI E[MX];
int d[MX][MX];
VPI scandi[MX], ecandi[MX];
pi egain[MX];
int n, m;

void fdist(int start)
{
	ji(n) d[start][i] = INF;
	d[start][start] = 0;
	queue<int> Q;
	Q.push(start);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int o : E[x]) {
			if (d[start][o] == INF)
			{
				d[start][o] = d[start][x]+1;
				Q.push(o);
			}
		}
	}
}

int main()
{
	rint(n); rint(m);
	jk(m) {
		int a, b;
		rint(a); rint(b);
		--a; --b;
		E[a].pb(b);
	}
	ji(n) fdist(i);
	ji(n) jj(n) {
		if (d[i][j] < INF && i != j) {
			scandi[j].push_back({d[i][j], i});
			ecandi[i].push_back({d[i][j], j});
		}
	}
	ji(n) {
		sort(scandi[i].begin(), scandi[i].end());
		reverse(scandi[i].begin(), scandi[i].end());
		sort(ecandi[i].begin(), ecandi[i].end());
		reverse(ecandi[i].begin(), ecandi[i].end());
		// printf("%d: ", i);
		// foreach(z, ecandi[i]) printf("{%d %d} ", z.first, z.second);
		// printf("\n");
	}
	tuple<int, int, int, int, int> ans {-1, -1, -1, -1, -1};
	// printf("%d\n", d[7][6]);
	jij(n, n) if (i != j && d[i][j] < INF) {
		int s = -1;
		int sgain = -1;
		for (pi p : scandi[i]) {
			if (p.second != j) {
				s = p.second;
				sgain = p.first;
				break;
			}
		}
		if (s < 0) continue;
		int e = -1;
		int egain = -1;
		for (pi p : ecandi[j]) {
			if (p.second != i && p.second != s) {
				e = p.second;
				egain = p.first;
				break;
			}
		}
		if (e < 0) continue;
		// if (i == 0 && j == 7) {
		// 	printf("%d %d %d %d\n", d[i][j], sgain, egain, d[i][j] + sgain + egain);
		// }
		ans = max(ans, make_tuple(d[i][j] + sgain + egain, s, i, j, e));
	}
	jij(n, n) if (i != j && d[i][j] < INF) {
		int e = -1;
		int egain = -1;
		for (pi p : ecandi[j]) {
			if (p.second != i) {
				e = p.second;
				egain = p.first;
				break;
			}
		}
		if (e < 0) continue;
		int s = -1;
		int sgain = -1;
		for (pi p : scandi[i]) {
			if (p.second != j && p.second != e) {
				s = p.second;
				sgain = p.first;
				break;
			}
		}
		if (s < 0) continue;
		// if (i == 0 && j == 7) {
		// 	printf("%d %d %d %d\n", d[i][j], sgain, egain, d[i][j] + sgain + egain);
		// 	printf("%d %d %d\n", e, d[j][e], d[j][6]);
		// 	// assert(6 != i && 6 != j && 6 != s);
		// }
		ans = max(ans, make_tuple(d[i][j] + sgain + egain, s, i, j, e));
	}
	int a = get<1>(ans);
	int b = get<2>(ans);
	int c = get<3>(ans);
	int z = get<4>(ans);
	// printf("%d %d %d %d\n", d[a][b], d[b][c], d[c][z], get<0>(ans));
	printf("%d %d %d %d\n",
		1 + a,
		1 + b,
		1 + c,
		1 + z);
}