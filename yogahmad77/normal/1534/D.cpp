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

int n;

set<pair<int, int>> edge;

vector<int> tanya(int x)
{
    cout << "? " << x + 1 << endl;
    vector<int> ret;
    for (int i = 0; i < n; i++)
    {
        int xx;
        cin >> xx;
        ret.push_back(xx);
        if (xx == 1)
        {
            edge.insert({min(x, i), max(x, i)});
        }
    }

    return ret;
}

void solve(int tc)
{
    cin >> n;
    int root = 0;
    auto lev = tanya(root);
    int genap = 0, ganjil = 0;
    for (int i = 1; i < n; i++)
    {
        if (lev[i] & 1)
            ganjil += 1;
        else
            genap += 1;
    }

    vector<int> ve;
    for (int i = 1; i < n; i++)
    {
        if (ganjil < genap)
        {
            if (lev[i] & 1)
                ve.push_back(i);
        }
        else
        {
            if (lev[i] & 1)
                continue;
            else
                ve.push_back(i);
        }
    }

    for (int i : ve)
    {
        tanya(i);
    }

    cout << "!\n";
    for (auto i : edge)
    {
        cout << i.f + 1 << ' ' << i.s + 1 << endl;
    }
}

int main()
{
    int t = 1;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}