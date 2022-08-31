#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > T, A;
const int N = 1050;
vector<vector<pair<int, int> > >ans;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int c, t;
        cin >> c >> t;
        if (t == 1)
            T.push_back(make_pair(c, i));
        else
            A.push_back(make_pair(c, i));
    }
    sort(T.begin(), T.end());
    reverse(T.begin(), T.end());
    sort(A.begin(), A.end());
    ans.resize(k);
    for (int i = 0; i < min(k, (int)T.size()); i++)
        ans[i].push_back(T[i]);
    for (int i = min(k, (int)T.size()); i < T.size(); i++)
        ans.back().push_back(T[i]);
    for (int i = 0; i < max(k - (int)T.size(), 0); i++)
        ans[i + T.size()].push_back(A[i]);
    for (int i = max(k - (int)T.size(), 0); i < A.size(); i++)
        ans.back().push_back(A[i]);
    long long res = 0;
    for (int i = 0; i < k; i++)
    {
        assert(!ans[i].empty());
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++)
            res += 2 * ans[i][j].first;
        if (i < T.size())
            res -= ans[i][0].first;
    }
    cout << res / 2 << '.' << (res % 2) * 5 << endl;
    for (int i = 0; i < k; i++)
    {
        cout << ans[i].size() << ' ';
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j].second + 1 << ' ';
        cout << endl;
    }
    return 0;
}