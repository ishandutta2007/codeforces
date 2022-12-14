#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n), d(n);
	for(int i=0;i<n;i++)
		cin >> h[i];
	for(int i=0;i<n;i++)
		d[i] = abs(h[(i + 1) % n] - h[i]);
	int p = min_element(d.begin(), d.end()) - d.begin(), q = (p + 1) % n;
	cout << p + 1 << ' ' << q + 1 << endl;
}