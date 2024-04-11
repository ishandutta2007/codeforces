#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1010, mod = 998244353;

int n, m, k, a[N];       

int dp[N][N], pd[N][N];

int ans, last, cur;
void add(int &a, int b){
	a += b;
	if(a >= mod)
		a -= mod;
}
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	m = 100000 / (k - 1);
	for(int i = m; i >= 0; i--){
		for(int j = 0; j <= n; j++)
			for(int q = 0; q <= k ; q++)
				dp[j][q] = pd[j][q] = 0;
		pd[0][1] = 1;
		last = cur;
		cur = 0;
		for(int j = 1, ptr = 1; j <= n; j++){
			ptr = max(ptr, j + 1);
			while(ptr <= n && a[ptr] - a[j] < i)
				ptr++;
			for(int q = 0; q <= k; q++){
				add(pd[j][q], pd[j - 1][q]);
				add(dp[j][q], pd[j][q]);
			}
			for(int q = 0; q < k; q++)
				add(pd[ptr][q + 1], dp[j][q]);			
			add(cur, dp[j][k]);
		}	
		ans = (ans + 1ll * i * (cur - last + mod)) % mod;
	}	
	cout << ans;
	return 0;
}