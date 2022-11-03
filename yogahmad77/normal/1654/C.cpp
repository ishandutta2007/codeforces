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
    long long sum = 0;
    map<long long, int> ada;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        sum += x;
        ada[x] += 1;
    }
    vector<long long> ve;
    if (ada[sum] > 0)
    {
        ada[sum] -= 1;
    }
    else
    {
        ve.push_back(sum);
    }
    for (int i = 1; i < n; i++)
    {
        long long x = ve.back();
        ve.pop_back();
        long long a = x / 2;
        long long b = x - a;
        if (ada[a] > 0)
        {
            ada[a] -= 1;
        }
        else
        {
            ve.push_back(a);
        }
        if (ada[b] > 0)
        {
            ada[b] -= 1;
        }
        else
            ve.push_back(b);
    }
    if (sz(ve) > 0)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}