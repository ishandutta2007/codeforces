#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n;

const long long mod = 998244353;

int main(){
	while(cin >> n){
		if(n == 1){
			cout << 1 << endl;
			return 0;
		}
		long long ans = 2;
		long long fac = 1;
		for(int i = 3;i <= n;i++){
			fac = fac * (i - 1) % mod;
			ans = 1LL * i * (ans + fac + mod - 1) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}