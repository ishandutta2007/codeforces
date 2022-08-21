//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL




#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

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



#include <unistd.h>

struct Scanner {
    int fd = -1;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += ::read(fd, line + ed, (1 << 15) - ed);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) {
            bool sep = false;
            for (size_t i = st; i < ed; i++) {
                if (isspace(line[i])) {
                    sep = true;
                    break;
                }
            }
            if (!sep) reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] & 0xf);
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* fp) : fd(fileno(fp)) {}
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val; // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char(0x30 | (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

const int BS = 200;
const int BN = 105000 / BS;
const int N = BS * BN;

const int INF = TEN(9) + TEN(7);

int dist(const set<int>& s, int x) {
    int ans = INF;
    auto it = s.lower_bound(x);
    if (it != s.end()) {
        ans = min(ans, *it - x);
    }
    if (it != s.begin()) {
        ans = min(ans, x - *prev(it));
    }
    return ans;
}








#include <chrono>

#include <cstdint>


#include <random>



struct Random {
  private:
    // Use xoshiro256**
    // Refereces: http://xoshiro.di.unimi.it/xoshiro256starstar.c
    static uint64_t rotl(const uint64_t x, int k) {
        return (x << k) | (x >> (64 - k));
    }

    std::array<uint64_t, 4> s;

    uint64_t next() {
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

    // random choice from [0, upper]
    uint64_t next(uint64_t upper) {
        if (!(upper & (upper + 1))) {
            // b = 00..0011..11
            return next() & upper;
        }
        int lg = 63 - __builtin_clzll(upper);
        uint64_t mask = (lg == 63) ? ~0ULL : (1ULL << (lg + 1)) - 1;
        while (true) {
            uint64_t r = next() & mask;
            if (r <= upper) return r;
        }
    }

  public:
    Random(uint64_t seed = 0) {
        // Use splitmix64
        // Reference: http://xoshiro.di.unimi.it/splitmix64.c
        for (int i = 0; i < 4; i++) {
            uint64_t z = (seed += 0x9e3779b97f4a7c15);
            z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
            z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
            s[i] = z ^ (z >> 31);
        }
    }

    // random choice from [lower, upper]
    template <class T> T uniform(T lower, T upper) {
        assert(lower <= upper);
        return T(lower + next(uint64_t(upper - lower)));
    }

    bool uniform_bool() { return uniform(0, 1) == 1; }

    double uniform01() {
        uint64_t v = next(1ULL << 63);
        return double(v) / (1ULL << 63);
    }

    template <class T> std::pair<T, T> uniform_pair(T lower, T upper) {
        assert(upper - lower >= 1);
        T a, b;
        do {
            a = uniform(lower, upper);
            b = uniform(lower, upper);
        } while (a == b);
        if (a > b) std::swap(a, b);
        return {a, b};
    }

    // generate random lower string that length = n
    std::string lower_string(size_t n) {
        std::string res = "";
        for (size_t i = 0; i < n; i++) {
            res += uniform('a', 'z');
        }
        return res;
    }

    // random shuffle
    template <class Iter> void shuffle(Iter first, Iter last) {
        if (first == last) return;
        // Reference and edit:
        // cpprefjp - C++
        // (https://cpprefjp.github.io/reference/algorithm/shuffle.html)
        int len = 1;
        for (auto it = first + 1; it != last; it++) {
            len++;
            int j = uniform(0, len - 1);
            if (j != len - 1) iter_swap(it, first + j);
        }
    }

    // generate random permutation that length = n
    template <class T> std::vector<T> perm(size_t n) {
        std::vector<T> idx(n);
        std::iota(idx.begin(), idx.end(), T(0));
        shuffle(idx.begin(), idx.end());
        return idx;
    }

    template <class T> std::vector<T> choice(size_t n, T lower, T upper) {
        assert(n <= upper - lower + 1);
        std::set<T> res;
        while (res.size() < n) res.insert(uniform(lower, upper));
        return {res.begin(), res.end()};
    }
};
Random& global_gen() {
    static Random gen;
    return gen;
}
Random get_random_gen() {
    return Random(chrono::steady_clock::now().time_since_epoch().count());
}
Random& global_runtime_gen() {
    static Random gen = get_random_gen();
    return gen;
}

int main() {

    int n;
    sc.read(n);
    //n = 100000;
    V<int> a(N);
    for (int i = 0; i < n; i++) {
        sc.read(a[i]);
        //a[i] = i;
    }

    VV<int> le(BN + 1, V<int>(N + 1, INF));
    VV<int> ri(BN + 1, V<int>(N + 1, INF));

    V<int> alli(N);
    iota(alli.begin(), alli.end(), 0);
    sort(alli.begin(), alli.end(), [&](int l, int r) {
        return a[l] < a[r];
    });

    VV<int> idx(BN, V<int>(BS));
    for (int i = 0; i < BN; i++) {
        iota(idx[i].begin(), idx[i].end(), i * BS);
        sort(idx[i].begin(), idx[i].end(), [&](int l, int r) {
            return a[l] < a[r];
        });
    }

    for (int ph = 1; ph <= BN; ph++) {
        ri[ph] = ri[ph - 1];
        int r = ph * BS;

        int inside = INF;
        for (int i = r - BS; i < r; i++) {
            for (int j = i + 1; j < r; j++) {
                inside = min(inside, abs(a[i] - a[j]));
            }
        }
        ri[ph][(ph - 1) * BS] = min(ri[ph][(ph - 1) * BS], inside);

        int pos = 0;

        for (int i: alli) {
            if ((ph - 1) * BS <= i) continue;
            while (pos < BS && a[idx[ph - 1][pos]] <= a[i]) pos++;
            int z = INF;
            if (pos) z = min(z, abs(a[i] - a[idx[ph - 1][pos - 1]]));
            if (pos < BS) z = min(z, abs(a[i] - a[idx[ph - 1][pos]]));

            ri[ph][i] = min(ri[ph][i], z);
        }
        for (int l = r - 2; l >= 0; l--) {
            ri[ph][l] = min(ri[ph][l], ri[ph][l + 1]);
        }
/*        set<int> st;
        int now = INF;
        for (int l = r - 1; l >= 0; l--) {
            now = min(now, dist(st, a[l]));
            if (l >= (ph - 1) * BS) st.insert(a[l]);
            ri[ph][l] = min(ri[ph][l], now);
        }*/
    }

    for (int ph = BN - 1; ph >= 0; ph--) {
        le[ph] = le[ph + 1];
        int l = ph * BS;

        int inside = INF;
        for (int i = l; i < l + BS; i++) {
            for (int j = i + 1; j < l + BS; j++) {
                inside = min(inside, abs(a[i] - a[j]));
            }
        }
        le[ph][l + BS] = min(le[ph][l + BS], inside);

        int pos = 0;
        for (int i : alli) {
            if (i < (ph + 1) * BS) continue;
            while (pos < BS && a[idx[ph][pos]] <= a[i]) pos++;
            int z = INF;
            if (pos) z = min(z, abs(a[i] - a[idx[ph][pos - 1]]));
            if (pos < BS) z = min(z, abs(a[i] - a[idx[ph][pos]]));

            le[ph][i + 1] = min(le[ph][i + 1], z);
        }
        for (int r = l + 2; r <= N; r++) {
            le[ph][r] = min(le[ph][r], le[ph][r - 1]);
        }

/*        set<int> st;
        int now = INF;
        for (int r = l + 1; r <= N; r++) {
            now = min(now, dist(st, a[r - 1]));
            if (r - 1 < (i + 1) * BS) st.insert(a[r - 1]);
            le[i][r] = min(le[i][r], now);
        }*/
    }

    int q;
    sc.read(q);
    //q = 300000;
    V<int> wow(2 * BS);
    for (int ph = 0; ph < q; ph++) {
        int l, r;
        sc.read(l, r); l--;
        //tie(l, r) = global_gen().uniform_pair(0, n);

        int lb = l / BS;
        int rb = r / BS;

        int ans = INF;
        if (lb != rb) {
            if (lb + 1 < rb) {
                ans = min(ans, ri[rb][l]);
                ans = min(ans, le[lb + 1][r]);
            }
            merge(idx[lb].begin(), idx[lb].end(), idx[rb].begin(), idx[rb].end(), wow.begin(), [&](int x, int y) {
                return a[x] < a[y];
            });
            int pre = -INF;
            for (int i : wow) {
                if (l <= i && i < r) {
                    ans = min(ans, a[i] - pre);
                    pre = a[i];
                }
            }
        } else {
            int pre = -INF;
            for (int i : idx[lb]) {
                if (l <= i && i < r) {
                    ans = min(ans, a[i] - pre);
                    pre = a[i];
                }
            }
        }
        pr.writeln(ans);
    }
    return 0;
}