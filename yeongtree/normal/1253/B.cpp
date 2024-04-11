#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    int tp[1010101]{}; int cnt = 0;
    int sz = 1; vector<int> ans;

    for(int i = 0; i < n; ++i)
    {
        if(arr[i] > 0)
        {
            if(abs(tp[arr[i]]) == sz) {cout << -1; return 0;}
            tp[arr[i]] = sz; ++cnt;
        }
        else
        {
            if(tp[-arr[i]] != sz) {cout << -1; return 0;}
            tp[-arr[i]] = -sz; --cnt;
        }
        if(cnt == 0)
        {
            ++sz;
            ans.push_back(i);
        }
    }
    if(cnt) {cout << -1; return 0;}

    --sz;
    cout << sz << '\n';
    cout << ans[0] + 1 << ' ';
    for(int i = 1; i < sz; ++i) cout << ans[i] - ans[i - 1] << ' ';
    return 0;
}