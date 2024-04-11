#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, ans;
pii a[100];
double C, T;
double p[1000], dp[105][1005];
double calc(double t, int n){
	return (T - t  - 10 * n) * ( 1 + t * C);
}
double get(int n){
	double l = 0, r = T - 10 * n;
	for(int i = 0; i < 1000 && l <= r; i++){
		double m1 = l + (r - l) / 3;
		double m2 = l + 2 * (r - l) / 3;
		if(calc(m1, n) < calc(m2, n))
			l = m1;
		else
			r = m2;
	}
	return calc(l, n);
}
void solve(){
	cin >> n;
	cin >> C >> T;
	for(int i = 0; i < n; i++)
		cin >> a[i].f >> a[i].s;
	sort(a, a + n);
	reverse(a, a + n);
	
	for(int i = 0; i <= 100; i++)
	 	for(int j = 0; j <= 1000; j++)
	 		dp[i][j] = -1;
	dp[0][0] = 0;
	ans = 0;
	
	for(int i = 0; i < n; i++)
		for(int q = i; q >= 0; q--)
			for(int j = 0; j <= 10 * q; j++)
				if(dp[q][j] != -1 && (dp[q + 1][j + a[i].s] == -1 ||  dp[q + 1][j + a[i].s] > dp[q][j] + a[i].f / p[q + 1]))
					dp[q + 1][j + a[i].s] = dp[q][j] + a[i].f / p[q + 1]; 
	
	for(int i = 1; i <= n; i++){
		double val = get(i);
		for(int j = 0; j <= i * 10; j++){
			double x = dp[i][j];
		    if(x == -1)
		    	continue;
			if(x <= val){
				ans = max(ans, j);
			}
		}
	}
	cout << ans << endl;
}

int main(){
	p[0] = 1;
	for(int i = 1; i < 1000; i++)
		p[i] = p[i - 1] * 0.9;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}