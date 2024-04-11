#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	
	long long sum = 0, tope = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		tope = max(tope, a[i]);
		sum += a[i];
	}
	
	cout << max(tope, (sum+n-2)/(n-1)) << endl;
}