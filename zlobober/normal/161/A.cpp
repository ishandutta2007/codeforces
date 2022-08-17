#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100500;

pair<int, int> A[N], B[N];

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> A[i].first, A[i].second = i;

    for (int i = 0; i < m; i++)
        cin >> B[i].first, B[i].second = i;
    sort(A, A + n);
    sort(B, B + m);
    int pt = 0;
    B[m] = make_pair(2000000001, -42);
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++)
    {
        while (B[pt].first < A[i].first - x)
            pt++;
        if (B[pt].first <= A[i].first + y)
        {
            ans.push_back(make_pair(A[i].second + 1, B[pt].second + 1));
            pt++;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;
}