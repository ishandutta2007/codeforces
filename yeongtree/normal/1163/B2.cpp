#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;

    const int SZ = 1e5;
    int u[SZ + 1]{};
    int mx = 0, n0 = SZ, n1 = 0, nm_ = 0, nm = 0;
    int ans = -1;

    for(int i = 0; i < n; ++i)
    {
        int val = arr[i];
        ++u[val];

        if(mx < u[val])
        {
            if(mx + 1 == u[val]){nm_ = nm; nm = 0;}
            else nm_ = nm = 0;
            mx = u[val];
        }

        if(u[val] == 1){--n0; ++n1;}
        else if(u[val] == 2) --n1;
        if(u[val] == mx - 1) ++nm_;
        else if(u[val] == mx){--nm_; ++nm;}
        else if(u[val] == mx + 1) --nm;

        if(mx == 1) ans = i;
        else if(n1 == 1 && n0 + n1 + nm == SZ) ans = i;
        else if(nm == 1 && n0 + nm_ + nm == SZ) ans = i;
    }

    cout << ans + 1;
    return 0;
}