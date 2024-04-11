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

const int MX = (1 << 21) + 5;

const int SMMX = 400010;

pi tree[MX];

void init_tree()
{
	ji(MX) tree[i] = {0, -1};
}

void update(int idx, int l, int r, int pos, pi v)
{
	if (pos < l || pos > r)
		;
	else if (l == r)
		tree[idx] = max(tree[idx], v);
	else
	{
		int mid = (l + r) / 2;
		update(idx*2+1, l, mid, pos, v);
		update(idx*2+2, mid+1, r, pos, v);
		tree[idx] = max(tree[idx*2+1], tree[idx*2+2]);
	}
}

pi query(int idx, int l, int r, int a, int b)
{
	if (a > r || b < l)
		return {0, -1};
	if (a <= l && b >= r)
		return tree[idx];
	int mid = (l + r) / 2;
	return max(
		query(idx*2+1, l, mid, a, b),
		query(idx*2+2, mid+1, r, a, b));
}

int treeBound;
pi queryLeft(int x)
{
	return query(0, 0, treeBound, 0, x-1);
}
pi queryRight(int x)
{
	return query(0, 0, treeBound, x+1, treeBound);
}

int n, m;
int h[SMMX];
pi queries[SMMX];
VI queryIndices[SMMX];
map<int, int> compress;
int leftAnswer[SMMX];
int rightAnswer[SMMX];
int backjump1[SMMX];
int backjump2[SMMX];
bool inSol[SMMX];
int realAns[SMMX];

int main()
{
	rint(n); rint(m);
	ji(n) rint(h[i]);
	ji(m)
	{
		rint(queries[i].first);
		rint(queries[i].second);
		--queries[i].first;
	}
	ji(n) compress[h[i]] = 0;
	ji(m) compress[queries[i].second] = 0;
	int nxt = 0;
	foreach (pr, compress) pr.second = nxt++;
	treeBound = nxt - 1;
	ji(n) h[i] = compress[h[i]];
	ji(m) queries[i].second = compress[queries[i].second];
	ji(m) queryIndices[queries[i].first].pb(i);
	init_tree();
	ji(n)
	{
		foreach(idx, queryIndices[i])
			leftAnswer[idx] = queryLeft(queries[idx].second).first;
		pi mval = queryLeft(h[i]);
		++mval.first;
		backjump1[i] = mval.second;
		realAns[i] = mval.first;
		update(0, 0, treeBound, h[i], make_pair(realAns[i], i));
	}
	init_tree();
	ji(n)
	{
		pi mval = queryLeft(h[i]);
		++mval.first;
		backjump2[i] = (int) 1e9 - mval.second;
		if (backjump2[i] >= (int) 1e9)
			backjump2[i] = -1;
		update(0, 0, treeBound, h[i], make_pair(realAns[i], (int) 1e9 - i));
	}
	init_tree();
	for (int i = n-1; i >= 0; i--)
	{
		foreach(idx, queryIndices[i])
			rightAnswer[idx] = queryRight(queries[idx].second).first;
		int val = queryRight(h[i]).first;
		++val;
		update(0, 0, treeBound, h[i], make_pair(val, i));
	}
	int mx = 0;
	ji(n) if (realAns[i] >= realAns[mx])
		mx = i;
	int mn = 0;
	ji(n) if (realAns[i] > realAns[mn])
		mn = i;
	int bestSeq = realAns[mx];
	while (mx >= 0)
	{
		if (mx == mn)
			inSol[mx] = true;
		mx = backjump1[mx];
		mn = backjump2[mn];
	}
	ji(m)
	{
		int p = queries[i].first;
		// printf("{%d %d} -> %d %d\n", queries[i].first, queries[i].second, leftAnswer[i], rightAnswer[i]);
		if (inSol[p])
			printf("%d\n", max(0, max(leftAnswer[i] + rightAnswer[i] + 1, bestSeq - 1)));
		else
			printf("%d\n", max(0, max(leftAnswer[i] + rightAnswer[i] + 1, bestSeq)));
	}
}