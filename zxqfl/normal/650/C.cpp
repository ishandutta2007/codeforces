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

const int MX = 1.1e6;

pi invmap[MX];
vector<int> E[MX];
int indegree[MX];
bool seen[MX];
int par[MX];

int rep(int x)
{
	return par[x] == x ? x : par[x] = rep(par[x]);
}

void merge(int a, int b)
{
	a = rep(a);
	b = rep(b);
	if (a != b)
	{
		par[a] = b;
		indegree[b] += indegree[a];
	}
}

int main()
{
	int n, m;
	rint(n); rint(m);
	VVI table(n, VI(m));
	VVI mapv(n, VI(m));
	VI answer(n*m);
	jij(n, m) rint(table[i][j]);
	ji(n*m) par[i] = i;
	int nxt = 0;
	jij(n, m)
	{
		mapv[i][j] = nxt;
		invmap[nxt] = {i, j};
		nxt++;
	}
	VPI row(m);
	VPI col(n);
	ji(n)
	{
		jj(m) row[j] = {table[i][j], mapv[i][j]};
		sort(row.begin(), row.end());
		jj(m-1)
		{
			int a = rep(row[j].second);
			int b = rep(row[j+1].second);
			if (row[j].first == row[j+1].first)
			{
				merge(a, b);
			}
			else
			{
				E[a].pb(b);
				++indegree[b];
			}
		}
	}
	ji(m)
	{
		jj(n) col[j] = {table[j][i], mapv[j][i]};
		sort(col.begin(), col.end());
		jj(n-1)
		{
			int a = rep(col[j].second);
			int b = rep(col[j+1].second);
			if (col[j].first == col[j+1].first)
			{
				merge(a, b);
			}
			else
			{
				E[a].pb(b);
				++indegree[b];
			}
		}
	}
	jjl(x, n*m)
	{
		for (int& ed : E[x])
		{
			ed = rep(ed);
			if (x != rep(x))
				E[rep(x)].pb(ed);
		}
	}
	queue<int> q1, q2;
	for (int i = 0; i < n*m; i++)
		if (indegree[i] == 0 && par[i] == i)
			q1.push(i), seen[i] = true;
	int nextAnswer = 1;
	while (!q1.empty())
	{
		while (!q1.empty())
		{
			int x = q1.front();
			q1.pop();
			answer[x] = nextAnswer;
			for (int ed : E[x])
				if (indegree[ed] >= 2)
					--indegree[ed];
				else if (!seen[ed])
				{
					seen[ed] = true;
					q2.push(ed);
				}
		}
		swap(q1, q2);
		++nextAnswer;
	}
	ji(n)
	{
		jj(m) printf("%d%c", answer[rep(mapv[i][j])], j+1 == m ? '\n' : ' ');
	}
}