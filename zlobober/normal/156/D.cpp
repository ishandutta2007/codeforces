#include <iostream>
#include <cassert>
#include <list>
#include <vector>
using namespace std;

int n, m;

long long k;

const int N = 100500;
list<int> E[N];

vector<int> sz;


bool was[N];

int DFS(int x)
{
    was[x] = 1;
    int ans = 1;
    for (auto y : E[x])
        if (!was[y])
            ans += DFS(y);
    return ans;
}

void sDFS()
{
    for (int i = 1; i <= n; i++)
        if (!was[i])
            sz.push_back(DFS(i)), cerr << sz.back() << ' ';
}

int main()
{
    cin >> n >> m >> k;
    int a, b;
    for (int i = 0; i < m; i++)
        cin >> a >> b, E[a].push_back(b), E[b].push_back(a);
    sDFS();
    typedef long long llong;
    assert(!sz.empty());
    if (sz.size() == 1)
        cout << 1 % k;
    else
    {
        llong ans = 1;
        #define MUL(a, b) a = ((a) * (b)) % k;
        for (int i = 0; i < sz.size() - 2; i++)
            MUL(ans, n);
        for (int i = 0; i < sz.size(); i++)
            MUL(ans, sz[i]);
        cout << ans;
    }


}