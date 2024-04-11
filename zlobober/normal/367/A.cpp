#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100500;

char buf[N];
int cnt[N][3];

int main()
{
    gets(buf);
    int n = strlen(buf);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cnt[i + 1][j] = cnt[i][j];
        cnt[i + 1][buf[i] - 'x']++;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        bool good = false;
        if (r - l <= 1)
            good = true;
        else
        {
            int c[3];
            for (int j = 0; j < 3; j++)
                c[j] = cnt[r][j] - cnt[l - 1][j];
            fprintf(stderr, "%d %d %d\n", c[0], c[1], c[2]);
            if (*max_element(c, c + 3) - *min_element(c, c + 3) <= 1)
                good = true;
            else
                good = false;
        }
        if (good)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}