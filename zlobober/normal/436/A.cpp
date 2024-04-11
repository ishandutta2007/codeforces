#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 2050;

int T[N], H[N], M[N];
bool used[N];

int main()
{
    int n, init;
    scanf("%d %d", &n, &init);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &T[i], &H[i], &M[i]);
    int ans = -1;
    for (int q = 0; q < 2; q++)
    {
        int t = q;
        int x = init;
        memset(used, 0, sizeof(used));
        int cnt = 0;
        while (true)
        {
            int eat = -1;
            int mxr = -1;
            for (int i = 0; i < n; i++)
            {
                if (!used[i] && T[i] == t && H[i] <= x)
                {
                    if (mxr < M[i])
                        mxr = M[i], eat = i;
                }
            }
            if (eat == -1)
                break;
            else
                used[eat] = true, t ^= 1, x += mxr, cnt++;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
}