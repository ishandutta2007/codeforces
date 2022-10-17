#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int arr[n]; int cnt[n]{};
        for(auto &i : arr) cin >> i, --i, ++cnt[i];
        int l = 0, r = n - 1;
        bool flag = true;
        vector<int> ans;
        for(int i = 0; i < n - 1; ++i)
        {
            if(flag && cnt[i]) ans.push_back(1);
            else ans.push_back(0);
            if(cnt[i] != 1) flag = false;
            else if(arr[l] == i) ++l;
            else if(arr[r] == i) --r;
            else flag = false;
        }
        flag = true;
        for(int i = 0; i < n; ++i) if(!cnt[i]) flag = false;
        if(flag) ans.push_back(1);
        else ans.push_back(0);
        reverse(ans.begin(), ans.end());
        for(auto i : ans) cout << i;
        cout << '\n';
    }
}