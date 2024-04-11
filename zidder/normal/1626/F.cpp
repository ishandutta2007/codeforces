#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#pragma optimize("O3")

using namespace std;

const int MOD = 998244353;

const int Q = 16 * 9 * 5 * 7 * 11 * 13;
long long a[Q]={}, b[Q]={};

void solve(int test_ind){
	long long n, a0, x, y, M, k;
	cin >> n >> a0 >> x >> y >> k >> M;
	a[a0 % Q]++;
	b[a0 % Q] += a0 / Q;
	for (int i=1;i<n;++i){
		a0 = (a0 * x + y) % M;
		a[a0 % Q]++;
		b[a0 % Q] += a0 / Q;
	}

	// solve for a n k

	// long long ans = 0;
    // for(int i = 1; i <= k; i++)
    // {
	// 	int idx = rnd.next(0, n - 1);
	//  ans += a[idx];
	//  a[idx] -= (a[idx] % i);
	// }

	long long res = 0;
	for (int x=1;x<=k;++x){
		(res *= n) %= MOD;
		for (int i=0;i<Q;++i){
			(res += (a[i] * i + b[i] * Q)) %= MOD;
			if (x == k) continue;
			int j = i - i % x;
			if (j < i){
				(a[j] += a[i]) %= MOD;
				(b[j] += b[i]) %= MOD;
				(a[i] *= n - 1) %= MOD;
				(b[i] *= n - 1) %= MOD;
			} else {
				(a[i] *= n) %= MOD;
				(b[i] *= n) %= MOD;
			}
		}
	}
	cout << res << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}