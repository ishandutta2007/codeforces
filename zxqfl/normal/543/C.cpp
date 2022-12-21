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

int N, M;
vector<int> masks;
vector<pi> switches;
const int MX = 20;
const int SZ = 1 << MX;
int dp[SZ];
int minCost[MX];
int costs[MX][MX];
char strings[50][50];

inline int sw(int x)
{
	return ((1 << N) - 1) ^ x;
}

int main()
{
	rint(N); rint(M);
	ji(1 << N) masks.pb(i);
	sort(masks.begin(), masks.end(), [](int a, int b) { return __builtin_popcount(a) > __builtin_popcount(b); });
	foreach(v, masks)
	{
		ji(N) if (v & (1 << i))
		{
			switches.pb({v, v ^ (1 << i)});
		}
	}
	ji(N) scanf("%s", strings[i]);
	jij(N, M) rint(costs[i][j]);
	ji(N)
	{
		minCost[i] = INF;
		jj(M) minCost[i] = min(minCost[i], costs[i][j]);
	}
	ji(1 << N)
	{
		dp[i] = 0;
		jj(N) if (i & (1 << j))
			dp[i] += minCost[j];
	}
	ji(M)
	{
		vector<int> buckets[256];
		jj(N) buckets[strings[j][i]].pb(j);
		jk(256)
		{
			auto& V = buckets[k];
			if (V.empty()) continue;
			int total = 0;
			int most = 0;
			int msk = 0;
			foreach(x, V)
			{
				total += costs[x][i];
				most = max(most, costs[x][i]);
				msk |= 1 << x;
			}
			jj(1 << N)
				dp[j | msk] = min(dp[j | msk], dp[j] + total - most);
		}
	}
	printf("%d\n", dp[(1 << N) - 1]);
}