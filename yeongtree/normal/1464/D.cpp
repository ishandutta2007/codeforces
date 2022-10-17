#include <iostream>
#include <vector>

using namespace std;

const int Q = (int)1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int p[n]; for(auto &i : p) cin >> i, --i;
        int cyc[3]{};
        bool vst[n]{}; bool flag = false;
        for(int i = 0; i < n; ++i) if(!vst[i])
        {
            int cnt = 0, pt = i;
            do{
                ++cnt;
                vst[pt] = true;
                pt = p[pt];
            }while(pt != i);
            ++cyc[cnt % 3];
            if(cnt % 3 == 1 && cnt > 1) flag = true;
        }

        if(n % 3 == 0)
        {
            int ans = 1;
            for(int i = 0; i < n; i += 3) ans = 1ll * ans * 3 % Q;
            cout << ans << ' ' << n / 3 - cyc[0] + (max(cyc[1], cyc[2]) - min(cyc[1], cyc[2])) / 3 << '\n';
        }

        else if(n % 3 == 1)
        {
            int ans = 4;
            for(int i = 4; i < n; i += 3) ans = 1ll * ans * 3 % Q;
            if(cyc[1] > cyc[2] && flag) cout << ans << ' ' << (n - 1) / 3 - cyc[0] + (cyc[1] - cyc[2] - 4) / 3 << '\n';
            else if(cyc[1] == 1 && cyc[2] == 0) cout << ans << ' ' << (n - 1) / 3 - cyc[0] + 1 << '\n';
            else if(cyc[1] > cyc[2]) cout << ans << ' ' << (n + 2) / 3 - cyc[0] + (cyc[1] - cyc[2] - 4) / 3 << '\n';
            else cout << ans << ' ' << (n + 2) / 3 - cyc[0] + (cyc[2] - cyc[1] - 8) / 3 << '\n';
        }

        else
        {
            int ans = 2;
            for(int i = 2; i < n; i += 3) ans = 1ll * ans * 3 % Q;
            if(cyc[1] > cyc[2]) cout << ans << ' ' << (n + 1) / 3 - cyc[0] + (cyc[1] - cyc[2] - 2) / 3 << '\n';
            else cout << ans << ' ' << (n + 1) / 3 - cyc[0] + (cyc[2] - cyc[1] - 4) / 3 << '\n';
        }
    }
}