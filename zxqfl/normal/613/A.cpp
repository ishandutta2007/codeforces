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

int n;
const int MX = 1.1e5;
ll px, py;

double ar(double x)
{
	return acos(-1) * x * x;
}

template<typename T>
struct MyPoint
{
	T x, y;

	MyPoint() {}
	MyPoint(const T& a, const T& b) : x(a), y(b) {}

	MyPoint operator + (const MyPoint& P) const
	{
		return {x + P.x, y + P.y};
	}
	MyPoint operator - (const MyPoint& P) const
	{
		return {x - P.x, y - P.y};
	}
	MyPoint operator * (const T& s) const
	{
		return {x * s, y * s};
	}
	T operator * (const MyPoint& P) const
	{
		return x * P.x + y * P.y;
	}
	T operator ^ (const MyPoint& P) const
	{
		return x * P.y - y * P.x;
	}
	T dot(const MyPoint& P) const
	{
		return (*this) * P;
	}
	T cross(const MyPoint& P) const
	{
		return (*this) ^ P;
	}
	T norm2() const
	{
		return x * x + y * y;
	}
};
typedef MyPoint<ll> pt;

pt pts[MX];

int main()
{
	rint(n); rint(px); rint(py);
	ji(n) rint(pts[i].x), rint(pts[i].y);
	double best = 0;
	double worst = 1e25;
	for (int i = 0; i < n; i++)
	{
		ll dx = pts[i].x - px;
		ll dy = pts[i].y - py;
		best = max(best, sqrt(dx * dx + dy * dy));
		worst = min(worst, sqrt(dx * dx + dy * dy));
	}
	pt cpt{px, py};
	ji(n)
	{
		auto a = pts[i];
		auto b = pts[(i+1)%n];
		if ((b - a)*(cpt - a) >= 0 && (a - b) * (cpt - b) >= 0)
		{
			worst = min(worst, abs((a - b) ^ (cpt - b)) / sqrt((a-b).norm2()));
		}
	}
	printf("%.12f\n", ar(best) - ar(worst));
}