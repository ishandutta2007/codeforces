#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n;
char a[3][N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%s", a[0]);
        scanf("%s", a[1]);
        scanf("%s", a[2]);
        int i = 0, j = 0, q = 0;
        while (true)
        {
            if (i == 2 * n || j == 2 * n || q == 2 * n)
            {
                int cnt = 0;
                if (i == 2 * n)
                    cnt++;
                if (j == 2 * n)
                    cnt++;
                if (q == 2 * n)
                    cnt++;
                if (cnt > 1)
                    break;
                int w = 0, p = -1;
                if (i < 2 * n && w < i)
                    w = i, p = 0;
                if (j < 2 * n && w < j)
                    w = j, p = 1;
                if (q < 2 * n && w < q)
                    w = q, p = 2;
                while (p != -1 && w < 2 * n)
                {
                    printf("%c", a[p][w]);
                    w++;
                }
                break;
            }
            int cnt[] = {0, 0};
            cnt[a[0][i] - '0']++;
            cnt[a[1][j] - '0']++;
            cnt[a[2][q] - '0']++;
            char c;
            if (cnt[0] < cnt[1])
                c = '1';
            else
                c = '0';
            printf("%c", c);
            if (a[0][i] == c)
                i++;
            if (a[1][j] == c)
                j++;
            if (a[2][q] == c)
                q++;
        }
        printf("\n");
    }
}