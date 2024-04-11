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
#define INF ((int) 1.5e9+10)
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

const int MX = 1e5 + 10;
int N, M;
vector<pi> edges[MX];
map<int, int> rtime[MX];
int dist[MX];
bool vis[MX];

int main()
{
	rint(N); rint(M);
	jk(M)
	{
		nrint(a);
		nrint(b);
		nrint(c);
		a--; b--;
		edges[a].pb({b, c});
		edges[b].pb({a, c});
	}
	ji(N)
	{
		nrint(k);
		int arr[k];
		jj(k) rint(arr[j]);
		reverse(arr, arr + k);
		int prev = INF;
		int v = INF;
		jj(k)
		{
			if (prev == arr[j] + 1)
			{
				rtime[i][arr[j]] = v;
			}
			else
			{
				v = rtime[i][arr[j]] = arr[j] + 1;
			}
			prev = arr[j];
		}
	}
	ji(N) dist[i] = INF;
	dist[0] = 0;
	priority_queue<pi> Q;
	Q.push({0, 0});
	while (!Q.empty())
	{
		int x = Q.top().second;
		if (x == N-1)
			break;
		Q.pop();
		if (vis[x]) continue;
		vis[x] = true;
		int& d = dist[x];
		if (rtime[x].count(d))
			d = rtime[x][d];
		foreach(e, edges[x])
		{
			int nd = d + e.second;
			if (nd < dist[e.first])
			{
				dist[e.first] = nd;
				Q.push({-nd, e.first});
			}
		}
	}
	printf("%d\n", dist[N-1] >= INF ? -1 : dist[N-1]);
}