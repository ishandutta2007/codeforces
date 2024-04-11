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

void solve(int tc)
{
    int n, k, m;
    cin >> n >> k >> m;
    int x = (k - 1) / 2;
    vector<int> b(m);
    for (int &i : b)
        cin >> i;
    int tadi = 0;
    vector<int> apa;
    if ((n - m) % (k - 1) != 0)
    {
        cout << "NO\n";
        return;
    }
    for (int i : b)
    {
        apa.push_back(i - tadi - 1);
        tadi = i;
    }
    apa.push_back(n + 1 - tadi - 1);
    int B = 0;
    for (int i : apa)
        B += i;
    int ada = 0, A = 0;
    for (int i : apa)
    {
        A += i;
        B -= i;
        if (A >= x && B >= x)
            ada = 1;
    }
    if (ada)
        cout << "YES\n";
    else
        cout << "NO\n ";
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