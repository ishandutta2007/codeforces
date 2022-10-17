#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, k = 6, a[N], ans = inf, m, cnt[N];
vector< pii > v;
set< pii > st;
int main()
{
	for(int i = 1; i <= k; i++)
		scanf("%d", &a[i]);	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		for(int j = 1; j <= k; j++)
			v.pb({x - a[j], i});
	}
	sort(v.begin(), v.end());
	for(int i = 0, j = 0; i < v.size(); i++){
		while(j < v.size() && m < n){
			st.insert({v[j].f, j});			
			cnt[v[j].s]++;
			if(cnt[v[j].s] == 1)
				m++;
			j++;
		}
		if(m == n){
			int mn = st.begin() -> f;
			int mx = (--st.end()) -> f;
			ans = min(ans, mx - mn);
		}
		st.erase({v[i].f, i});
		cnt[v[i].s]--;
		if(cnt[v[i].s] == 0)
			m--;
	}	
	printf("%d\n", ans);
}