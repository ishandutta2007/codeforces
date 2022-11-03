#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a, b) memset(a, b, sizeof a);
#define ALL(x) x.begin(), x.end()

template <typename T>
void cetak(T t)
{
    cout << t << ')' << endl;
}
template <typename T, typename... V>
void cetak(T t, V... v)
{
    cout << t;
    if (sizeof...(v))
        cout << ", ";
    cetak(v...);
}

#define debug(x...)               \
    cout << '(' << #x << ") = ("; \
    cetak(x)
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);
#define vi vector<int>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define trav(e, f) for (auto e : f)
const int mx = 1e5 + 10;
const int MOD = 1e9 + 7;

struct TwoSat
{
    int N;
    vector<vi> gr;
    vi values; // 0 = false, 1 = true

    TwoSat(int n = 0) : N(n), gr(2 * n) {}

    int add_var()
    { // (optional)
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }

    void either(int f, int j)
    {
        f = max(2 * f, -1 - 2 * f);
        j = max(2 * j, -1 - 2 * j);
        gr[f ^ 1].push_back(j);
        gr[j ^ 1].push_back(f);
    }
    void set_value(int x) { either(x, x); }

    void at_most_one(const vi &li)
    { // (optional)
        if (sz(li) <= 1)
            return;
        int cur = ~li[0];
        rep(i, 2, sz(li))
        {
            int next = add_var();
            either(cur, ~li[i]);
            either(cur, next);
            either(~li[i], next);
            cur = ~next;
        }
        either(cur, ~li[1]);
    }

    vi val, comp, z;
    int time = 0;
    int dfs(int i)
    {
        int low = val[i] = ++time, x;
        z.push_back(i);
        trav(e, gr[i]) if (!comp[e])
            low = min(low, val[e] ?: dfs(e));
        ++time;
        if (low == val[i])
            do
            {
                x = z.back();
                z.pop_back();
                comp[x] = time;
                if (values[x >> 1] == -1)
                    values[x >> 1] = !(x & 1);
            } while (x != i);
        return val[i] = low;
    }

    bool solve()
    {
        values.assign(N, -1);
        val.assign(2 * N, 0);
        comp = val;
        rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
        rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
        return 1;
    }
};

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<int> X(n - 1), Y(n - 1), Z(n - 1);
    TwoSat ye(n * 4 + 10);
    ye.set_value(~1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        X[i] = u;
        Y[i] = v;
        Z[i] = w;
        int ww = 0;
        if (w != -1)
        {
            for (int j = 0; j < 30; j++)
            {
                if (w & (1 << j))
                    ww += 1;
            }
            if (ww & 1)
            {
                ye.either(u, v);
                ye.either(~u, ~v);
            }
            else
            {
                ye.either(~u, v);
                ye.either(u, ~v);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w & 1)
        {
            ye.either(u, v);
            ye.either(~u, ~v);
        }
        else
        {
            ye.either(u, ~v);
            ye.either(~u, v);
        }
    }
    if (!ye.solve())
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n - 1; i++)
    {
        if (Z[i] != -1)
        {
            cout << X[i] << ' ' << Y[i] << ' ' << Z[i] << '\n';
            continue;
        }
        if (ye.values[X[i]] == ye.values[Y[i]])
        {
            cout << X[i] << ' ' << Y[i] << ' ' << 0 << '\n';
        }
        else
        {
            cout << X[i] << ' ' << Y[i] << ' ' << 1 << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}