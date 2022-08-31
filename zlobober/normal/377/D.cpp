#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

const int N = 1 << 19;

int T[2 * N], D[2 * N];

inline void push(int x)
{
    if (x < N)
    {
        T[x] += D[x];
        D[2 * x] += D[x];
        D[2 * x + 1] += D[x];
        D[x] = 0;
    }
    else
        T[x] += D[x], D[x] = 0;
}

int get(int l, int r, int L, int R, int v)
{
    if (r < L || l > R)
        return -1;
    else if (l <= L && R <= r)
        return T[v] + D[v];
    else
    {
        push(v);
        return max(get(l, r, L, (L + R) / 2, 2 * v), get(l, r, (L + R) / 2 + 1, R, 2 * v + 1));
    }
}

#ifdef LOCAL42
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

int add(int l, int r, int L, int R, int v, int x)
{
    if (r < L || l > R)
        return T[v] + D[v];
    else if (l <= L && R <= r)
    {
        D[v] += x;
        return T[v] + D[v];
    }
    else
    {
        push(v);
        T[v] = max(
                add(l, r, L, (L + R) / 2, 2 * v, x),
                add(l, r, (L + R) / 2 + 1, R, 2 * v + 1, x)
        );
        return T[v];
    }
}

int A[N], V[N], B[N];

vector<int> E[N];

int seek(int L, int R, int v)
{
    if (v >= N)
        return v - N + 1;
    else
        return (D[2 * v] + T[2 * v] > D[2 * v + 1] + T[2 * v + 1]) ? seek(L, (L + R) / 2, 2 * v) : seek((L + R) / 2 + 1, R, 2 * v + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &A[i], &V[i], &B[i]);
        E[V[i]].push_back(i);
        E[A[i] - 1].push_back(~i);
    }
    int ans = 0;
    int ansl = -1, ansr = -1;
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < E[i].size(); j++)
        {
            if (E[i][j] >= 0)
                add(V[E[i][j]], B[E[i][j]], 1, N, 1, 1);
            else
                add(V[~E[i][j]], B[~E[i][j]], 1, N, 1, -1);
        }
        int v = get(1, N, 1, N, 1);
        if (ans < v)
        {
            ans = v;
            int r = seek(1, N, 1);
            ansl = i, ansr = r;
            eprintf("change: ansl = %d, ansr = %d, ans = %d\n", ansl, ansr, ans);
        }
    }
    assert(ans > 0);
    printf("%d\n", ans);
    eprintf("%d %d\n", ansl, ansr);
    vector<int> lst;
    for (int i = 0; i < n; i++)
        if (A[i] <= ansl && B[i] >= ansr && ansl <= V[i] && V[i] <= ansr)
            lst.push_back(i + 1);
    assert(lst.size() == ans);
    for (int i = 0; i < lst.size(); i++)
        printf("%d%c", lst[i], " \n"[i + 1 == lst.size()]);
}