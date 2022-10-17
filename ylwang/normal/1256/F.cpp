#include <cstdio>

typedef long long ll;
ll read()
{
    ll ret = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret;
}
const int MAXN = 200005;

int Q, N, cnt[26], ans1, ans2;
char S[MAXN], T[MAXN];
int main()
{
    scanf("%d", &Q);
    while (Q--)
    {
        scanf("%d%s%s", &N, S + 1, T + 1); int i, j;
        for (i = 0; i < 26; ++i) cnt[i] = 0;
        bool flag = 0;
        for (i = 1; i <= N; ++i)
        {
            ++cnt[S[i] - 'a'];
            if (cnt[S[i] - 'a'] > 1) flag = 1;
        }
        for (i = 1; i <= N; ++i) --cnt[T[i] - 'a'];
        for (i = 0; i < 26; ++i) if (cnt[i]) { puts("NO"); break; }
        if (i < 26) continue;
        if (flag) puts("YES");
        else
        {
            ans1 = ans2 = 0;
            for (i = 0; i < 26; ++i) cnt[i] = 0;
            for (i = 1; i <= N; ++i)
            {
                for (j = S[i] - 'a' + 1; j < 26; ++j) ans1 += cnt[j];
                ++cnt[S[i] - 'a'];
            }
            for (i = 0; i < 26; ++i) cnt[i] = 0;
            for (i = 1; i <= N; ++i)
            {
                for (j = T[i] - 'a' + 1; j < 26; ++j) ans2 += cnt[j];
                ++cnt[T[i] - 'a'];
            }
            puts((ans1 - ans2) % 2 ? "NO" : "YES");
        }
    }
    return 0;
}