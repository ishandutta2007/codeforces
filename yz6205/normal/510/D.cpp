#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
	return b == 0 ? a : gcd(b,a % b);
}

const int N = 305;
int a[N],c[N];
int n;

void init() {
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) scanf("%d",&c[i]);
}

map < int , int > dp[2];

void checkMin(int& a,int b) {
	if (b < a) a = b;
}

void solve() {
	int cur = 0;
	dp[cur][a[1]] = c[1];
	dp[cur][   0] = 0;
	for (int i=2; i<=n; i++) {
		dp[cur ^ 1].clear();
		for (map < int , int > :: iterator it = dp[cur].begin();
		        it != dp[cur].end(); ++it) {
			int g = it->first;
			int s = it->second;
//			cout << g << ' ' << s << endl;
			if (dp[cur ^ 1].count(g)) checkMin(dp[cur ^ 1][g],s);
			else dp[cur ^ 1][g] = s;
			
			if (dp[cur ^ 1].count(gcd(g,a[i])))
				checkMin(dp[cur ^ 1][gcd(g,a[i])],s + c[i]);
			else dp[cur ^ 1][gcd(g,a[i])] = s + c[i];
		}
		cur ^= 1;
//		puts("pass");
	}
	if (dp[cur].count(1)) printf("%d\n",dp[cur][1]);
	else puts("-1");
}

int main() {
	init();
	solve();
	return 0;
}