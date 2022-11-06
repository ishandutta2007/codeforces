#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;




const int mod = 1000000007;
struct Mod {
public:
    int num;
    Mod() : num(0) { ; }
    Mod(long long int n) : num((n % mod + mod) % mod) { ; }
    Mod(int n) : num((n % mod + mod) % mod) { ; }
    operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
    if (n == 0) return Mod(1);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
    assert(b.num != 0);
    return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
    assert(b.num != 0);
    return Mod(a) * inv(b);
}
Mod operator/=(Mod &a, const Mod b) {
    assert(b.num != 0);
    return a = a * inv(b);
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init() {
    fact[0] = Mod(1); factinv[0] = 1;
    for (int i = 0; i < MAX_MOD_N - 1; ++i) {
        fact[i + 1] = fact[i] * Mod(i + 1);
        factinv[i + 1] = factinv[i] / Mod(i + 1);
    }
}
Mod comb(const int a, const int b) {
    return fact[a] * factinv[b] * factinv[a - b];
}

int main() {
    int n; cin >> n;
    map<long long int, long long int>mp;
    for (int i = 0; i < n; ++i) {
        long long int a; cin >> a;
        mp[a]++;
    }
    

    bool allki = true;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second%2) {
            allki = false; break;
        }
    }
    if (!allki) {

        Mod ans(1);
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            for (int i = 0; i < it->second; ++i) {
                ans *= it->first;
            }
        }

        bool ok = false;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            Mod num(1);
            if ((!ok) && (it->second + 1) % 2 == 0) {
                ok = true;
                for (int i = 0; i < (it->second + 1) / 2; ++i) {
                    num *= ans;
                }
            }
            else {
                for (int i = 0; i < it->second + 1; ++i) {
                    num *= ans;
                }
            }
            ans = num;
        }
        cout << ans << endl;
    }
    else {
        Mod ans(1);
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            for (int i = 0; i < it->second/2; ++i) {
                ans *= it->first;
            }
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            Mod num(1);
            
            for (int i = 0; i < it->second + 1; ++i) {
                num *= ans;
            }
            ans = num;
            
        }
        cout << ans << endl;
    }
    
    return 0;
}