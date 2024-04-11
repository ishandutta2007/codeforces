#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
vector< int > g[N];
int n, a[N], k, st[N], L[N], R[N], cnt[N];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	k = 0;
	for(int i = 0; i < n; i++){
		while(k && a[st[k - 1]] >= a[i])
			k--; 
		if(k)
			L[i] = st[k - 1] + 1;
		else
			L[i] = 0;
		st[k++] = i;
	}
	k = 0;
	for(int i = n - 1; i >= 0; i--){
		while(k && a[st[k - 1]] > a[i])
			k--; 
		if(k)
			R[i] = st[k - 1] - 1;
		else
			R[i] = n - 1;
		st[k++] = i;
	}
	for(int i = 1; i <= n; i++)
		g[i].clear();
	for(int i = 0; i < n; i++){
		int len = R[i] - L[i] + 1;
		g[len].pb(i);
	}	
	int sz = 0, usz = 0;
	ll s = 0;
	for(int i = 1; i <= n; i++)
		cnt[i] = 0;
	for(int i = 1; i <= n; i++){
		for(auto j : g[i]){
			sz++;
			usz -= (cnt[a[j]] == 1);
			cnt[a[j]]++;
			usz += (cnt[a[j]] == 1);
			s += a[j];
		}
	}
	for(int i = 1; i <= n; i++){
		if(sz == usz && sz == (n - i + 1) && s == (ll)(n - i + 1) * (n - i + 2) / 2)
			printf("1");
		else
			printf("0");
		for(auto j : g[i]){
			sz--;
			usz -= (cnt[a[j]] == 1);
			cnt[a[j]]--;
			usz += (cnt[a[j]] == 1);
			s -= a[j];
		}
	}
	printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}