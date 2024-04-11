// https://codeforces.com/problemset/problem/895/E

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n, q;

struct Node{
	long double a = 1;
	long double b = 0;
	long double sm;
} ST[4 * 100004]; // ax + b with sum[x] sm

void build(vector<int>& a, int l=0, int r=-1, int v=1){
	if (r == -1) r=n;
	if (l + 1 == r){
		ST[v].a = 1;
		ST[v].b = 0;
		ST[v].sm = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(a, l, m, v * 2);
	build(a, m, r, v * 2 + 1);
	ST[v].a = 1;
	ST[v].b = 0;
	ST[v].sm = ST[v * 2].sm + ST[v * 2 + 1].sm;
}

void push(int v, int l, int r){
	ST[v * 2].a *= ST[v].a;
	ST[v * 2].b *= ST[v].a;
	ST[v * 2 + 1].a *= ST[v].a;
	ST[v * 2 + 1].b *= ST[v].a;
	ST[v * 2].b += ST[v].b;
	ST[v * 2 + 1].b += ST[v].b;
	ST[v].a = 1;
	ST[v].b = 0;
	int m = (l + r) / 2;
	ST[v].sm = ST[v * 2].sm * ST[v * 2].a + ST[v * 2].b * (m - l) + ST[v * 2 + 1].a * ST[v * 2 + 1].sm + ST[v * 2 + 1].b * (r - m);
}

void update_add(int ql, int qr, long double val, int l=0, int r=-1, int v=1){
	if (r == -1) r=n;
	if (ql >= r || qr <= l) return;
	if (ql <= l && qr >= r){
		if (l + 1 == r){
			ST[v].sm = ST[v].sm * ST[v].a + ST[v].b + val;
			ST[v].b = 0;
			ST[v].a = 1;
			return;
		}
		push(v, l, r);
		ST[v].b += val;
		return;
	}
	int m = (l + r) / 2;
	push(v, l, r);
	update_add(ql, qr, val, l, m, v * 2);
	update_add(ql, qr, val, m, r, v * 2 + 1);
	push(v, l, r);
}

void update_mul(int ql, int qr, long double val, int l=0, int r=-1, int v=1){
	if (r == -1) r=n;
	if (ql >= r || qr <= l) return;
	if (ql <= l && qr >= r){
		if (l + 1 == r){
			ST[v].sm = (ST[v].sm * ST[v].a + ST[v].b) * val;
			ST[v].b = 0;
			ST[v].a = 1;
			return;
		}
		ST[v].a *= val;
		ST[v].b *= val;
		push(v, l, r);
		return;
	}
	int m = (l + r) / 2;
	push(v, l, r);
	update_mul(ql, qr, val, l, m, v * 2);
	update_mul(ql, qr, val, m, r, v * 2 + 1);
	push(v, l, r);
}

long double query(int ql, int qr, int l=0, int r=-1, int v=1){
	if (r == -1) r=n;
	if (ql >= r || qr <= l) return 0;
	if (ql <= l && qr >= r) return ST[v].sm * ST[v].a + ST[v].b * (r - l);
	push(v, l, r);
	int m = (l + r) / 2;
	return query(ql, qr, l, m, v * 2) + query(ql, qr, m, r, v * 2 + 1);
}

void solve(int test_ind){
	// [a0 a1 a2 a3 a4 ... an] length = n + 1 
	// [(n a0 + x) / (n + 1) ... (n an + x) / (n + 1)] length = n + 1
	// n/n+1 * a + x / (n + 1)
	cin >> n >> q;
	vector<int> a(n);
	long double one=1;
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	build(a);
	for (int i=0;i<q;++i){
		int t;
		scanf("%d", &t);
		if (t == 1){
			int l1, r1, l2, r2;
			scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
			l1--;l2--;
			long double q1 = query(l1, r1), q2=query(l2, r2);
			q1 /= (r1 - l1);
			q2 /= (r2 - l2);
			update_mul(l1, r1, (r1-l1-one) / (r1-l1));
			update_mul(l2, r2, (r2-l2-one) / (r2-l2));
			update_add(l1, r1, q2 / (r1-l1));
			update_add(l2, r2, q1 / (r2-l2));
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			printf("%.10Lf\n", query(l, r));
		}
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}