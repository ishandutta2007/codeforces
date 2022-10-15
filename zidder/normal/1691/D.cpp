#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 200005;

int ST[4 * N];
pair<long long, long long> ST2[4 * N];

int n;
void build(vector<int> &a, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (l + 1 == r) {
		ST[v] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(a, l, mid, v * 2);
	build(a, mid, r, v * 2 + 1);
	ST[v] = max(ST[v * 2], ST[v * 2 + 1]);
}

int queryl(int ql, int val, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (ST[v] < val) return r;
	if (r <= ql) return r;
	if (l + 1 == r) return l;
	int mid = (l + r) / 2;
	int vl = queryl(ql, val, l, mid, 2*v);
	if (vl == mid) return queryl(ql, val, mid, r, 2*v+1);
	return vl;
}

int queryr(int qr, int val, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (ST[v] <= val) return l - 1;
	if (l >= qr) return l - 1;
	if (l + 1 == r) return l;
	int mid = (l + r) / 2;
	int vr = queryr(qr, val, mid, r, 2*v+1);
	if (vr == mid - 1) return queryr(qr, val, l, mid, 2*v);
	return vr;
}

void build2(vector<long long> &p, int l=0, int r=-1, int v=1){
	if (r == -1) r = n + 1;
	if (l + 1 == r) {
		ST2[v] = {p[l], p[l]};
		return;
	}
	int mid = (l + r) / 2;
	build2(p, l, mid, v * 2);
	build2(p, mid, r, v * 2 + 1);
	ST2[v] = {max(ST2[v * 2].first, ST2[v * 2 + 1].first), min(ST2[v * 2].second, ST2[v * 2 + 1].second)};
}

const long long INF = 1000000000000000000LL;

long long getmax(int ql, int qr, int l=0, int r=-1, int v=1){
	if (r == -1) r = n + 1;
	if (l >= qr || r <= ql) return -INF;
	if (ql <= l && r <= qr) return ST2[v].first;
	int mid = (l + r) / 2;
	return max(getmax(ql, qr, l, mid, 2*v), getmax(ql, qr, mid, r, 2*v+1));
}

long long getmin(int ql, int qr, int l=0, int r=-1, int v=1){
	if (r == -1) r = n + 1;
	if (l >= qr || r <= ql) return INF;
	if (ql <= l && r <= qr) return ST2[v].second;
	int mid = (l + r) / 2;
	return min(getmin(ql, qr, l, mid, 2*v), getmin(ql, qr, mid, r, 2*v+1));
}

void solve(int test_ind){
	scanf("%d", &n);
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	build(a);
	vector<long long> p(n+1);
	for (int i=0;i<n;++i) p[i+1] = p[i] + a[i];
	build2(p);
	// p[j+1] - p[i] - ak > 0 where i <= k <= j
	// right max p[j+1], s.t. ak >= p[k..j]
	// left min p[i], s.t. ak >= p[i..k]
	for (int i=0;i<n;++i){
		int l, r = n;
		if (i == 0) l = 0;
		else l = queryr(i, a[i]) + 1;
		if (i == n-1) r = n;
		else r = queryl(i+1, a[i]);
		// cout << i << " " << l << " " << r << endl;
		// a[l-1] >= a[i] && a[l] < a[i] && a[r] >= a[i]
		if (getmax(i + 1, r + 1) - getmin(l, i + 1) - a[i] > 0) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}