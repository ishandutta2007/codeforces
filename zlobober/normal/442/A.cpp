#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 105;
char buf[N][5];

char Q[] = "RGBYW";

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %s ", buf[i]);
        buf[i][0] = find(Q, Q + 5, buf[i][0]) - Q;
        buf[i][1] -= '1';
    }
    int ans = 20;
    for (int msk1 = 0; msk1 < 32; msk1++)
    {
        for (int msk2 = 0; msk2 < 32; msk2++)
        {
            bool bad = false;
            for (int i = 0; !bad && i < n; i++)
                for (int j = 0; !bad && j < i; j++)
                {
                    if (make_pair(buf[i][0], buf[i][1]) == make_pair(buf[j][0], buf[j][1]))
                        continue;
                    bool any = false;
                    for (int q = 0; q < 5; q++)
                        if ((msk1 & (1 << q)))
                            any |= (buf[i][0] == q) ^ (buf[j][0] == q);
                    for (int q = 0; q < 5; q++)
                        if ((msk2 & (1 << q)))
                            any |= (buf[i][1] == q) ^ (buf[j][1] == q);
                    if (!any)
                    {
                        bad = true;
                        break;
                    }
                }
            if (bad)
                continue;
            ans = min(ans, __builtin_popcount(msk1) + __builtin_popcount(msk2));
        }
    }
    printf("%d\n", ans);
}