#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    bool flag[n];
    for(auto &i : flag)
    {
        char c; cin >> c;
        i = (c == '1');
    }
    int a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    int ans = -1;
    for(int t = 0; t < 10000; ++t)
    {
        int cnt = 0;
        for(int i = 0; i < n; ++i)
            if(flag[i]) ++cnt;
        if(cnt > ans) ans = cnt;

        for(int i = 0; i < n; ++i)
            if(t >= b[i] && (t - b[i]) % a[i] == 0)
            flag[i] = !flag[i];
    }

    cout << ans;
    return 0;
}