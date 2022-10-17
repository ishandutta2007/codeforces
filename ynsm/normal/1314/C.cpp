#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1010;
 
int n, m, nn, pref[N][N], id[N][N];
pii p[N * N];
ll k, dp[N][N], suf[N][N];
char s[N];
bool cmp(pii a, pii b){
	if(a.f == b.f)
		return a.s < b.s;
	if(a.f + pref[a.f][b.f] <= a.s && b.f + pref[a.f][b.f] <= b.s)
		return s[a.f + pref[a.f][b.f]] < s[b.f + pref[a.f][b.f]];				
	else
		return a.s - a.f < b.s - b.f;
}
void add(ll &a, ll b){
	a += b;
	if(a > k)
		a = k;
}
ll get(int x){
	ll res = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			suf[i][j] = 0, dp[i][j] = 0;
	dp[0][0] = 1;					
	for(int i = 0; i <= n; i++){
		int j = i;
		while(j < n && id[i][j] < x)
			j++;
	    for(int w = 0; w <= m; w++){
			add(dp[i][w], suf[i][w]);
			add(suf[i + 1][w], suf[i][w]);
		}
        for(int w = 0; w < m; w++)
			add(suf[j + 1][w + 1], dp[i][w]);
	}
	return dp[n][m];
}
int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	scanf("%s", &s);
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			p[nn++] = {i, j};
	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j >= 0; j--){
			if(s[i] == s[j])
				pref[i][j] = pref[i + 1][j + 1] + 1;
			else
				pref[i][j] = 0;
		}
	}
	sort(p, p + nn, cmp);
	for(int i = 0; i < nn; i++)
		id[p[i].f][p[i].s] = i;
	int l = 0, r = nn;
	while(l <= r){
		int m = (l + r) >> 1;
		if(get(m) == k)
			l = m + 1;
		else
			r = m - 1;
	}
	l--;
	for(int i = p[l].f; i <= p[l].s; i++)
		printf("%c", s[i]);
}