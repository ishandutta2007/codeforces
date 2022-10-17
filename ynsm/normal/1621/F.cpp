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

int n, a, b, c;
char s[N];
ll f(bool rev)
{
    ll res = 0, cur = 0;
    int ex_zeros = 0, ex_solo_zero = 0, solo_zero = 0, ones = 0;
    vector<int> zeros;
    for (int i = 0, j = 0; i < n; i = j)
    {
        while (j < n && s[i] == s[j])
            j++;
        if (s[i] == '0')
            if (i == 0 || j == n)
                ex_zeros += j - i - 1, ex_solo_zero++;
            else
                zeros.pb({j - i - 1});
        else
            ones += j - i - 1;
    }
    sort(zeros.begin(), zeros.end());
    int i = 0;
    while (true)
    {
        while (i < zeros.size() && zeros[i] == 0)
        {
            solo_zero++;
            i++;
        }

        if (rev)
            if (ones > 0)
                ones--, cur += b;
            else
                break;
        res = max(res, cur);



        if (i < zeros.size())
            res = max(res, cur + a);
        else if (ex_zeros > 0)
            res = max(res, cur + a);

        if (solo_zero > 0 && ones == 0)
            solo_zero--, ones++, cur -= c;
        else if (i < zeros.size())
            zeros[i]--, cur += a;
        else if (ex_zeros > 0)
            ex_zeros--, cur += a;
        else if (solo_zero > 0)
            solo_zero--, ones++, cur -= c;
        else if (ex_solo_zero > 0)
            ex_solo_zero--, cur -= c;
        else
            break;

        res = max(res, cur);

        if (!rev)
            if (ones > 0)
                ones--, cur += b;
            else
                break;
        res = max(res, cur);
    }
    return res;
}
void solve()
{
    scanf("%d%d%d%d", &n, &a, &b, &c);
    scanf("%s", s);
    printf("%lld\n", max(f(0), f(1)));
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}