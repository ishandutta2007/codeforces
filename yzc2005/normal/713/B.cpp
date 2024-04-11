#include <bits/stdc++.h>
using namespace std;
int query(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	cout.flush();
	int cnt;
	cin >> cnt;
	return cnt; 
} 
array<int, 4> solve(int l1, int r1, int l2, int r2) {
	int x1, y1, x2, y2;
	int l = l1, r = r1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (query(mid, l2, r1, r2))
			x1 = mid, l = mid + 1;
		else 
			r = mid - 1;
	}
	l = l1, r = r1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (query(l1, l2, mid, r2))
			x2 = mid, r = mid - 1;
		else 
			l = mid + 1;
	} 
	l = l2, r = r2;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (query(l1, mid, r1, r2))
			y1 = mid, l = mid + 1;
		else 
			r = mid - 1;
	}
	l = l2, r = r2;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (query(l1, l2, r1, mid))
			y2 = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return array<int, 4>{x1, y1, x2, y2}; 
}
void answer(array<int, 4> a, array<int, 4> b) {
	cout << "! ";
	cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " ";
	cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << endl;
	cout.flush();
}
int main() {
	int n;
	cin >> n;
	int l = 1, r = n, pos = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int cur = query(1, 1, mid, n);
		if (cur >= 1)
			pos = mid, r = mid - 1;
		else 
			l = mid + 1;
	}
	assert(pos);
	if (pos < n && query(1, 1, pos, n) == 1 && query(pos + 1, 1, n, n) == 1) {
		auto a = solve(1, pos, 1, n);
		auto b = solve(pos + 1, n, 1, n);
		answer(a, b);
		return 0;
	}
	l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int cur = query(1, 1, n, mid);
		if (cur >= 1)
			pos = mid, r = mid - 1;
		else 
			l = mid + 1;
	}
	auto a = solve(1, n, 1, pos);
	auto b = solve(1, n, pos + 1, n);
	answer(a, b);
	return 0;
}