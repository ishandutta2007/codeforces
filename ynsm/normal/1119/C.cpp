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

int n, m, a[1000][1000];
int main()
{
	scanf("%d%d", &n, &m);        
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			int x;
			scanf("%d", &x);
			a[i][j] ^= x;
		}
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = 0; j < m; j++)
			cnt += a[i][j];
		if(((cnt & 1) && i + 1 < n) || (cnt && i == n - 1)){
			puts("No");
			return 0;
		}
		for(int j = 0; j < m; j++)
			a[i + 1][j] ^= a[i][j];
	}
	puts("Yes");
	return 0;
}