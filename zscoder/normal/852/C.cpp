#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 100005;
int a[MAX], b[MAX];
vector<pii> v;
int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) { scanf("%d", &a[i]); }
	a[n] = a[0];
	for (int i=0; i<n; i++) {
		v.push_back({n-a[i]-a[i+1], i}); 
	}
	sort(v.begin(), v.end());
	for (int i=0; i<n; i++) {
		b[v[i].second] = n-1-i;
	}
	for (int i=0; i<n; i++) {
		printf("%d ", b[i]);
	}
}