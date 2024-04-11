#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

long long binpow(long long a, long long p) {
    return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
    return binpow(a, MOD-2);
}

void solve(int test_ind){
	int n;
    cin >> n;
    n++;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    for (int i=0;i<n;++i) {
        if (a[i] == 0) {
            n = i;
            break;
        }
    }
    while (a.size() > n) a.pop_back();
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> fact(500000);
    vector<int> ifact(500000);
    fact[0] = ifact[0] = 1;
    for (int i=1;i<fact.size();++i) fact[i] = fact[i-1] * 1ll * i % MOD;
    for (int i=1;i<fact.size();++i) ifact[i] = bininv(fact[i]);

    auto C = [&](int n, int k) -> long long {
        if (k < 0 || k > n) return 0;
        return fact[n] * 1ll * ifact[k] % MOD * 1ll * ifact[n-k] % MOD;
    };

    int mn = a[0];
    int op = a[0];
    for (int i=1;i<n;++i) {
        if (a[i] >= mn) {
            op = (op + C(i + mn, i+1)) % MOD;
            int nm = C(i+mn-1,i);
            int c = a[i] - mn;
            op = (op + c * 1ll * nm % MOD) % MOD;
        } else {
            op = (op + C(i + a[i], i+1)) % MOD;
            mn = a[i];
        }
    }
    cout << op << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}