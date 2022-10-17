#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        bool chc[n]{};
        int pr = -1;
        for(int i = 0; i < n; ++i)
        {
            int k; cin >> k;
            bool flag = true;
            for(int j = 0; j < k; ++j)
            {
                int x; cin >> x; --x;
                if(flag && !chc[x]) { chc[x] = true; flag = false; }
            }
            if(flag) pr = i;
        }
        if(pr != -1)
        {
            cout << "IMPROVE\n";
            for(int i = 0; i < n; ++i)
            {
                if(!chc[i])
                {
                    cout << pr + 1 << ' ' << i + 1 << '\n';
                    break;
                }
            }
        }
        else cout << "OPTIMAL\n";
    }
}