#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define mp make_pair

typedef long long llong;

#ifdef LOCAL
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

const int N = 1 << 17;
pair<int, int> B[N];
map<int, int> M;

int A[N];

#define eprintf(...) //fprintf(stderr, __VA_ARGS__)

vector<int> T[2 * N];

int T2[2 * N];

int get2(int l, int r, int L, int R, int v)
{
    if (r < L || l > R)
        return 0;
    if (l <= L && R <= r)
        return T2[v];
    return get2(l, r, L, (L + R) / 2, 2 * v) + get2(l, r, (L + R) / 2 + 1, R, 2 * v + 1);
}

void add2(int x, int v)
{
    for (x += N - 1; x; x >>= 1)
        T2[x] += v;
}

int get(int l, int r, int L, int R, int v, int y, bool gr)
{
    if (r < L || l > R)
        return 0;
    if (l <= L && R <= r)
    {
        if (gr)
            return T[v].end() - upper_bound(T[v].begin(), T[v].end(), y);
        else
            return lower_bound(T[v].begin(), T[v].end(), y) - T[v].begin();
    }
    return get(l, r, L, (L + R) / 2, 2 * v, y, gr) + get(l, r, (L + R) / 2 + 1, R, 2 * v + 1, y, gr);
}

int main()
{
    int n;
    llong k;
    scanf("%d "LLD, &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]), M[A[i]];
    int pt = 1;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
        it->second = pt++;
    for (int i = 1; i <= n; i++)
        A[i] = M[A[i]];
    for (int i = 1; i <= n; i++)
        B[i] = mp(A[i], i);
    sort(B + 1, B + n + 1);
    llong cur = 0;
    for (int i = 1; i <= n; i++)
        add2(B[i].second, 1), cur += get2(B[i].second + 1, n, 1, N, 1);
    eprintf("initially %lld inverces\n", cur);
    for (int i = 1; i <= n; i++)
        T[i + N - 1].push_back(A[i]);
    for (int i = N - 1; i > 0; i--)
        T[i].resize(T[2 * i].size() + T[2 * i + 1].size()),
        merge(T[2 * i].begin(), T[2 * i].end(), T[2 * i + 1].begin(), T[2 * i + 1].end(), T[i].begin());
    int l = 1, r = 2;
    llong ans = 0;
    while (l < n)
    {
        while (cur > k || r <= l)
        {
            if (r == n)
                goto end;
            eprintf("out %d\n", r);
            int x1 = get(r + 1, n, 1, N, 1, A[r], 0);
            int x2 = get(1, l, 1, N, 1, A[r], 1);
            eprintf("r+1..n %d\n1..l %d\n", x1, x2);
            cur -= x1 + x2;
            eprintf("l = %d r = %d cur = %lld\n", l, r, cur);
            r++;
        }
        ans += n - r + 1;
        eprintf("in %d\n", l + 1);
        int x1 = get(r, n, 1, N, 1, A[l + 1], 0);
        int x2 = get(1, l, 1, N, 1, A[l + 1], 1);
        cur += x1 + x2;
        eprintf("r..n %d\n1..l+1 %d\n", x1, x2);
        eprintf("l = %d r = %d cur = %lld\n", l, r, cur);
        eprintf("\n");
        l++;
    }
    end:;
    printf(LLD"\n", ans);

}