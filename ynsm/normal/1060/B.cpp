#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 18;
string s;
int n, dp[50][2];
int main(){
	cin >> s;
	n = s.size();
	for(int i = 0; i < 50; i++)
		dp[i][0] = dp[i][1] = -inf;
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		int d = s[n - i] - '0';
		for(int j = 0; j < 10; j++)
			for(int q = 0; q < 10; q++){
				for(int w =  0; w <= 1; w++){
					int x = q + j + w;
					int y = x / 10;
					x %= 10;
					if(x != d)
						continue;
					dp[i][y] = max(dp[i][y], dp[i - 1][w] + j + q);
				}	

			}
	}
	cout << dp[n][0];
}