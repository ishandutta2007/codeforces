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

void solve()
{
    vector<ll> a(3);
    for (ll i = 0; i < 3; i++)
        cin >> a[i];
    if (a[0] == a[1] and a[1] == a[2])
    {
        if (a[0] == 0)
        {
            cout << 1 << " " << 1 << " " << 1 << "\n";
        }
        else
            cout << "NO\n";
        return;
    }
    for (ll i = 0; i < 3; i++)
    {
        if (a[0] >= a[1] and a[1] >= a[2])
        {
            vector<ll> b = {a[0], 2 * a[0] + a[1] + a[2], 2 * a[0] + a[2]};
            for (ll j = 0; j < 3; j++)
            {
                cout << b[(j + 3 - i) % 3] << " ";
            }
            cout << "\n";
            return;
        }
        if (a[0] < a[1] and a[1] > a[2] and a[0] > a[2])
        {
            vector<ll> b = {a[0] + a[1], a[1], a[0] + a[1] + a[2]};
            for (ll j = 0; j < 3; j++)
            {
                cout << b[(j + 3 - i) % 3] << " ";
            }
            cout << "\n";
            return;
        }
        a = {a[1], a[2], a[0]};
    }
}

int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}