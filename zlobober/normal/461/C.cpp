#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1 << 17;

int T[2 * N];
int get(int l, int r, int L = 1, int R = N, int v = 1)
{
    if (r < L || l > R)
        return 0;
    if (l <= L && R <= r)
        return T[v];
    return get(l, r, L, (L + R) / 2, 2 * v) + get(l, r, (L + R) / 2 + 1, R, 2 * v + 1);
}

void add(int x, int v)
{
    x += N - 1;
    T[x] += v;
    while (x /= 2)
        T[x] = T[2 * x] + T[2 * x + 1];
}

int sign(int x)
{
    return (x > 0) - (x < 0);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        add(i, 1);
    int l = 1, r = n, s = 1;
    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x;
            scanf("%d", &x);
            int len = abs(r - l) + 1;
            if (x * 2 <= len)
            {
                int u = l;
                int v = l + (2 * x - 1) * s;
                do
                {
                    add(v, get(u, u));
                    u += s, v -= s;
                } while (u - s != v);
                l = u;
            }
            else
            {
                int y = len - x;
                int u = r;
                int v = r - (2 * y - 1) * s;
                do
                {
                    add(v, get(u, u));
                    u -= s, v += s;
                } while (u + s != v);
                r = l, l = u, s = sign(r - l);
            }
        }
        else
        {
            int a, b;
            scanf("%d %d", &a, &b);
            --b;
            int u = l + s * a, v = l + s * b;
            printf("%d\n", get(min(u, v), max(u, v))); 
        }
    }

}