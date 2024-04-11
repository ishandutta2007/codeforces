// https://codeforces.com/problemset/problem/1575/F
// Finding Expected Value

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;

long long binpow(long long a, long long p){
    return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
    return binpow(a, MOD-2);
}

struct ZP{
    long long a;
    ZP(): ZP(0){}
    ZP(long long a) : a(((a % MOD) + MOD) % MOD) {}
    ZP operator+(const ZP& b) const {
        return ZP(a + b.a);
    }
    ZP operator*(const ZP& b) const {
        return ZP(a * b.a);
    }
    ZP operator-(const ZP& b) const {
        return ZP(a - b.a);
    }
    ZP operator/(const ZP& b) const {
        return ZP(a * bininv(b.a));
    }
    ZP operator-() const {
        return ZP(-a);
    }

    ZP operator+=(const ZP& b) {
        a = (a + b.a) % MOD;
        return *this;
    }

    ZP operator*=(const ZP& b) {
        a = (a * b.a) % MOD;
        return *this;
    }

    ZP operator-=(const ZP& b) {
        a = (a - b.a + MOD) % MOD;
        return *this;
    }

    ZP operator/=(const ZP& b) {
        a = (a * bininv(b.a)) % MOD;
        return *this;
    }
};

int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);

    vector<ZP> f(n + 1);

    // one pile case
    // expected number of moves = F[last] - F[first]
    // f(a) + 1 = (a * f(a) + (n-a) * (k-1) * f(a) + a * (k - 1) * f(a-1) + (n - a) * f(a+1)) / nk
    // (nk - a - (n-a) * (k-1)) * f(a) + nk = (a * (k - 1) * f(a-1) + (n - a) * f(a+1))
    // f(a+1) = [(nk - a - (n-a) * (k-1)) * f(a) + nk - a * (k - 1) * f(a-1)] / (n - a)

    for (int i=0;i<n;++i){
        f[i+1] = n * k  - i - (n - i) * (k - 1);
        f[i+1] *= f[i];
        f[i+1] += n * k;
        if (i) f[i+1] -= (ZP(k-1) * i) * f[i-1];
        f[i+1] /= (n - i);
    }

    // cout << f[0].a << " " << f[1].a << " " << f[2].a << " " << f[3].a << endl;

    // multiple piles case
    // expected number of moves = SUM[F[last] - F[first] for each x] / k

    map<int, int> cnt;
    for (int i=0;i<n;++i){
        cnt[a[i]]++;
    }
    int c_1 = cnt[-1];

    vector<ZP> C(c_1+1);
    C[0] = 1;
    for (int i=1;i<=c_1;++i){
        // c_1! / (c_1 - i)! / i!
        C[i] = C[i-1] / i;
        C[i] *= (c_1 - i + 1);
    }
    cnt.erase(-1);
    map<int, int> cntcnt;
    for (auto &p: cnt){
        cntcnt[p.second]++;
    }

    ZP answer = 0;
    for (int d=0;d<=c_1;++d){
        // C[c_1][d] * (k-1)**(c_1-d)
        ZP coef = C[d] * binpow(k-1, c_1 - d);
        for (auto &p: cntcnt){
            answer -= coef * f[p.first+d] * p.second;
        }
        answer -= coef * f[d] * (k - cnt.size());
    }
    answer /= binpow(k, c_1);
    answer += f[n];
    answer /= k;

    cout << answer.a << endl;

    return 0;
}