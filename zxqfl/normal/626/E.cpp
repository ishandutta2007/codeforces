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
typedef long double ld;

bool eq(ld a, ld b)
{
	return a == b;
}

ld solve(VI v, ld r = -1e9)
{
	sort(v.begin(), v.end());
	int n = v.size();
	VLL prefix(n+1);
	for (int i = 1; i <= n; i++)
		prefix[i] = v[i-1] + prefix[i-1];
	ld best = 0;
	jjl(median, n)
	{
		int lo = 0;
		int hi = min(n - median - 1, median);
		#define FUN(x) ((ld) (prefix[n] - prefix[n-(x)] + v[median] + prefix[median] - prefix[median-(x)]) / (2*(x)+1) - v[median])
		while (hi != lo)
		{
			int mid = (lo + hi) / 2;
			if (FUN(mid) > FUN((mid+1)))
				hi = mid;
			else
				lo = mid+1;
		}
		ld val = FUN(lo);
		if (eq(val, r))
		{
			printf("%d\n", 2*lo+1);
			ji(lo) printf("%d %d ", v[median - i - 1], v[n - i - 1]);
			printf("%d\n", v[median]);
			exit(0);
		}
		best = max(best, val);
		#undef FUN
	}
	jjl(leftmedian, n-1)
	{
		int rightmedian = leftmedian + 1;
		int lo = 0;
		int hi = min(n - rightmedian - 1, leftmedian);
		#define FUN(x) ((ld) (prefix[n] - prefix[n-(x)] + v[leftmedian] + v[rightmedian] + prefix[leftmedian] - prefix[leftmedian-(x)]) / (2*(x)+2) - (ld) (v[leftmedian] + v[rightmedian]) / 2)
		while (hi != lo)
		{
			int mid = (lo + hi) / 2;
			if (FUN(mid) > FUN((mid+1)))
				hi = mid;
			else
				lo = mid+1;
		}
		ld val = FUN(lo);
		if (eq(val, r))
		{
			printf("%d\n", 2*lo+2);
			ji(lo) printf("%d %d ", v[leftmedian - i - 1], v[n - i - 1]);
			printf("%d %d\n", v[leftmedian], v[rightmedian]);
			exit(0);
		}
		best = max(best, val);
		#undef FUN
	}
	return best;
}

int main()
{
	int n;
	rint(n);
	VI v(n);
	ji(n) rint(v[i]);
	solve(v, solve(v));
}