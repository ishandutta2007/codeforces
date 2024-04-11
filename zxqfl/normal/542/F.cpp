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
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
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

const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pi;

const int MX = 1010;

int dp[MX][MX];
int T, N;
vector<int> tasks[MX];

int f(int t, int slots)
{
	if (t < 0) return 0;
	slots = min(slots, N);
	int& ans = dp[t][slots];
	if (ans >= 0) return ans;
	ans = 0;
	int gain = 0;
	ji(slots + 1)
	{
		ans = max(ans, gain + f(t-1, (slots - i) * 2));
		if (i < tasks[t].size())
			gain += tasks[t][i];
	}
	return ans;
}

int main()
{
	memset(dp, -1, sizeof dp);
	rint(N); rint(T);
	ji(N)
	{
		nrint(t);
		nrint(q);
		tasks[t].pb(q);
	}
	ji(MX)
	{
		sort(tasks[i].begin(), tasks[i].end());
		reverse(tasks[i].begin(), tasks[i].end());
	}
	printf("%d\n", f(T, 1));
}