//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL





#include <array>

#include <cassert>

#include <chrono>

#include <cstdint>

#include <type_traits>



namespace yosupo {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

} // namespace internal

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) { return __builtin_ctz(n); }
// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned long n) { return __builtin_ctzl(n); }
// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned long long n) { return __builtin_ctzll(n); }

// @param n `1 <= n`
// @return maximum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsr(unsigned int n) {
    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);
}
// @param n `1 <= n`
// @return maximum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsr(unsigned long n) {
    return 8 * (int)sizeof(unsigned long) - 1 - __builtin_clzl(n);
}
// @param n `1 <= n`
// @return maximum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsr(unsigned long long n) {
    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);
}

} // namespace yosupo

namespace yosupo {

struct Xoshiro256StarStar {
  public:
    using result_type = uint64_t;
    Xoshiro256StarStar() : Xoshiro256StarStar(0) {}
    explicit Xoshiro256StarStar(uint64_t seed) {
        // use splitmix64
        // Reference: http://xoshiro.di.unimi.it/splitmix64.c
        for (int i = 0; i < 4; i++) {
            uint64_t z = (seed += 0x9e3779b97f4a7c15);
            z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
            z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
            s[i] = z ^ (z >> 31);
        }
    }

    static constexpr result_type min() { return 0; }
    static constexpr result_type max() { return -1; }

    result_type operator()() {
        const uint64_t result_starstar = rotl(s[1] * 5, 7) * 9;

        const uint64_t t = s[1] << 17;

        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];

        s[2] ^= t;

        s[3] = rotl(s[3], 45);

        return result_starstar;
    }

  private:
    // Use xoshiro256**
    // Refereces: http://xoshiro.di.unimi.it/xoshiro256starstar.c
    static uint64_t rotl(const uint64_t x, int k) {
        return (x << k) | (x >> (64 - k));
    }

    std::array<uint64_t, 4> s;
};

namespace internal {

// random choice from [0, upper]
template <class G> uint64_t uniform(uint64_t upper, G& gen) {
    static_assert(std::is_same<uint64_t, typename G::result_type>::value, "");
    static_assert(G::min() == 0, "");
    static_assert(G::max() == uint64_t(-1), "");
    if (!(upper & (upper + 1))) {
        // b = 00..0011..11
        return gen() & upper;
    }
    int log = bsr(upper);
    uint64_t mask = (log == 63) ? ~0ULL : (1ULL << (log + 1)) - 1;
    while (true) {
        uint64_t r = gen() & mask;
        if (r <= upper) return r;
    }
}

} // namespace internal

Xoshiro256StarStar& global_gen() {
    static Xoshiro256StarStar gen(
        std::chrono::steady_clock::now().time_since_epoch().count());
    return gen;
}

template <class T, class G> T uniform(T lower, T upper, G& gen) {
    return T(lower + internal::uniform(uint64_t(upper) - uint64_t(lower), gen));
}
template <class T> T uniform(T lower, T upper) {
    return uniform(lower, upper, global_gen());
}

template <class G> bool uniform_bool(G& gen) {
    return internal::uniform(1, gen) == 1;
}
bool uniform_bool() { return uniform_bool(global_gen()); }

template <class T, class G>
std::pair<T, T> uniform_pair(T lower, T upper, G& gen) {
    assert(upper - lower >= 1);
    T a, b;
    do {
        a = uniform(lower, upper, gen);
        b = uniform(lower, upper, gen);
    } while (a == b);
    if (a > b) std::swap(a, b);
    return {a, b};
}
template <class T> std::pair<T, T> uniform_pair(T lower, T upper) {
    return uniform_pair(lower, upper, global_gen());
}

} // namespace yosupo
using namespace yosupo;




#include <algorithm>


#include <bitset>


#include <complex>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

const bool DEBUG = false;

int n, m;

int mod_nm(int x) {
    return (x % (n * m) + n * m) % (n * m);
}

int zpos = 0;
V<int> qhist;

V<int> cor_pos;
void init() {
    cin >> n >> m;
    if (DEBUG) {
        cor_pos = V<int>(n);
        for (int i = 1; i < n; i++) {
            cor_pos[i] = uniform(0, n * m - 1);
        }
    }
}

int qc = 0;

// 1: expand wall
// 0: same
//-1: shrink
int query(int x, int d) {
    qc++;
    if (x == 0) {
        zpos = mod_nm(zpos + d);
    }

    int a;
    if (DEBUG) {
        cor_pos[x] = mod_nm(cor_pos[x] + d);
        V<bool> vis(n * m);
        for (int i = 0; i < n; i++) {
            int p = cor_pos[i];
            for (int j = 0; j < m; j++) {
                vis[p] = true;
                p++;
                if (p == n * m) p = 0;
            }
        }
        a = n * m;
        for (int i = 0; i < n * m; i++) {
            if (vis[i]) a--;
        }
    } else {
        cout << "? " << x << " " << d << endl;
        cin >> a;
    }


    // COMMON
    int ans = 0;
    if (qhist.size()) ans = - (a - qhist.back());
    qhist.push_back(a);

    return ans;
}

void answer(V<int> v) {

    if (DEBUG) {
        V<int> cor;
        for (int i = 1; i < n; i++) {
            cor.push_back(mod_nm(cor_pos[i] - cor_pos[0]));
        }
                       ;
        assert(cor == v);
        assert(qc <= 15000);
    } else {
        cout << "!";
        for (int x : v) {
            cout << " " << x;
        }
        cout << endl;
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    for (int i = 0; i < 300; i++) {
        query(uniform(0, n - 1), uniform(0, 1) * 2 - 1);
    }
    query(0, 1);

    V<int> pos(n, -1);
    pos[0] = 0;

    int rem = n - 1;
    V<bool> pred(n);

    while (rem) {
        while (true) {
            if (query(0, 1) == -1) {
                break;
            }
        }
        while (true) {
            if (query(0, 1) != -1) {
                query(0, -1);
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            if (pos[i] != -1) continue;
            if (pred[i]) continue;
            if (query(i, -1) == 1) {
                pred[i] = true;
            }
            query(i, 1);
        }
        query(0, -1);
        V<int> vs;
        for (int i = 1; i < n; i++) {
            if (pos[i] != -1) continue;
            if (!pred[i]) continue;
            if (query(i, -1) == 1) {
                query(i, 1);
                continue;
            }
            vs.push_back(i);
        }
        for (int i : vs) {
            for (int ph = 0; ph < m - 1; ph++) {
                query(i, -1);
            }
            pos[i] = mod_nm(zpos - (m - 1));
            rem--;
        }
    }

    V<int> ans;
    for (int i = 1; i < n; i++) {
        ans.push_back(mod_nm(pos[i] - zpos));
    }

    answer(ans);


    return 0;
}