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

int n, a[N], ans;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++){
		if(a[0] != a[i])
			ans = max(ans, i);
		if(a[n - 1] != a[i])
			ans = max(ans, n - 1 - i);
	}
	printf("%d", ans);
	return 0;
}