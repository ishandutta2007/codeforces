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

const int MX = 1000;
int bip[MX];
vector<int> edges[MX];
vector<int> component;
int dist[MX];

void fail()
{
	printf("-1\n");
	exit(0);
}

void dfs(int x, int t)
{
	if (bip[x])
	{
		if (bip[x] != t)
			fail();
	}
	else
	{
		component.pb(x);
		bip[x] = t;
		foreach(o, edges[x])
			dfs(o, t ^ 2);
	}
}

int ans;

int bfs(int start)
{
	memset(dist, -1, sizeof dist);
	dist[start] = 0;
	queue<int> Q;
	Q.push(start);
	int v = 0;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		foreach(o, edges[x])
		{
			if (dist[o] < 0)
			{
				dist[o] = v = dist[x] + 1;
				Q.push(o);
			}
		}
	}
	return v;
}

int main()
{
	nrint(N);
	nrint(M);
	jk(M)
	{
		nrint(a);
		nrint(b);
		a--; b--;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	ji(N) if (bip[i] == 0)
	{
		component.clear();
		dfs(i, 1);
		int val = 0;
		foreach(n, component)
			val = max(val, bfs(n));
		ans += val;
	}
	printf("%d\n", ans);
}