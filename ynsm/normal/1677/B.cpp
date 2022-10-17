#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2000100;

int n, m;
char s[N];

int p[N], pp[N];
bool was[N];

void solve()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s);

    int last = -1;
    for (int i = 0; i < n * m; i++)
        p[i] = pp[i] = 0;
    for (int i = 0; i < n * m; i++)
    {
        if (s[i] == '0')
            continue;
        if (last == -1)
        {
            p[i]++;
        }
        else
        {
            if (i - last < m)
            {
                pp[last + m]++;
                pp[i + m]--;
            }
            else
            {
                p[i]++;
            }
        }
        last = i;
    }
    for (int i = 1; i < n * m; i++)
        pp[i] += pp[i - 1];
    for (int i = m; i < n * m; i++)
        pp[i] += pp[i - m];
    for (int i = 1; i < n * m; i++)
        p[i] += p[i - 1];

    for (int i = 0; i < m; i++)
        was[i] = 0;
    int col = 0;
    for (int i = 0; i < n * m; i++)
    {
        int row = 0;
        if (s[i] == '1')
        {
            if (!was[i % m])
                col++;
            was[i % m] = 1;
        }
        row = p[i] + pp[i];
        printf("%d ", row + col);
    }
    printf("\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}