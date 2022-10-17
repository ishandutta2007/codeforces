#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r; cin >> l >> r;
    int x = r - l;

    cout << "YES\n";

    vector<piii> ans;

    ans.push_back({1, {22, l}});

    for(int i = 2; i < 22; ++i)
    {
        for(int j = i + 1; j <= 22; ++j)
        ans.push_back({i, {j, (j == 22 ? l : (1 << (21 - j)))}});
    }

    int pr = 1;
    for(int i = 0; i < 20; ++i) if(x >> i & 1)
    {
        ans.push_back({1, {21 - i, pr}});
        pr += (1 << i);
    }

    cout << "22 " << ans.size() << '\n';
    for(auto i : ans)
    {
        cout << i.ff << ' ' << i.ee << ' ' << i.rr << '\n';
    }
}