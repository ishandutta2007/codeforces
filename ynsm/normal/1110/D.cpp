#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, cnt[N], dp[3][3][N], ans;
int main()
{
	scanf("%d%d", &n, &m);
	while(n--){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < 3; j++)
			for(int q = 0; q < 3; q++)
				dp[j][q][i] = -1;
	dp[0][0][0] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < 3; j++){
			for(int q = 0; q < 3; q++){
				if(dp[j][q][i - 1] == -1)
					continue;
				int a = cnt[i] - j - q;
				int b = cnt[i + 1] - q;
				int c = cnt[i + 2];
				for(int w = 0; w < 3; w++)
					if(w <= a && w <= b && w <= c)
						dp[q][w][i] = max(dp[q][w][i], dp[j][q][i - 1] + (a - w) / 3 + w);
			}
		}
	}
	for(int j = 0; j < 3; j++)
		for(int q = 0; q < 3; q++)
			ans = max(ans, dp[j][q][m]);
	printf("%d", ans);
	return 0;
}