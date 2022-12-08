#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), d(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int start = n;
	for(int i=0; i<n; i++) {
		if(a[i] == 0) start = 0;
		d[i] = start;
		start++;
	}
	start = n;
	for(int i=n-1; i>=0; i--) {
		if(a[i] == 0) start = 0;
		d[i] = min(d[i], start);
		start++;
	}
	
	for(int i=0; i<n; i++) {
		if(i) cout << " ";
		cout << d[i];
	}
	cout << endl;
}