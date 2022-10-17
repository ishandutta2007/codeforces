#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; int t = n / 2;
    int A[n]; for(auto &i : A) {cin >> i; --i;}
    int R[n]; for(int i = 0; i < n; ++i) R[A[i]] = i;

    vector<pair<int, int>> ans;

    for(int i = 0; i < n; ++i)
    {
        if(i == A[i]) continue;

        if(abs(i - R[i]) >= t) ans.emplace_back(i + 1, R[i] + 1);
        else if(i < t && R[i] < t)
        {
            ans.emplace_back(i + 1, n);
            ans.emplace_back(R[i] + 1, n);
            ans.emplace_back(i + 1, n);
        }
        else if(i >= t && R[i] >= t)
        {
            ans.emplace_back(i + 1, 1);
            ans.emplace_back(R[i] + 1, 1);
            ans.emplace_back(i + 1, 1);
        }
        else if(i < t && R[i] >= t)
        {
            ans.emplace_back(i + 1, n);
            ans.emplace_back(1, n);
            ans.emplace_back(R[i] + 1, 1);
            ans.emplace_back(1, n);
            ans.emplace_back(i + 1, n);
        }
        else
        {
            ans.emplace_back(i + 1, 1);
            ans.emplace_back(1, n);
            ans.emplace_back(R[i] + 1, n);
            ans.emplace_back(1, n);
            ans.emplace_back(i + 1, 1);
        }

        A[R[i]] = A[i]; R[A[i]] = R[i]; A[i] = i; R[i] = i;
    }

    cout << ans.size() << '\n';
    for(auto &i : ans) cout << i.first << ' ' << i.second << '\n';

    return 0;
}