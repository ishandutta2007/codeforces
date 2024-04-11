#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int t, n, m;

ll sum = 0, x;
ll a[1234567];

bool was[1234567];

vector<int> graf[1234567];
vector<int> ind[1234567];

vector<int> toend;
vector<int> ans;

bool done[1234567];

void dfs(int v, int f)
{
    was[v] = true;
    for (int i = 0; i < graf[v].size(); i++)
    {
        if (!was[graf[v][i]])
        {
            dfs(graf[v][i], ind[v][i]);
            if (done[graf[v][i]])
                a[v] += a[graf[v][i]];
        }
    }
    if (v != 1 && a[v] >= x)
    {
        ans.push_back(f);
        a[v] -= x;
        done[v] = true;
    }
    else if (v != 1)
        toend.push_back(f);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < n * x - x)
    {
        cout << "NO" << endl;
        return 0;
    }
    int b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> b >> c;
        graf[b].push_back(c);
        graf[c].push_back(b);
        ind[b].push_back(i + 1);
        ind[c].push_back(i + 1);
    }
    dfs(1, 0);
    cout << "YES" << endl;
    for (auto v : ans)
        cout << v << "\n";
    reverse(toend.begin(), toend.end());
    for (auto v : toend)
        cout << v << "\n";
    return 0;
}