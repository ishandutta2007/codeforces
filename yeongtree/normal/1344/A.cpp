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
        bool chc[n]{};
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            chc[((i + x) % n + n) % n] = true;
        }
        bool flag = true;
        for(int i = 0; i < n; ++i) if(!chc[i]) { flag = false; cout << "NO\n"; break; }
        if(flag) cout << "YES\n";
    }
}