#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const long long MOD = 998244353;

long long binpow(long long a, long long p){
    return p>0?binpow(a*a%MOD, p>>1) * (p%2?a:1)%MOD: 1;
}

long long bininv(long long a){
    return binpow(a, MOD-2);
}

long long fact(long long a, long long k=1){
    long long p = 1;
    for (int i=k;i<=a;++i)
        (p *= i) %= MOD;
    return p;
}

long long C(int n, int k){
    if (n == 0) return 1;
    return fact(n, n - k + 1) * bininv(fact(k)) % MOD;
}

void solve(int test_ind){
    int n;
    cin >> n;
    vector<long long> v(2 * n);
    for(int i=0;i<v.size();++i){
        int x;
        scanf("%d", &x);
        v[i] = x;
    }
    sort(v.begin(), v.end());
    long long count = C(2 * n, n);
    long long s = 0;
    for (long long i=0;i<v.size();++i){
        (s += v[i] * (i<n?MOD-count:count) % MOD) %= MOD;
    }
    cout << s << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}