#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
const int K = 30;

int n;
char s[N];
bool w22[K][K], w33[K][K][K];
bool w23[K][K], w32[K][K];
void solve()
{
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            w22[i][j] = w23[i][j] = w32[i][j] = 0;
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            for (int q = 0; q < K; q++)
                w33[i][j][q] = 0;

    scanf("%d", &n);
    bool ok = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        int k = strlen(s);
        for (int i = 0; i < k; i++)
            s[i] -= 'a';

        if (s[0] == s[k - 1])
            ok = 1;
        if (k == 2)
        {
            ok |= w22[s[1]][s[0]];
            ok |= w32[s[1]][s[0]];

            w22[s[0]][s[1]] = 1;
            w23[s[0]][s[1]] = 1;
        }
        if (k == 3)
        {
            ok |= w33[s[2]][s[1]][s[0]];
            ok |= w23[s[2]][s[1]];

            w32[s[0]][s[1]] = 1;
            w33[s[0]][s[1]][s[2]] = 1;
        }
    }
    if (ok)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}