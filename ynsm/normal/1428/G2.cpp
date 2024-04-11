#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1000000;
const ll INF = 1e18;
 
int k;
ll p[7], F[7], dp[7][N];
deque< int > dq;
ll calc(int i, int j, int q){
	return dp[i - 1][j + q * 9 * p[i]] - F[i] * 3 * q;
}
void flex(int i, int j, int lim, int k, int w){
	if(lim < 0)
		return;
	for(int q = 0; j + (q * 9 + k) * p[i] < N; q++){
		while(!dq.empty() && calc(i, j, dq.back()) < calc(i, j, q))
			dq.pop_back();				
		dq.push_back(q);
		while(!dq.empty() && q - dq.front() > lim)
			dq.pop_front();
		dp[i][j + (q * 9 + k) * p[i]] = max(dp[i][j + (q * 9 + k) * p[i]], calc(i, j, dq.front()) + F[i] * (3 * q + w));
	}
	while(!dq.empty())
		dq.pop_back();
}
int main()                  	
{
	scanf("%d", &k);
	for(int i = 1; i <= 6; i++)
		scanf("%lld", &F[i]);
	p[1] = 1;	
	for(int i = 2; i <= 6; i++)
		p[i] = p[i - 1] * 10;

	for(int j = 0; j <= 6; j++)
    	for(int i = 1; i < N; i++)
			dp[j][i] = -INF;
	for(int i = 1; i <= 6; i++){
		for(int j = 0; j < 9 * p[i]; j++){ 
			flex(i, j, k - 0, 0, 0); 
			
			flex(i, j, k - 1, 1, 0); 
			flex(i, j, k - 1, 2, 0); 
			flex(i, j, k - 1, 3, 1); 
			flex(i, j, k - 1, 4, 0); 
			flex(i, j, k - 1, 5, 0); 
			flex(i, j, k - 1, 6, 2); 
			flex(i, j, k - 1, 7, 0); 
			flex(i, j, k - 1, 8, 0); 
		                            
		    flex(i, j, k - 2, 4, 1); 
			flex(i, j, k - 2, 5, 1);
		    flex(i, j, k - 2, 7, 2); 
			flex(i, j, k - 2, 8, 2); 
		}
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[6][n]);
	}
}