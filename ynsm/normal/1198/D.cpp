#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[55][55], dp[55][55][55][55];
bool was[55][55][55][55];
char s[55];
int calc(int xa, int ya, int xb, int yb){
	if(was[xa][ya][xb][yb])
		return dp[xa][ya][xb][yb];
	was[xa][ya][xb][yb] = 1;
	if(xa == xb && ya == yb)
		return dp[xa][ya][xb][yb] = a[xa][ya];
	int res = max(xb - xa + 1, yb - ya + 1);
	for(int i = xa; i < xb; i++)
		res = min(res, calc(xa, ya, i, yb) + calc(i + 1, ya, xb, yb));
	for(int i = ya; i < yb; i++)
		res = min(res, calc(xa, ya, xb, i) + calc(xa, i + 1, xb, yb));
	return dp[xa][ya][xb][yb] = res;	
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		for(int j = 1; j <= n; j++)
			a[i][j] = (s[j - 1] == '#');
	}
	calc(1, 1, n, n);
	printf("%d", dp[1][1][n][n]);
	return 0;
}