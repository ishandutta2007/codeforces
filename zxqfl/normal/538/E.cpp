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

vector<int> child[200000];
int depth[200000];
int ans[200000];
int ssz[200000];
int N;
int M;

void pp(int x)
{
	foreach(c, child[x])
	{
		pp(c);
		ssz[x] += ssz[c];
	}
	if (child[x].empty())
		ssz[x] = 1;
}

int mode;

void process(int x)
{
	foreach(c, child[x])
	{
		depth[c] = depth[x] + 1;
		process(c);
	}
	ans[x] = 1;
	if ((depth[x] % 2 == 0) == (mode == 1))
	{
		foreach(c, child[x])
			ans[x] = max(ans[x], ans[c] + ssz[x] - ssz[c]);
	}
	else
	{
		foreach(c, child[x])
			ans[x] += ans[c] - 1;
	}
}

int main()
{
	rint(N);
	jk(N - 1)
	{
		nrint(a);
		nrint(b);
		a--; b--;
		child[a].pb(b);
	}
	pp(0);
	mode = 1;
	process(0);
	printf("%d ", ans[0]);
	mode = 2;
	process(0);
	printf("%d\n", ssz[0] - ans[0] + 1);
}