#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
int n, dp[8];
int main(){
	for(int i = 1; i < 8; i++)
		dp[i] = inf; 
	cin >> n;
	for(int i = 0; i < n; i++){
		int k,cur = 0;
		string s;
		cin >> k >> s;

		for(int j = 0; j < (int)s.size(); j++)
			cur |= (1<<(s[j]-'A'));
		
		dp[cur] = min(dp[cur], k);
	}
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if(dp[(i|j)] > dp[i] + dp[j])
            	dp[(i|j)] = dp[i] + dp[j];	
	if(dp[7] == inf)
		cout << -1;
	else
		cout << dp[7];
	return 0;
}