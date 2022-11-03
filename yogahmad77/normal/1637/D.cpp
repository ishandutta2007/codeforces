#include <bits/stdc++.h>
using namespace std;
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

const int mx = 100 + 10;
const int MOD = 1e9 + 7;

int dp[mx][mx * mx], a[mx], b[mx], total[mx];
int sudah[mx][mx * mx];
vector<tuple<int, int> > change;
int n;
int f(int now, int sum)
{
    if (now == n)
        return 0;
    int &ret = dp[now][sum];
    if (sudah[now][sum])
        return ret;
    sudah[now][sum] = 1;
    change.push_back(make_tuple(now, sum));
    int sum2 = 0;
    if (now > 0)
        sum2 = total[now - 1] - sum;
    // tetap
    ret = f(now + 1, sum + a[now]) + a[now] * sum + b[now] * sum2;
    ret = min(ret, f(now + 1, sum + b[now]) + b[now] * sum + a[now] * sum2);
    return ret;
}

void solve(int tc)
{
    for (auto x : change)
    {
        int a, b;
        tie(a, b) = x;
        sudah[a][b] = 0;
    }
    change.clear();
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        ans += a[i] * a[i] * (n - 1);
        ans += b[i] * b[i] * (n - 1);
        total[i] = a[i] + b[i];
        if (i > 0)
            total[i] += total[i - 1];
    }
    cout << f(0, 0) * 2 + ans << '\n';
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