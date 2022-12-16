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

#ifndef ONLINE_JUDGE
const bool DEBUG = true;
#define Db(x...)   ({ if (DEBUG) { cout << "Debug["; DB, #x, ":", x, "]\n"; } })
template<class T> void Dbrng(T lo, T hi, string note = "", int w = 0) {
  if (DEBUG) {  
    cout << "Debug[ ";
    if (!note.empty()) cout << setw(3) << note << " : ";
    for (; lo != hi; ++lo) cout << setw(w) << *lo << " ";
    cout << "]" << endl;
  }
}
struct Debugger { template<class T> Debugger& operator ,
  (const T & v) { cout << " " << v << flush; return *this; } } DB;
#else
const bool DEBUG = false;
#define Db(x...)
#endif

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
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

template<typename T>
struct mypt
{
	T x, y;

	mypt() {}
	mypt(const T& a, const T& b) : x(a), y(b) {}

	mypt operator + (const mypt& P) const
	{
		return {x + P.x, y + P.y};
	}
	mypt operator - (const mypt& P) const
	{
		return {x - P.x, y - P.y};
	}
	mypt operator * (const T& s) const
	{
		return {x * s, y * s};
	}
	T operator * (const mypt& P) const
	{
		return x * P.x + y * P.y;
	}
	T operator ^ (const mypt& P) const
	{
		return x * P.y - y * P.x;
	}
	T dot(const mypt& P) const
	{
		return (*this) * P;
	}
	T cross(const mypt& P) const
	{
		return (*this) ^ P;
	}
	T norm2() const
	{
		return x * x + y * y;
	}
};
typedef mypt<ll> pt;

const int MX = 1.1e5;
int N;
pt pts[MX];
double pow2[MX];

double ge3(ll x)
{
	return pow2[x] - 1 - x - x * (x - 1) / 2;
}

double ge2(ll x)
{
	return pow2[x] - 1 - x;
}

double ge1(ll x)
{
	return pow2[x] - 1;
}

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int findBoundary(int a, int b)
{
	ll dx = abs(pts[a].x - pts[b].x);
	ll dy = abs(pts[a].y - pts[b].y);
	assert(dx || dy);
	if (dx > dy) swap(dx, dy);
	if (dx == 0)
		return dy;
	ll z = gcd(dx, dy);
	return z;
}


int main()
{
	pow2[0] = 1;
	jjs(i, 1, 1000)
		pow2[i] = pow2[i-1] * 2;
	double Earea = 0;
	double Eboundary = 0;
	rint(N);
	ji(N)
	{
		rint(pts[i].x);
		rint(pts[i].y);
	}
	pt translation = pts[0];
	ji(N) pts[i] = pts[i] - translation;
	double baseChance = (N > 400 ? 0.5 : (1 - ge3(N-1) / ge3(N)));
	ji(N)
	{
		// double chance = baseChance;
		jjs(lose, 1, N)
		{
			// if (chance < 1e-20)
			// 	break;
			int oth = N - 1 - lose;
			// double tchance = (N > 400 ? 0.5 : ge1(oth) / ge2(oth));
			// double x = chance * tchance;
			double x = (N > 400) ? (1.0 / pow2[lose + 1]) : (ge1(oth) / ge3(N));
			if (x < 1e-20) break;
			int p = (i - lose + N) % N;
			// printf("%d %d %f\n", p, i, x);
			Earea += x * (pts[p] ^ pts[i]);
			Eboundary += x * findBoundary(i, p);
			// chance *= 1 - tchance;
		}
	}
	Earea /= 2;
	// printf("%.15f\n", baseChance);
	// printf("%.15f\n", Earea);
	// printf("%.15f\n", Eboundary);
	printf("%.15f\n", Earea - Eboundary / 2 + 1);
}