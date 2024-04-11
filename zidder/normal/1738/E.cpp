#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

long long binpow(long long a, long long p) {
    return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
    return binpow(a, MOD-2);
}

void solve(int test_ind){
	int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    vector<int> pw(n);
    pw[0] = 1;
    for (int i=1;i<n;++i) pw[i] = pw[i-1] * 2 % MOD;
    long long sm = 0;
    for (int i: a) sm += i;
    int ans = 1;
    if (sm == 0 || n == 1) {
        ans = pw[n-1];
        printf("%d\n", ans);
        return;
    }
    vector<int> fact(n+1), ifact(n+1);
    fact[0] = 1;
    for (int i=1;i<=n;++i) fact[i] = fact[i-1] * 1ll * i % MOD;
    for (int i=0;i<=n;++i) ifact[i] = bininv(fact[i]);
    long long lft = 0, rght = 0;
    int l = 0;
    int cl = 0;
    int cr = 0;
    int r = n - 1;

    auto C = [&](int n, int k) -> long long {
        return fact[n] * 1ll * ifact[k] % MOD * ifact[n-k] % MOD;
    };

    auto f = [&](int cl, int cr) -> long long {
        long long res = 0;
        for (int i=0;i<=min(cl, cr);++i) {
            res += C(cl, i) * C(cr, i) % MOD;
        }
        return res % MOD;
    };

    while (l <= r) {
        if (lft == rght) {
            ans = ans * f(cl, cr) % MOD;
            if (l == r) {
                break;
            }
            cl = 1;
            cr = 1;
            lft += a[l];
            l++;
            rght += a[r];
            r--;
            if (l > r) {
                if (lft == rght) {
                    ans = ans * f(cl, cr) % MOD;
                }
                break;
            }
                // cerr << l << " " << r << " " << lft << " " << rght << " " << cl << " " << cr << " " << ans << endl;
            while (a[l] == 0) {l++;cl++;}
            if (l > r) {
                if (lft == rght) {
                    ans = ans * 1ll * pw[cl] % MOD;
                }
                break;
            }
            while (a[r] == 0) {r--;cr++;}
            if (l > r) {
                if (lft == rght) {
                    ans = ans * f(cl, cr) % MOD;
                }
                break;
            }
            continue;
            // cout << l << " " << lft << " " << r << " " << rght << endl;
            // cout << ans << endl;
        } else {
            if (lft < rght) {
                lft += a[l];
                l++;
                cl = 1;
                while (a[l] == 0) {l++;cl++;}
                if (l > r) {
                    if (lft == rght) {
                        ans = ans * 1ll * pw[cl] % MOD;
                    }
                    break;
                }
            } else {
                rght += a[r];
                r--;
                cr = 1;
                while (a[r] == 0) {r--;cr++;}
                if (l > r) {
                    if (lft == rght) {
                        ans = ans * 1ll * pw[cr] % MOD;
                    }
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}