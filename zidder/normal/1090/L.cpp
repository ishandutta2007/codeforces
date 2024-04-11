//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

const bool __LOG_ = true;
#define db(x) if (__LOG_) cerr << (#x) << " = " << (x) << endl;

typedef long long   ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll,  ll  > pll;

typedef vector < int > vi;
typedef vector < ll  > vl;

const int  N         = 100002;
const int  logN      = (int)log2(N)+1;

const int  MOD       = 1000000007;
const ll   MODL      = 1000000007;
const int  INF       = 1000000007;
const ll   INFL      = 1000000007ll*1000000007ll;
const ld   PI        = acos(-1);
const int  HashPrime = 31;
const ld   eps       = 1e-10;

inline void No() {
    printf("NO\n");
}
inline void Yes() {
    printf("YES\n");
}

#define fi first
#define se second

#define pb push_back

template < typename T1, typename T2 >
std::istream& operator>>(std::istream& in, std::pair < T1, T2 > &p) {
    return in >> p.fi >> p.se;
}

template < typename T1, typename T2 >
std::ostream& operator<<(std::ostream& out, const std::pair < T1, T2 > p) {
    return out << p.fi << " " << p.se;
}

template < typename T >
std::istream& operator>>(std::istream& in, vector<T> &vec) {
    for (auto &x: vec) {
        in >> x;
    }
    return in;
}

template < typename T >
std::ostream& operator<<(std::ostream& out, const vector<T> &vec) {
    for (auto x: vec) {
        out << x << " ";
    }
    return out;
}

template < typename T >
std::vector<T>& operator+=(std::vector<T> &a, const std::vector<T> &b) {
    assert(a.size() == b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        a[i] += b[i];
    }
    return a;
}

template < typename T >
std::vector<T>& operator-=(std::vector<T> &a, const std::vector<T> &b) {
    assert(a.size() == b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        a[i] -= b[i];
    }
    return a;
}

template < typename T >
std::vector<T>& operator*=(std::vector<T> &a, const std::vector<T> &b) {
    assert(a.size() == b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        a[i] *= b[i];
    }
    return a;
}

template < typename T >
std::vector<T>& operator/=(std::vector<T> &a, const std::vector<T> &b) {
    assert(a.size() == b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        a[i] /= b[i];
    }
    return a;
}

template < typename T >
std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> ans(a);
    ans += b;
    return ans;
}

template < typename T >
std::vector<T> operator-(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> ans(a);
    ans -= b;
    return ans;
}

template < typename T >
std::vector<T> operator*(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> ans(a);
    ans *= b;
    return ans;
}

template < typename T >
std::vector<T> operator/(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> ans(a);
    ans /= b;
    return ans;
}

template < typename T >
T max(std::vector < T > v) {
    T ans = v[0];
    for (auto x: v) {
        ans = max(ans, x);
    }
    return ans;
}

template < typename T >
T min(std::vector < T > v) {
    T ans = v[0];
    for (auto x: v) {
        ans = min(ans, x);
    }
    return ans;
}

// __int128 gcd(__int128 a, __int128 b) {
//     return b == 0 ? a : gcd(b, a%b);
// }
//
// __int128 abs(__int128 x) {
//     return x < 0 ? -x : x;
// }
//
// std::ostream&
// operator<<( std::ostream& dest, __int128_t value ) {
//     std::ostream::sentry s( dest );
//     if ( s ) {
//         __uint128_t tmp = value < 0 ? -value : value;
//         char buffer[ 128 ];
//         char* d = std::end( buffer );
//         do
//         {
//             -- d;
//             *d = "0123456789"[ tmp % 10 ];
//             tmp /= 10;
//         } while ( tmp != 0 );
//         if ( value < 0 ) {
//             -- d;
//             *d = '-';
//         }
//         long int len = std::end( buffer ) - d;
//         if ( dest.rdbuf()->sputn( d, len ) != len ) {
//             dest.setstate( std::ios_base::badbit );
//         }
//     }
//     return dest;
// }

////////////////////////////////////////////////////////////////////////////////////////////

void precalc() {
}

void solve() {
    long long t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;

    long long l = 0, r = t + 1;
    while(r - l > 1) {
        long long m = (r + l) / 2;
        long long a_ = min(a, m), b_ = min(b, m);
        if (a_ * ((n + 1) / 2) + b_* (n / 2) >= m * k) {
            l = m;
        }
        else
            r = m;
    }
    cout << l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);

    precalc();

    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}