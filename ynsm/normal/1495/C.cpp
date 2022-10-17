#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 550;

int n, m;
char s[N][N];
bool ans[N][N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", s[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = (s[i][j] == 'X');
        for (int i = 0; i < n; i += 3)
        {
            for (int j = 0; j < m; j++)
                ans[i][j] = 1;
            if (i + 3 < n)
            {
                int q = 0;
                for (int j = 0; j < m; j++)
                    if (ans[i + 1][j] || ans[i + 2][j])
                        q = j;
                ans[i + 1][q] = ans[i + 2][q] = 1;
            }
            if (i + 3 == n)
            {
                for (int j = 0; j < m; j++)
                    if (ans[i + 2][j])
                        ans[i + 1][j] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%c", (ans[i][j] ? 'X' : '.'));
            printf("\n");
        }
    }
}