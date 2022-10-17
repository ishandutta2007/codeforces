#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

vector<int> gph[505050];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    pii arr[n];
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x; --x;
        arr[i] = {x, i};
    }
    sort(arr, arr + n);

    int top[n]; for(auto &i : top) i = -1;

    for(int i = 0; i < n; ++i)
    {
        int x = arr[i].ss;
        int cnt = arr[i].ff;
        vector<int> V(cnt + 1);
        for(auto y : gph[x]) if(top[y] != -1) V[top[y]] = 1;
        if(V[cnt] == 1) {cout << -1; return 0;}
        for(int i = 0; i < cnt; ++i) if(V[i] == 0) {cout << -1; return 0;}
        top[x] = cnt;
    }

    for(int i = 0; i < n; ++i) cout << arr[i].ss + 1 << ' ';
}