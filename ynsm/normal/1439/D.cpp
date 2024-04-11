#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 505;
int n, m, mod;
ll C[N][N];
pll dp[N], DP[N][N], mt[N][N];

pll add(pll &a, pll b){
	a.f = (a.f + b.f);
	a.s = (a.s + b.s);	
	if(a.f >= mod)
		a.f -= mod;
	if(a.s >= mod)
		a.s -= mod;
}
pll mult(pll a, pll b){
	return {(a.f * b.s + b.f * a.s) % mod, a.s * b.s % mod};
}
int main()
{
	cin >> n >> m >> mod;
	
	for(int i = 0; i < N; i++)
		C[i][0] = 1;
 	for(int i = 1; i < N; i++)
 		for(int j = 1; j < N; j++)
 			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	dp[0] = {0, 1};
	mt[0][0] = mult(dp[0], dp[0]);
	for(int i = 1; i <= 500; i++){
		for(int j = 0; j < i; j++){
			for(int q = 0; q < i; q++){
				if(q <= j)
					add(dp[i], mult(mp((j - q) * C[i - 1][q] % mod, C[i - 1][q]), mt[q][i - q - 1]));
				if(q >= j)
					add(dp[i], mult(mp((q - j) * C[i - 1][q] % mod, C[i - 1][q]), mt[q][i - q - 1]));
			}
		}
		for(int j = 0; j <= i; j++)
			mt[j][i] = mt[i][j] = mult(dp[i], dp[j]);
	}
	DP[0][0] = {0, 1};
	for(int i = 1; i <= 500; i++){
		for(int j = 0; j <= i; j++){
			if(i == j){
				DP[i][j] = dp[i];
				continue;
			}
			add(DP[i][j], DP[i - 1][j]);
			for(int q = 1; q <= j; q++)
				add(DP[i][j], mult(mp(0, C[j][q]), mult(DP[i - q - 1][j - q], dp[q])));		
		}
	}
	
	cout << DP[n][m].f << endl;
}