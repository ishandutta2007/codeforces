#include <iostream>
#include <vector>

using namespace std;

const int Q = (int)1e9 + 7;

int par[505050];
bool chc[505050];
int fnd(int x) { return par[x] == x ? x : (par[x] = fnd(par[x])); }
void uni(int x, int y)
{
    x = fnd(x), y = fnd(y);
    par[x] = y;
    if(chc[x]) chc[y] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> m >> n;
    for(int i = 0; i < n; ++i) par[i] = i;
    vector<int> V;
    for(int i = 0; i < m; ++i)
    {
        int k; cin >> k;
        if(k == 1)
        {
            int x; cin >> x; --x;
            if(!chc[fnd(x)])
            {
                V.push_back(i + 1);
                chc[fnd(x)] = true;
            }
        }
        if(k == 2)
        {
            int x, y; cin >> x >> y; --x; --y;
            if(fnd(x) != fnd(y) && (!chc[fnd(x)] || !chc[fnd(y)]))
            {
                V.push_back(i + 1);
                uni(x, y);
            }
        }
    }
    int ans = 1;
    for(int i = 0; i < (int)V.size(); ++i) ans = ans * 2 % Q;
    cout << ans << ' ' << (int)V.size() << '\n';
    for(auto i : V) cout << i << ' ';
}