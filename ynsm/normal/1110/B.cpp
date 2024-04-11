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

int n, m, k, b[N], ans;
set<pair<int, int> > st;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	ans = n;
	for(int i = 2; i <= n; i++)
		st.insert({b[i] - b[i - 1] - 1, i});
	while(n > k){
		n--;
		ans += st.begin() -> f;
		st.erase(st.begin());
	}
	printf("%d", ans);
	return 0;
}