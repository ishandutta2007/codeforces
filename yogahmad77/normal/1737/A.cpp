#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a, b) memset(a, b, sizeof a);
#define ALL(x) x.begin(), x.end()

template <typename T>
void cetak(T t)
{
    cout << t << ')' << endl;
}
template <typename T, typename... V>
void cetak(T t, V... v)
{
    cout << t;
    if (sizeof...(v))
        cout << ", ";
    cetak(v...);
}

#define debug(x...)               \
    cout << '(' << #x << ") = ("; \
    cetak(x)
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);

const int mx = 2e5 + 10;

void solve(int tc)
{
    int n, k;
    string ss;
    vector<int> cnt(25, 0);
    cin >> n >> k >> ss;
    for (auto i : ss)
    {
        int x = i - 'a';
        cnt[x] += 1;
    }
    string ans = "";
    for (int i = 0; i < k; i++)
    {
        int idx = 0;
        int sisa = n / k;
        while (cnt[idx] > 0 && sisa > 0)
        {
            cnt[idx] -= 1;
            sisa -= 1;
            idx += 1;
        }
        ans += 'a' + idx;
    }
    cout << ans << '\n';
}

int main()
{
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}