#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    int u[10]{}, ans = -1;
    for(int i = 0; i < n; ++i)
    {
        u[arr[i] - 1]++;

        int _min = 1e6;
        for(int j = 0; j < 10; ++j) if(_min > u[j] && u[j] != 0) _min = u[j];
        bool flag = true; int cnt = 0;
        for(int j = 0; j < 10; ++j)
        {
            if(u[j] == 0 || u[j] == _min) continue;
            else if(u[j] == _min + 1) ++cnt;
            else {flag = false; break;}
            if(cnt >= 2) {flag = false; break;}
        }
        if(flag && cnt == 1) ans = i;

        else if(_min == 1)
    {


            _min = 1e6; int ch = -1;
                    for(int j = 0; j < 10; ++j)
                    {
                        if(u[j] == 0) continue;
                        if(u[j] == 1 && ch == -1)
                        {
                            ch = j;
                            continue;
                        }
                        if(_min > u[j]) _min = u[j];
                    }
                bool flag2 = true;
            for(int j = 0; j < 10; ++j)
                {
                    if(u[j] != _min && j != ch && u[j] != 0) {flag2 = false; break;}
                }
            if(flag2) ans = i;
        }

        else
        {
            int cnt = 0;
            for(int j = 0; j < 10;j++) if(u[j]) ++cnt;
            if(cnt == 1) ans = i;
        }
    }
    cout << ans + 1;
}