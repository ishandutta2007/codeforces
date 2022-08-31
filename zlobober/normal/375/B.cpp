#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 5050;
char buf[N][N];

int len[N];
int cnt[N];

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main()
{
    int n, m;
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < n; i++)
        gets(buf[i]);
    int ans = 0;
    for (int j = m - 1; j >= 0; j--)
    {
        //eprintf("j = %d\n", j);
        for (int i = 0; i < n; i++)
        {
            if (buf[i][j] == '0')
                len[i] = 0;
            else
                len[i]++;
            //eprintf("len[%d] = %d\n", i, len[i]);
        }
        for (int i = 0; i <= m; i++)
            cnt[i] = 0;
        for (int i = 0; i < n; i++)
            cnt[len[i]]++;
        int cur = 0;
        for (int i = m + 1; i >= 0; i--)
        {
            cur += cnt[i];
            //eprintf("w = %d cur = %d\n", i, cur);
            ans = max(ans, cur * i);
        }
    }
    printf("%d\n", ans);
}