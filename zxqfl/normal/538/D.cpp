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

char board[200][200];
bool attacked[200][200];
char ans[200][200];
int N;
vector<pi> moves;

bool works(int dx, int dy)
{
	jij(N, N) if (board[i][j] == 'o' && board[i+dx][j+dy] == '.')
		return false;
	return true;
}

int main()
{
	rint(N);
	ji(N) scanf("%s", board[i]);
	for (int i = -N + 1; i < N; i++)
	for (int j = -N + 1; j < N; j++)
		if (works(i, j))
			moves.pb({i, j});
	jij(N, N) if (board[i][j] == 'o')
	{
		foreach(m, moves) attacked[i+m.first][j+m.second] = true;
	}
	jij(N, N)
	{
		if (board[i][j] == 'x' && !attacked[i][j])
		{
			printf("NO\n");
			return 0;
		}
	}
	int B = 2 * N - 1;
	jij(B, B) ans[i][j] = '.';
	foreach(m, moves) ans[N-1+m.first][N-1+m.second] = 'x';
	ans[N-1][N-1] = 'o';
	printf("YES\n");
	ji(B) printf("%s\n", ans[i]);
}