#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, c[100005], w[100005], ans;
bool flag[100005];
priority_queue<pair<ll, int> >pq;
int main () {
	scanf("%lld %lld", &n, &m);
	for (int i=0; i<n; i++) scanf("%lld", &c[i]);
	for (int i=0; i<n; i++) scanf("%lld", &w[i]);
	for (int i=0; i<n; i++) {
		if (c[i]%100==0) continue;
		pq.push({-(100-c[i]%100)*w[i], i});
		m-=c[i]%100;
		if (m<0) {
			int p=pq.top().second;
			ans+=-pq.top().first;
			flag[p]=true;
			pq.pop();
			m+=100;
		}
	}
	printf("%lld\n", ans);
	for (int i=0; i<n; i++) printf("%lld %lld\n", c[i]/100+flag[i], flag[i]?0LL:c[i]%100);
	return 0;
}