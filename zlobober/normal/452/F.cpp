#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

/*const int P1 = 42424243, P2 = 1000000009;
const int A1 = 4243, A2 = 424243;
struct hsh
{
    int x, y;
    hsh(){}
    inline hsh(int _x, int _y)
    {
        x = _x, y = _y;
    }
    inline friend hsh operator +(const hsh& a, const hsh& b)
    {
        int x = a.x + b.x;
        if (x >= P1)
            x -= P1;
        int y = a.y + b.y;
        if (y >= P2)
            y -= P2;
        return hsh(x, y);
    }
    inline friend hsh operator -(const hsh& a, const hsh& b)
    {
        int x = a.x - b.x + P1;
        int y = a.y - b.y + P2;
        if (x < 0)
            x += P1;
        if (y < 0)
            y += P2;
        return hsh(x, y);
    }
    inline friend hsh operator *(const hsh& a, const hsh& b)
    {
        return hsh(a.x * 1LL * b.x % P1, a.y * 1LL * b.y % P2);
    }
    inline friend bool operator ==(const hsh& a, const hsh& b)
    {
        return a.x == b.x && a.y == b.y;
    }
};*/

typedef int hsh;

const int N = 1 << 19;

const int A1 = 424243;
const int MOD = 1000 * 1000 * 1000 + 21;

hsh AA[N];
int A[N];

hsh T1[2 * N], T2[2 * N];

pair<int, hsh> get(hsh* T, int l, int r, int L = 1, int R = N, int v = 1)
{
    if (r < L || l > R)
        return make_pair(0, 0);
    if (l <= L && R <= r)
        return make_pair(R - L + 1, T[v]);
    else
    {
        pair<int, hsh> a = get(T, l, r, L, (L + R) / 2, 2 * v);
        pair<int, hsh> b = get(T, l, r, (L + R) / 2 + 1, R, 2 * v + 1);
        return make_pair(a.first + b.first, (a.second * 1LL * AA[b.first] + b.second) % MOD);
    }
}

void set(hsh* T, int v, int x)
{
    v += N - 1;
    T[v] = x;
    int len = 1;
    while (v >>= 1)
    {
        T[v] = (T[2 * v] * 1LL * AA[len] + T[2 * v + 1]) % MOD;
        len <<= 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]), A[i];
    AA[0] = 1;
    for (int i = 1; i <= n; i++)
        AA[i] = (AA[i - 1] * 1LL * A1) % MOD;
    for (int i = 1; i <= n; i++)
        set(T1, i, '0'), set(T2, i, '0');
    for (int i = 0; i < n; i++)
    {
        int q = A[i];
        int len = min(q, n - q + 1);
        int l1 = q - len + 1, r1 = q + len - 1;
        int l2 = n - q + 1 - len + 1, r2 = n - q + 1 + len - 1;
        pair<int, hsh> h1 = get(T1, l1, r1);
        pair<int, hsh> h2 = get(T2, l2, r2);
        assert(h1.first == h2.first);
        if (h1 != h2)
        {
            fprintf(stderr, "pos = %d, val = %d, h1 = %d, h2 = %d\n", i, q, h1.second, h2.second);
            puts("YES");
            return 0;
        }
        set(T1, q, '1');
        set(T2, n - q + 1, '1');
    }
    puts("NO");
}