#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
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

vector<int> nums;

bool valid(int x)
{
	while (x)
	{
		int d = x % 10;
		if (d != 0 && d != 1)
			return false;
		x /= 10;
	}
	return true;
}
int dp[1000001];
int main()
{
	ji(1e6 + 1)
	{
		if (valid(i)) nums.pb(i);
	}
	nrint(N);
	dp[0] = 0;
	jjs(i, 1, N+1)
	{
		dp[i] = INF;
		foreach(v, nums) if (v <= i)
			dp[i] = min(dp[i], 1 + dp[i-v]);
	}
	int crnt = N;
	vector<int> ans;
	while (crnt)
	{
		foreach(v, nums) if (v <= crnt && dp[crnt] == 1 + dp[crnt - v])
		{
			ans.pb(v);
			crnt -= v;
			break;
		}
	}
	printf("%d\n", (int) ans.size());
	foreach(x, ans) printf("%d ", x);
}