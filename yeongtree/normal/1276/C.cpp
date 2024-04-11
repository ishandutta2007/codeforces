#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    vector<int> pr(arr, arr + n);
    sort(pr.begin(), pr.end());
    pr.erase(unique(pr.begin(), pr.end()), pr.end());
    for(auto &i : arr) i = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
    int m = pr.size();
    int cnt[m]{}; for(auto i : arr) ++cnt[i];
    int ord[m]; for(int i = 0; i < m; ++i) ord[i] = i;
    sort(ord, ord + m, [&cnt](const int &x, const int &y){return cnt[x] < cnt[y];});
    pii fin[m]; for(int i = 0; i < m; ++i) fin[i] = {cnt[ord[i]], pr[ord[i]]};

    int r = 0, c = 0, mx = -1, i = 1, pos = 0, sm = 0;
    while(1)
    {
        while(pos < m && fin[pos].ff < i) sm += fin[pos++].ff;
        int tmp = sm + (m - pos) * i;
        int row = tmp / i;
        if(row < i) break;
        if(mx < i * row) mx = i * row, r = i, c = row;
        ++i;
    }

    int ans[r][c];
    i = 0; int j = 0;
    for(int k = m - 1; k >= 0; --k)
    {
        for(int l = 0; l < min(fin[k].ff, r); ++l)
        {
            ans[i][(i + j) % c] = fin[k].ss;
            ++i; if(i == r) i = 0, ++j;
        }
    }

    cout << r * c << '\n';
    cout << r << ' ' << c << '\n';
    for(auto &k : ans)
    {
        for(auto &l : k)
            cout << l << ' ';
        cout << '\n';
    }
}