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

const int MOD = 1000000007;

long long modPow(long long a, long long b, int mod = MOD)
{
	assert(b >= 0);
	long long ret = 1 % mod;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

const int MX = 1.1e5;
const int BLAH = MX*2;
const int LM = 18;

int n, q;
int a[MX];
int f[MX];
int qa[MX], qb[MX];
int idxFor[MX];
int rmq[BLAH][LM];

int maxf(int a, int b)
{
	if (a == -1) return b;
	if (b == -1) return a;
	if (f[a] > f[b]) return a;
	else return b;
}

ll rec(int a, int b)
{
	if (a > b) return 0;
	int sz = b-a+1;
	int idx = idxFor[sz];
	int p2 = 1 << idx;
	int highest = maxf(rmq[a][idx], rmq[b-p2+1][idx]);
	// printf("%d %d %d %d\n", a, b, highest, idx);
	ll ret = 0;
	ret += (ll) f[highest] * (highest - a + 1) * (b - highest + 1);
	ret += rec(a, highest - 1);
	ret += rec(highest + 1, b);
	return ret;
}

int main()
{
	rint(n); rint(q);
	ji(n) rint(a[i]);
	ji(q)
	{
		rint(qa[i]);
		rint(qb[i]);
		--qa[i];
		--qb[i];
		--qb[i];
	}
	ji(n-1) f[i] = abs(a[i] - a[i+1]);
	int nxt = 0;
	ji(LM)
	{
		int z = 1 << (i+1);
		while (nxt < z && nxt <= n)
			idxFor[nxt++] = i;
	}
	--n;
	jij(BLAH, LM) rmq[i][j] = -1;
	ji(n) rmq[i][0] = i;
	// ji(n) printf("f[%d] = %d\n", i, f[i]);
	jjs(q, 1, LM) ji(n)
	{
		int z = 1 << (q-1);
		if (i+z >= BLAH) break;
		rmq[i][q] = maxf(rmq[i][q-1], rmq[i+z][q-1]);
		// if (q < 5) printf("[%d][%d] -> (%d %d, %d %d) -> %d\n", i, q, i, q-1, i+z, q-1, rmq[i][q]);
	}
	ji(q) printf("%lld\n", rec(qa[i], qb[i]));
}