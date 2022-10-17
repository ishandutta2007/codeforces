#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1e6 + 100, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, a[N], pr[N];
bool was[N];
vector< int > v[2][2];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		bool OK = 1;
		for(int i = 0; i < 2; i++){
			scanf("%d", &n);
			bitset< N > dp;
			dp[0] = 1;
			int s = 0;
			for(int j = 0; j < n; j++)
				was[j] = 0;
			v[i][0].clear();
			v[i][1].clear();
			for(int j = 0; j < n; j++){
				scanf("%d", &a[j]);
				s += a[j];
				bitset< N > tmp = dp, ndp;
				tmp <<= a[j];
				ndp = dp | tmp;
				tmp = ndp ^ dp;
				dp = ndp;
				for(int q = tmp._Find_first(); q < N; q = tmp._Find_next(q))
					pr[q] = j;
			}
			if((s & 1) || !dp[s / 2])
				OK = 0;
			else{
				s /= 2;
				while(s){
					was[pr[s]] = 1;
					s -= a[pr[s]];				
				}
				for(int j = 0; j < n; j++)
					v[i][was[j]].pb(a[j]);	
			}
		}
		if(!OK || v[0][0].size() + v[0][1].size() != v[1][0].size() + v[1][1].size()){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		vector< int > X, Y;                  
		if(v[0][0].size() > v[0][1].size())
			swap(v[0][0], v[0][1]);          
		if(v[1][0].size() < v[1][1].size())
			swap(v[1][0], v[1][1]);          
		sort(v[0][0].begin(), v[0][0].end());
		sort(v[0][1].begin(), v[0][1].end());
		reverse(v[0][0].begin(), v[0][0].end());
		reverse(v[0][1].begin(), v[0][1].end());
		sort(v[1][0].begin(), v[1][0].end());
		sort(v[1][1].begin(), v[1][1].end());
		for(auto it : v[0][0])
			X.pb(it);
		for(auto it : v[0][1])
			X.pb(-it);
		for(auto it : v[1][0])
			Y.pb(it);
		for(auto it : v[1][1])
			Y.pb(-it);
		int x = 0, y = 0;
		for(int i = 0; i < X.size(); i++){
			x += X[i];
			printf("%d %d\n", x, y);
			y += Y[i];
			printf("%d %d\n", x, y);
		}
	}
}