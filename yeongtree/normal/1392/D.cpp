#include <iostream>

using namespace std;

int arr[202020];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) arr[i] = 0;
        for(int i = 0; i < n; ++i)
        {
            char c; cin >> c;
            if(c == 'L') ++arr[i];
            else ++arr[(i + 1) % n];
        }

        int t = -1;
        for(int i = 0; i < n; ++i) if(arr[i] != 1) t = i;
        if(t == -1) cout << (n + 2) / 3 << '\n';
        else
        {
            int ans = 0;
            int conti = 0;
            for(int i = 0; i < n; ++i)
            {
                int x = (i + t) % n;
                if(arr[x] == 1) ++conti;
                else
                {
                    ans += (conti + 1) / 3;
                    conti = 0;
                }
            }
            ans += (conti + 1) / 3;
            cout << ans << '\n';
        }

    }
}