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
 
int n, a[N], cnt[N];
void solve(){
	int ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for(int i = 0; i <= n + 1; i++)
		cnt[i] = 0;
	for(int i = 0; i + 1 < n; i++)
		if(a[i] == a[i + 1])
			ans++, cnt[a[i]] += 2;
	cnt[0]++;
	cnt[n + 1]++;
	cnt[a[0]]++;
	cnt[a[n - 1]]++;
	
	int p = 0, s = 0;
	for(int i = 0; i <= n + 1; i++){
		if(cnt[i] > cnt[p])
			p = i;	
		s += cnt[i];
	}
	int need = 2 * cnt[p] - s;
	for(int i = 0; i + 1 < n; i++)
		if(a[i] != a[i + 1] && a[i] != p && a[i + 1] != p && need > 0)
			ans++, need -= 2;
	if(need > 0)
		ans = -1;
	printf("%d\n", ans);		
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}