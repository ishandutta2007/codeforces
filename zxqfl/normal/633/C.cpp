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

int n, w;
string input;
string dict[100100];
int dp[100100];

char buf[100100];
string readString()
{
	scanf("%s", buf);
	return string(buf);
}

struct trie
{
	trie *child[26];
	int idx;
	trie()
	{
		ji(26) child[i] = 0;
		idx = -1;
	}
	trie *get(char c, int f)
	{
		int x = (int) c - 'a';
		if (child[x])
			return child[x];
		else if (f)
			return child[x] = new trie();
		else
			return 0;
	}
} *root = new trie();

char lc(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c -= 'A';
		c += 'a';
	}
	return (char) c;
}

int main()
{
	rint(n);
	input = readString();
	rint(w);
	ji(w)
		dict[i] = readString();
	ji(w)
	{
		trie *t = root;
		for (int j = 0; j < dict[i].length(); j++)
			t = t->get(lc(dict[i][j]), 1);
		t->idx = i;
	}
	dp[0] = 1234;
	for (int i = 1; i <= input.length(); i++)
	{
		trie *t = root;
		dp[i] = -1;
		for (int j = i-1; j >= 0 && j >= i - 1005; j--)
		{
			t = t->get(input[j], 0);
			if (!t)
				break;
			if (t->idx >= 0 && dp[j] >= 0)
			{
				dp[i] = t->idx;
				break;
			}
		}
	}
	int x = input.length();
	vector<string> ans;
	while (x)
	{
		assert(dp[x] >= 0 && dp[x] < w);
		ans.pb(dict[dp[x]]);
		x -= dict[dp[x]].length();
	}
	reverse(ans.begin(), ans.end());
	foreach(x, ans)
		printf("%s ", x.c_str());
}