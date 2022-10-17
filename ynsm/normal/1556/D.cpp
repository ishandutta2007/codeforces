#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 10010, LOG = 30;

int n, k, a[N], b[N];

pii f(int v, int u)
{
    int x, y;
    cout << "and " << v << " " << u << endl;
    cin >> x;
    cout << "or " << v << " " << u << endl;
    cin >> y;
    // x = (b[v] & b[u]);
    // y = (b[v] | b[u]);
    return {x, y};
}
int main()
{
    cin >> n >> k;
    // for (int i = 1; i <= n; i++)
    //     b[i] = rand() % (int)1e9;
    {
        pii x, y, z;
        x = f(1, 2);
        y = f(1, 3);
        z = f(2, 3);
        for (int i = 0; i < LOG; i++)
        {
            for (int j = 0; j < (1 << 3); j++)
            {
                bool ok = 1;
                int q = ((j >> 0) & 1);
                int w = ((j >> 1) & 1);
                int e = ((j >> 2) & 1);
                ok &= (min(q, w) == ((x.f >> i) & 1));
                ok &= (max(q, w) == ((x.s >> i) & 1));
                ok &= (min(q, e) == ((y.f >> i) & 1));
                ok &= (max(q, e) == ((y.s >> i) & 1));
                ok &= (min(w, e) == ((z.f >> i) & 1));
                ok &= (max(w, e) == ((z.s >> i) & 1));
                if (ok)
                {
                    a[1] |= (q << i);
                    a[2] |= (w << i);
                    a[3] |= (e << i);
                    break;
                }
            }
        }
    }

    for (int i = 4; i <= n; i++)
    {
        pii x = f(1, i);
        // cerr << x.f << " " << x.s << endl;
        a[i] = x.f + (x.s ^ a[1]);
    }
    // for (int i = 1; i <= n; i++)
    //     cerr << a[i] << " ";
    // cerr << endl;
    // for (int i = 1; i <= n; i++)
    //     cerr << b[i] << " ";
    // cerr << endl;
    sort(a + 1, a + 1 + n);
    cout << "finish " << a[k] << endl;
    return 0;
}