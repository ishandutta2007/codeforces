#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int ST[4 * 2 * 100000];

int n;
void build(vector<int> &a, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (l + 1 == r){
		ST[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(a, l, m, v * 2);
	build(a, m, r, v * 2 + 1);
	ST[v] = __gcd(ST[v * 2], ST[v * 2 + 1]);
}

int gcd(int ql, int qr, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (ql <= l && r <= qr) return ST[v];
	if (qr <= l || r <= ql) return 0;
	int m = (l + r) / 2;
	return __gcd(gcd(ql, qr, l, m, v * 2), gcd(ql, qr, m, r, v * 2 + 1));
}

void solve(int test_ind){
	cin >> n;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	build(a);
	vector<int> ans(n);
	ans[0] = a[0] == 1;
	int ql = a[0] == 1;
	for (int i=1;i<n;++i) {
		ans[i] = ans[i-1];
		if (a[i] == 1){
			ans[i]++;
			ql = i+1;
			continue;
		}
		if (ql > i) {
			continue;
		}
		int l=ql, r=i;
		while (r - l > 1){
			int m = (l + r) / 2;
			if (gcd(m, i+1) <= i-m+1) l = m;
			else r = m;
		}
		if (gcd(l, i+1) == i + 1 - l) {ans[i]++;ql=i+1;}
	}

	for (int i: ans) printf("%d ", i);
	cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}