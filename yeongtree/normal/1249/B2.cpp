#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int arr[n]; for(auto &i : arr) {cin >> i; --i;}
        int rev[n]; for(int i = 0; i < n; ++i) rev[arr[i]] = i;
        int ans[n]{};

        for(int i = 0; i < n; ++i)
        {
            if(ans[i]) continue;
            int pt = i;
            do{++ans[i]; pt = arr[pt];}while(pt != i);
            do{ans[pt] = ans[i]; pt = rev[pt];}while(pt != i);
        }

        for(auto i : ans) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}