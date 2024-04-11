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

const int mx = 1e5 + 10;
const int MOD = 1e9 + 7;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x -= 1;
        if (a.empty() || a.back() != x)
            a.push_back(x);
    }
    vector<int> ada(n, 0);
    int ans = 0;
    vector<int> ve;
    for (int i : a)
    {
        if (ada[i])
        {
            ans += 1;
            for (int j = 0; j < sz(ve) - 1; j++)
            {
                ada[ve[j]] = 0;
            }
            int las = ve.back();
            ve.clear();
            ve.push_back(las);
            ada[i] = 1;
            ve.push_back(i);
        }
        else
        {
            ada[i] = 1;
            ve.push_back(i);
        }
    }
    cout << sz(a) - ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}