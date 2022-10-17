#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3000 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 18;

ll n, m, a[N], b[N], am[N], bm[N], ans, x;
int main(){
	for(int i = 0; i < N; i++)
		am[i] = bm[i] = inf;
	cin >> n >> m; 
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];              
	cin >> x;
    for(int i = 0; i < n; i++){
		ll s = 0;	
		for(int j = i; j < n; j++){
			s += a[j];
			am[j - i + 1] = min(am[j - i + 1], s);
		}
	}
	for(int i = 0; i < m; i++){
		ll s = 0;	
		for(int j = i; j < m; j++){
			s += b[j];
			bm[j - i + 1] = min(bm[j - i + 1], s);
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(am[i] *  bm[j] <= x)
				ans = max(ans, 1ll * i * j);
	cout << ans;
}