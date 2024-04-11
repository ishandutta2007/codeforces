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
 
ll n, ans, cnt[26], a[26][26];
char s[N];
int main()
{
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++){
		int x = s[i] - 'a';
		for(int j = 0; j < 26; j++)
			a[x][j] += cnt[j];
		cnt[x]++;
		ans = max(ans, cnt[x]);
		for(int j = 0; j < 26; j++)
			ans = max(ans, a[x][j]);
	}
	printf("%lld", ans);
}