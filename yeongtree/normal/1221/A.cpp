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
        int arr[n]; for(auto &i : arr) cin >> i;
        int cnt[12]{};
        for(auto i : arr)
        {
            for(int j = 0; j < 12; ++j)
                if(i == (1 << j)) ++cnt[j];
        }
        for(int i = 0; i < 11; ++i)
            cnt[i + 1] += cnt[i] / 2;
        cout << (cnt[11] ? "YES" : "NO") << '\n';
    }
    return 0;
}