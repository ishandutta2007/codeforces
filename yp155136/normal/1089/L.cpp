#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const int N = 100006;

int a[N];

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<pii> v;
	for (int i=0;i<n;++i) {
		cin >> a[i];
	}
	for (int i=0;i<n;++i) {
		int x;
		cin >> x;
		v.push_back(make_pair(x,a[i]));
	}
	memset(a,0,sizeof(a));
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	priority_queue<ll,vector<ll>,greater<ll> > pq;
	for (pii p:v) {
		if (a[p.second] == 0) {
			a[p.second] = 1;
			--k;
		}
		else {
			pq.push(p.first);
		};
	}
	ll ans=0;
	while (k) {
		ans += pq.top();
		pq.pop();
		--k;
	}
	cout << ans << endl;
}