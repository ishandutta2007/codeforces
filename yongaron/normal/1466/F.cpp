#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int n, m;

int f[1234567];
int rrank[1234567];
bool cycle[1234567];

int getfa(int a)
{
    if (a != f[a])
        f[a] = getfa(f[a]);
    return f[a];
}

void connect(int a, int b)
{
    int fa = getfa(a), fb = getfa(b);
    if (fa == fb)
    {
        cycle[fa] = true;
        return;
    }
    if (rrank[fa] == rrank[fb])
        rrank[fb]++;
    if (rrank[fa] > rrank[fb])
        swap(fa, fb);
    cycle[fb] = cycle[fb] | cycle[fa];
    f[fa] = fb;
}

bool connected(int a, int b)
{
    int fa = getfa(a), fb = getfa(b);
    return (fa == fb) || (cycle[fa] && cycle[fb]);
}

vector<int> v;

ll ans = 1;
ll mod = 1e9 + 7;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
        f[i] = i;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int a, b;
        if (k == 1)
        {
            cin >> a;
            b = a;
            if (!cycle[getfa(a)])
            {
                connect(a, b);
                v.push_back(i + 1);
                ans *= 2;
                if (ans >= mod)
                    ans -= mod;
            }
        }
        else
        {
            cin >> a >> b;
            if (!connected(a, b))
            {
                connect(a, b);
                v.push_back(i + 1);
                ans *= 2;
                if (ans >= mod)
                    ans -= mod;
            }
        }
        
    }
    cout << ans << " " << v.size() << endl;
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}