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

int tot = 0;

struct dsu
{
	dsu *rep;
	int cnt;
	int size;

	dsu() : rep(this), cnt(0), size(1)
	{}

	dsu *par() {
		return rep == this ? rep : rep = rep->par();
	}

	void reset() {
		cnt = 0;
	}

	void inc() {
		if (rep != this) {
			rep->inc();
			return;
		}
		if (cnt++ == 0) {
			tot += size;
		}
	}

	void dec() {
		if (rep != this) {
			rep->dec();
			return;
		}
		if (--cnt == 0) {
			tot -= size;
		}
		assert(cnt >= 0);
	}
};

void merge(dsu *a, dsu *b)
{
	a = a->par();
	b = b->par();
	if (a == b)
		return;
	a->size += b->size;
	b->rep = a;
}

const int MX = 510;

int n, k;
bool field[MX][MX];
dsu disj[MX][MX];

int main()
{
	rint(n);
	rint(k);
	ji(n) {
		char buf[MX];
		scanf("%s", buf);
		jj(n) field[i+1][j+1] = buf[j] == '.';
	}
	n += 2;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < n-1; j++) {
			jk(4) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (field[i][j] && field[nx][ny])
					merge(&disj[i][j], &disj[nx][ny]);
			}
		}
	}
	jij(n, n) {
		disj[i][j].par();
		assert(disj[i][j].rep == disj[i][j].par());
		if (!field[i][j])
			disj[i][j].size = 0;
	}
	int best = 0;
	for (int startX = 1; startX < n; startX++) {
		int endX = startX + k - 1;
		if (endX >= n-1)
			continue;
		tot = 0;
		jij(n, n)
			disj[i][j].reset();
		int squ = 0;
		int y = 1;
		for (int i = -1; i <= k; i++) {
			for (int j = -1; j <= k; j++) {
				if (i >= 0 && i < k && j >= 0 && j < k && !field[startX+i][y+j])
					++squ;
				if (i == -1 && j == -1) continue;
				if (i == k && j == -1) continue;
				if (i == -1 && j == k) continue;
				if (i == k && j == k) continue;
				disj[startX+i][y+j].inc();
			}
		}
		while (true)
		{
			best = max(best, squ + tot);
			if (y + k == n-1)
				break;
			else {
				disj[startX-1][y].dec();
				disj[startX+k][y].dec();
				ji(k) {
					disj[startX+i][y-1].dec();
				}
				disj[startX-1][y+k].inc();
				disj[startX+k][y+k].inc();
				ji(k) {
					disj[startX+i][y+k+1].inc();
				}
				ji(k) {
					if (!field[startX+i][y]) --squ;
					if (!field[startX+i][y+k]) ++squ;
				}
				++y;
			}
		}
	}
	printf("%d\n", best);
}