#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, q, mod;
	cin >> n >> q >> mod;

	vector<int> fibo(n+2);
	fibo[0] = fibo[1] = 1;
	for(int i = 2; i <= n+1; i++){
		fibo[i] = (fibo[i-1] + fibo[i-2]) % mod;
	}

	vector<int> a(n), b(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	for (int i=0;i<n;++i) scanf("%d", &b[i]);
	for (int i=0;i<n;++i) a[i] = (a[i] + mod - b[i]) % mod;
	auto print = [&](){
		return;
		for (int i: a) cout << i << " ";
		cout << endl;
	};
	print();
	for (int i=n-1;i>0;--i){
		if (i > 1){
			a[i] = (a[i] + 0ll + mod - a[i-1] + 0ll + mod - a[i-2]) % mod;
		} else {
			if (i) a[i] = (a[i] + mod - a[i-1]) % mod;
		}
	}
	print();
	int c0 = 0;
	for (int i=0;i<n;++i) c0 += a[i] == 0;
	auto upd = [&](int ind, int val){
		if (a[ind] == 0) c0--;
		a[ind] = val;
		if (a[ind] == 0) c0++;
	};
	for (int i=0;i<q;++i){
		char c;
		int l, r;
		scanf("\n%c %d %d", &c, &l, &r);
		l--;r--;
		if (c == 'A'){
			upd(l, (a[l] + 1) % mod);
			if (l == r){
				if (l+1<n) upd(l+1, (a[l+1] + mod - 1) % mod);
				if (l+2<n) upd(l+2, (a[l+2] + mod - 1) % mod);
			} else {
				if (r+1<n) upd(r + 1, (a[r+1] + mod - fibo[r-l+1]) % mod);
				if (r+2<n) upd(r + 2, (a[r+2] + mod - fibo[r-l]) % mod);
			}
		} else {
			upd(l, (a[l] + mod -1) % mod);
			if (l == r){
				if (l+1<n) upd(l+1, (a[l+1] + 1) % mod);
				if (l+2<n) upd(l+2, (a[l+2] + 1) % mod);
			} else {
				if (r+1<n) upd(r + 1, (a[r+1] + fibo[r-l+1]) % mod);
				if (r+2<n) upd(r + 2, (a[r+2] + fibo[r-l]) % mod);
			}
		}
		if (c0 == n){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		print();
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