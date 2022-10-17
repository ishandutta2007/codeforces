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

char s[N];
int n, cnt[N];
void solve()
{
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;

    for (int i = 0; i < n; i++)
    {
        bool good = 1;
        good &= (cnt[s[i] - 'a'] <= 1);
        if (good)
        {
            for (int j = i; j < n; j++)
                printf("%c", s[j]);
            printf("\n");
            return;
        }
        cnt[s[i] - 'a']--;
    }
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}