#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int M = 1e7 + 100, LOG = 30;
 
int n, m = 1, nxt[M][2], sz[M];
ll ans[LOG][2];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		int v = 0;
		for(int i = LOG - 1; i >= 0; i--){
			int c = ((x >> i) & 1);
			ans[i][c] += sz[nxt[v][c ^ 1]];
			if(!nxt[v][c]){
				nxt[v][c] = m++;
				assert(m < M);
			}
			v = nxt[v][c];
			sz[v]++;
		}
	}            
	ll k, x;
	k = x = 0;
	for(int i = 0; i < LOG; i++){
		k += min(ans[i][0], ans[i][1]);
		if(ans[i][0] > ans[i][1])
			x ^= (1 << i);
	}
	printf("%lld %lld\n", k, x);
}