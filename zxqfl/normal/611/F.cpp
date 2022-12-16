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

char str[500500];

typedef tuple<int, int, int> t3;

t3 combine(t3 a, t3 b)
{
	return make_tuple(
		get<0>(a) + get<0>(b),
		get<1>(a) + get<1>(b),
		get<2>(a) + get<2>(b)
	);
}

t3 dof(char c)
{
	switch(c) {
		case 'U': return make_tuple(-1, 0, 1);
		case 'D': return make_tuple(1, 0, 1);
		case 'L': return make_tuple(0, -1, 1);
		case 'R': return make_tuple(0, 1, 1);
		default: assert(false);
	}
}

ll ans = 0;

void put(int a, int b, int c, int d, int t)
{
	ll x = (c - a + 1);
	ll y = (d - b + 1);
	ans += x * y % MOD * t;
	ans %= MOD;
}

int main()
{
	int n_, h, w;
	rint(n_); rint(h); rint(w);
	scanf("%s", str);
	vector<t3> v;
	ji(n_) v.pb(dof(str[i]));
	int x1 = 1;
	int y1 = 1;
	int x2 = h;
	int y2 = w;
	int dx = 0;
	int dy = 0;
	while (x1 <= x2 && y1 <= y2)
	{
		vector<t3> nxt;
		t3 crnt {0, 0, 0};
		bool any = false;
		jk(v.size())
		{
			auto x = v[k];
			put(x1, y1, x2, y2, get<2>(x));
			dx += get<0>(x);
			dy += get<1>(x);
			bool changed = true;
			if (x2 + dx > h)
				--x2;
			else if (x1 + dx < 1)
				++x1;
			else if (y2 + dy > w)
				--y2;
			else if (y1 + dy < 1)
				++y1;
			else
				changed = false;
			crnt = combine(crnt, x);
			if (changed) any = true;
			if (changed || k+1 == v.size())
			{
				nxt.pb(crnt);
				crnt = make_tuple(0, 0, 0);
			}
			if (x1 > x2 || y1 > y2)
				break;
		}
		if (!any)
		{
			printf("-1\n");
			return 0;
		}
		v = nxt;
	}
	printf("%d\n", ans);
}