#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 15000100, LOG = 30, inf = 1e9;

int n, k = 1, nxt[N][2], dp[N], cnt[N]; 
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		int v = 0;
		cnt[v]++;
		for(int j = LOG - 1; j >= 0; j--){
			int c = ((x >> j) & 1);			
			if(!nxt[v][c])
				nxt[v][c] = k++;				
			v = nxt[v][c];
			cnt[v]++;
		}
	}
	for(int v = k - 1; v >= 0; v--){
		if(cnt[v] <= 2){
			dp[v] = 0;
			continue;
		}
		dp[v] = inf;                                                                 
		if(nxt[v][0])
			dp[v] = min(dp[v], dp[nxt[v][0]] + (nxt[v][1] ? cnt[nxt[v][1]] - 1 : 0));
		if(nxt[v][1])
			dp[v] = min(dp[v], dp[nxt[v][1]] + (nxt[v][0] ? cnt[nxt[v][0]] - 1 : 0));
	}
	printf("%d", dp[0]);
}