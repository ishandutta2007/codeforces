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
#define INF ((int) 1e7+10)
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

const int MX = 3010;
vector<int> edges[MX];
int N;
int dist[MX][MX];

void bfs(int start)
{
	ji(N) dist[start][i] = INF;
	dist[start][start] = 0;
	queue<int> Q;
	Q.push(start);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		foreach(o, edges[x])
		{
			if (dist[start][o] == INF)
			{
				dist[start][o] = dist[start][x] + 1;
				Q.push(o);
			}
		}
	}
}

int S1, T1, L1;
int S2, T2, L2;

int main()
{
	rint(N);
	nrint(M);
	jk(M)
	{
		nrint(a);
		nrint(b);
		a--; b--;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	ji(N) bfs(i);
	rint(S1);
	rint(T1);
	rint(L1);
	rint(S2);
	rint(T2);
	rint(L2);
	S1--; T1--;
	S2--; T2--;
	if (dist[S1][T1] > L1 || dist[S2][T2] > L2)
	{
		printf("-1\n");
		return 0;
	}
	int ans = dist[S1][T1] + dist[S2][T2];
	jij(N, N)
	{
		jk(2)
		{
			int a =  k ? i : j;
			int b = !k ? i : j;
			int d1 = dist[S1][i] + dist[i][j] + dist[j][T1];
			int d2 = dist[S2][a] + dist[a][b] + dist[b][T2];
			int c = dist[S1][i] + dist[S2][a] + dist[a][b] + dist[j][T1] + dist[b][T2];
			if (d1 <= L1 && d2 <= L2)
				ans = min(ans, c);
		}
	}
	printf("%d\n", M - ans);
}