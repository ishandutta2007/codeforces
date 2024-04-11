#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	if(k > 1000000 || (k*(k+1)) > 2LL*n) cout << -1 << endl;
	else {
		long long cota = (k*(k+1))/2, cand = 1;
		for(long long d = 1; d*d <= n; d++) {
			if(n % d == 0 && n/d >= cota) cand = max(cand, d);
			if(n % d == 0 && d >= cota) cand = max(cand, n/d);
		}
		
		for(int i = 1; i < k; i++) {
			cout << i*cand << " ";
			n-=i*cand;
		}
		cout << n << endl;
	}
}