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

bool solve()
{
	nrint(N); nrint(M);
	vector<pi> V;
	jk(M)
	{
		nrint(a);
		nrint(b);
		V.pb({a, b});
	}
	ji(V.size() - 1)
		if (abs(V[i].second - V[i+1].second) > V[i+1].first - V[i].first)
			return false;
	int ans = 0;
	ji(V.size() - 1)
	{
		int a = min(V[i].second, V[i+1].second);
		int b = max(V[i].second, V[i+1].second);
		int t = V[i+1].first - V[i].first;
		t -= b - a;
		ans = max(ans, b + t / 2);
	}
	ans = max(ans, V[0].first + V[0].second - 1);
	ans = max(ans, V.back().second + N - V.back().first);
	printf("%d\n", ans);
	return true;
}

int main()
{
	if (!solve()) printf("IMPOSSIBLE\n");
}