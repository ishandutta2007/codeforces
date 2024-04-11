#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s[n]; for(auto &i : s) cin >> i;
    int arr[n][n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(s[i][j] == '1') arr[i][j] = 1;
            else if(i == j) arr[i][j] = 0;
            else arr[i][j] = 987654321;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        int __arr[n][n];

        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                __arr[j][k] = min(arr[j][i] + arr[i][k], arr[j][k]);
            }
        }

        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
            arr[j][k] = __arr[j][k];
    }

    int m; cin >> m;
    int p[m]; for(auto &i : p) {cin >> i; --i;}

    vector<int> ans;
    ans.push_back(0);
    for(int i = 1; i < m; ++i)
    {
        if(arr[p[ans.back()]][p[i]] != i - ans.back()) ans.push_back(i - 1);
    }
    ans.push_back(m - 1);

    cout << ans.size() << '\n';
    for(auto i : ans) cout << p[i] + 1 << ' ';
    return 0;
}