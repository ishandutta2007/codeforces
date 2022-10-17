#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 260, M = 1e5;

int n, m, g[N][N], ans[N];

int a[M][N], k;

void f(int i, int j, vector<int> &v, int &s)
{
    if (g[i][j] < 0)
        v.pb(-g[i][j]);
    else
        s += g[i][j] - 1;
}
void add(vector<int> v, int sum)
{
    for (int i = 0; i < m; i++)
        a[k][i] = 0;
    for (auto x : v)
        a[k][x - 1] = 1;
    a[k][m] = sum;
    k++;
}

void solve()
{
    k = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            g[i][j] = 0;
    for (int i = 1; i <= m; i++)
    {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c);
        if (v > u)
            swap(v, u);
        v--, u--;
        if (c == -1)
            g[v][u] = -i;
        else
            g[v][u] = c;
        ans[i - 1] = c;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (g[i][j] == 0)
                continue;
            for (int q = j + 1; q < n; q++)
            {
                if (g[i][q] == 0)
                    continue;
                if (g[j][q] == 0)
                    continue;
                vector<int> vals;
                int sum = 0;
                f(i, j, vals, sum);
                f(i, q, vals, sum);
                f(j, q, vals, sum);
                add(vals, (3 - sum % 3) % 3);
            }
        }
    }
    vector<int> where(m, -1);
    // for(int i = 0; i < k; i++){
    //     for(int j = 0; j <= m; j++)
    //         cerr << a[i][j] << " ";
    //     cerr << endl;
    // }
    for (int col = 0, row = 0; col < m && row < k; ++col)
    {
        for (int i = row; i < k; ++i)
            if (a[i][col])
            {
                for (int j = 0; j <= m; j++)
                    swap(a[i][j], a[row][j]);
                break;
            }
        if (!a[row][col])
            continue;
        where[col] = row;
        for (int i = 0; i < k; ++i)
            if (i != row)
            {
                while (a[i][col])
                {
                    for (int j = 0; j <= m; j++)
                        a[i][j] = (a[i][j] + a[row][j]) % 3;
                }
            }
        ++row;
    }

    for (int i = 0; i < m; ++i)
    {
        if (ans[i] == -1)
        {
            if (where[i] == -1)
                ans[i] = 1;
            else
                ans[i] = a[where[i]][m] * a[where[i]][i] % 3 + 1;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        int sum = 0;
        for (int j = 0; j < m; ++j)
            sum += (ans[j] - 1) * a[i][j];
        if (sum % 3 != a[i][m])
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}