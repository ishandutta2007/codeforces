#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long pr[62] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                        83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
                        173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
                        269, 271, 277, 281, 283, 293};
const long long Q = (long long)1e9 + 7;

long long gcd(long long x, long long y){return (y == 0 ? x : gcd(y, x % y));}

long long divide_mod(long long x, long long y)
{
    x %= Q; y %= Q;
    long long k = gcd(x, y);
    x /= k; y /= k;
    long long z1 = 0, z2 = 1, w1 = 1, w2 = 0, t1 = Q, t2 = y;
    while(t2)
    {
        long long k = t1 / t2;
        long long z3 = z1 - z2 * k;
        long long w3 = w1 - w2 * k;
        long long t3 = t1 - t2 * k;
        z1 = z2; z2 = z3; w1 = w2; w2 = w3; t1 = t2; t2 = t3;
    }
    if(z1 < 0) z1 += Q;
    return (x * z1) % Q;
}

long long pow_mod(long long x, long long y)
{
    x %= Q;
    long long ans = 1;
    for(long long i = 29; ~i; --i)
    {
        ans = (ans * ans) % Q;
        if(y & (1ll << i))
            ans = (ans * x) % Q;
    }
    return ans;
}

class fenwick_mul
{
    long long *arr;
    long long N;

public:
    fenwick_mul(long long);
    ~fenwick_mul() {delete []arr;}
    void add(long long, long long);
    void update(long long, long long);
    long long mul(long long);
};

fenwick_mul::fenwick_mul(long long _N) : N(_N), arr(new long long[_N + 1]{}) {}

void fenwick_mul::add(long long n, long long x)
{
    arr[n] = x;
    long long id = n - 1; long long base = n & id;
    while(base < id)
    {
        arr[n] = (arr[n] * arr[id]) % Q;
        id &= id - 1;
    }
}

void fenwick_mul::update(long long n, long long x)
{
    ++n;
    while(n <= N)
    {
        arr[n] = (arr[n] * x) % Q;
        n += n & -n;
    }
    return;
}

long long fenwick_mul::mul(long long n)
{
    long long ans = 1;
    while(n)
    {
        ans = (ans * arr[n]) % Q;
        n &= n - 1;
    }
    return ans;
}

class rfenwick
{
    fenwick_mul con, lin;

public:
    rfenwick(long long, long long*);
    void update(long long, long long, long long);
    long long mul(long long, long long);
};

rfenwick::rfenwick(long long _N, long long *_arr)
    : con(_N), lin(_N)
{
    for(long long i = 1; i <= _N; ++i)
        con.add(i, _arr[i - 1]);
    for(long long i = 1; i <= _N; ++i)
        lin.add(i, 1);
}

void rfenwick::update(long long s, long long t, long long x)
{
    long long negX = divide_mod(1, x);
    con.update(s, pow_mod(negX, s));
    con.update(t, pow_mod(x, t));
    lin.update(s, x);
    lin.update(t, negX);
}

long long rfenwick::mul(long long s, long long t)
{
    return divide_mod(con.mul(t) * pow_mod(lin.mul(t), t),
                      (con.mul(s) * pow_mod(lin.mul(s), s)));
}

class index_prime
{
    vector<long long> prime;
    vector<long long> neg_prime;
    vector<long long> frac;
    vector<long long> lazy;
    long long N, L;

    void __update(const long long&, const long long&, const long long&, long long, long long, long long);
    void __mul(const long long&, const long long&, long long, long long, long long);

public:
    index_prime(const long long&, long long*);
    void update(long long, long long, long long);
    long long mul(long long, long long);
};

index_prime::index_prime(const long long &_N, long long *_arr)
    : N(_N), L(1), prime(62), neg_prime(62)
{
    for(long long i = 0; i < 62; ++i)
    {
        prime[i] = pr[i];
        neg_prime[i] = divide_mod(prime[i] - 1, prime[i]);
    }

    while(L < N) L <<= 1;
    frac.resize(L << 1, 0);
    lazy.resize(L << 1, 0);

    for(long long i = 0; i < N; ++i)
        for(long long j = 0; j < 62; ++j)
            if(_arr[i] % prime[j] == 0)
                frac[i | L] |= (1ll << j);

    for(long long i = L - 1; i; --i)
        frac[i] = frac[i << 1] | frac[i << 1 | 1];
}

void index_prime::update(long long s, long long t, long long x)
{
    long long fracX = 0;
    for(long long i = 0; i < 62; ++i)
        if(x % prime[i] == 0)
            fracX |= (1ll << i);
    __update(s, t, fracX, 0, L, 1);
    return;
}

void index_prime::__update(const long long &l, const long long &r, const long long &val,
                           long long left, long long right, long long node)
{
    if(right <= l || left >= r) return;
    if(left >= l && right <= r)
    {
        lazy[node] |= val;
        return;
    }

    frac[node] |= val;

    long long mid = (left + right) / 2;
    __update(l, r, val, left, mid, node << 1);
    __update(l, r, val, mid, right, node << 1 | 1);
    return;
}

long long index_prime::mul(long long s, long long t)
{
    frac[0] = 0;
    __mul(s, t, 0, L, 1);
    long long ans = 1;
    for(long long i = 0; i < 62; ++i)
        if(frac[0] & (1ll << i))
            ans = (ans * neg_prime[i]) % Q;
    return ans;
}

void index_prime::__mul(const long long &l, const long long &r,
                        long long left, long long right, long long node)
{
    if(right <= l || left >= r) return;

    if(node < L)
    {
        lazy[node << 1] |= lazy[node];
        lazy[node << 1 | 1] |= lazy[node];
    }
    frac[node] |= lazy[node];
    lazy[node] = 0;

    if(left >= l && right <= r)
    {
        frac[0] |= frac[node];
        return;
    }

    long long mid = (left + right) / 2;
    __mul(l, r, left, mid, node << 1);
    __mul(l, r, mid, right, node << 1 | 1);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q; cin >> n >> q;
    long long arr[n]; for(long long &i : arr) cin >> i;

    rfenwick rf(n, arr);
    index_prime id(n, arr);

    for(long long i = 0; i < q; ++i)
    {
        string s; cin >> s;

        if(s == "TOTIENT")
        {
            long long x, y; cin >> x >> y;
            cout << (rf.mul(x - 1, y) * id.mul(x - 1, y)) % Q << endl;
        }

        else
        {
            long long x, y, z; cin >> x >> y >> z;
            rf.update(x - 1, y, z);
            id.update(x - 1, y, z);
        }
    }

    return 0;
}