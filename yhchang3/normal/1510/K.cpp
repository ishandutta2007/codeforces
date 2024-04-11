#include<bits/stdc++.h>
using namespace std;

void op1(vector<int> &a) {
	for(int i=0;i<a.size();i+=2)
		swap(a[i], a[i + 1]);
}
void op2(vector<int>&a) {
	const int n = a.size() / 2;
	for(int i=0;i<n;i++)
		swap(a[i], a[i + n]);
}

bool check(vector<int> &a) {
	for(int i=0;i<a.size();i++)
		if(i + 1 != a[i])
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> b(2 * n), a(2 * n);
	for(int i=0;i<n*2;i++)
		cin >> b[i];
	int ans = 1e9;
	a = b;
	if(check(a))
		ans = 0;
	for(int i=1;i<=2*n;i++) {
		op1(a);
		if(check(a)) {
			ans = min(ans, i * 2 - 1);
			break;
		}
		op2(a);
		if(check(a)) {
			ans = min(ans, i * 2);
			break;
		}
	}
	a = b;
	for(int i=1;i<=2*n;i++) {
		op2(a);
		if(check(a)) {
			ans = min(ans, i * 2 - 1);
			break;
		}
		op1(a);
		if(check(a)) {
			ans = min(ans, i * 2);
			break;
		}
	}
	if(ans == 1e9)
		ans = -1;
	cout << ans << endl;
}