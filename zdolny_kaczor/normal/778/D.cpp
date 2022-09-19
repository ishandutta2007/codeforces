//Maciej Houbowicz
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int MN = 51;
char a[MN][MN], b[MN][MN];
const char L = 'L', R = 'R', U = 'U', D = 'D';
vector <pair <int, int> > sol, sol2;
int n, m;
void show() {
	debug("a:\n");
	for (int i = 0; i < n; ++i)
		debug("%s\n", a[i]);
	debug("\n\n");
	debug("b:\n");
	for (int i = 0; i < n; ++i)
		debug("%s\n", b[i]);
	debug("\n\n");
}
bool move(char arr[MN][MN], int i, int j) {
	debug("move %d %d\n", i, j);
	if (arr[i][j] == U && arr[i][j + 1] == U && arr[i + 1][j] == D && arr[i + 1][j + 1] == D) {
		debug("lay horizontal\n");
		arr[i][j] = arr[i + 1][j] = L;
		arr[i][j + 1] = arr[i + 1][j + 1] = R;
	}
	else if (arr[i][j] == L && arr[i + 1][j] == L && arr[i][j + 1] == R && arr[i + 1][j + 1] == R) {
		debug("lay vertical");
		arr[i][j] = arr[i][j + 1] = U;
		arr[i + 1][j] = arr[i + 1][j + 1] = D;
	}
	else {
		debug("failed\n");
		return false;
	}
	sol.emplace_back(i, j);
	return true;
	debug("reach:\n");
	show();
}
void push(char arr[MN][MN], int i, int k, bool ver) {
	char aim = ver ? U : L;
	debug("push %d %d try to reach %c\n", i, k, aim);
	show();
	assert(arr[i][k] == L || arr[i][k] == U);
	if (arr[i][k] != aim) {
		if (!move(arr, i, k)) {
			push(arr, i + ver, k + !ver, !ver);
			move(arr, i, k);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%s", b[i]);
	if (n % 2) {
		debug("n is odd\n");
		for (int k = 0; k < m; k += 2)
			for (int i = 0; i < n; ++i)
				push(a, i, k, false);
		
		swap(sol, sol2);
		debug("board 2\n");
		for (int k = 0; k < m; k += 2)
			for (int i = 0; i < n; i++)
				push(b, i, k, false);
	}
	else {
		debug("n is even\n");
		for (int i = 0; i < n; i += 2)
			for (int k = 0; k < m; k++)
				push(a, i, k, true);
		swap(sol, sol2);
		debug("board 2\n");
		for (int i = 0; i < n; i += 2)
			for (int k = 0; k < m; k++)
				push(b, i, k, true);
	}
	printf("%d\n", (int)(sol.size() + sol2.size()));
	reverse(sol.begin(), sol.end());
	for (auto x : sol2)
		printf("%d %d\n", x.first + 1, x.second + 1);
	for (auto x : sol)
		printf("%d %d\n", x.first + 1, x.second + 1);
}