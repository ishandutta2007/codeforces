#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i & 1) cout << (1ll << (i + j)) << ' ';
            else cout << "0 ";
        }
        cout << endl;
    }
    cout.flush();

    int T; cin >> T;
    while(T--)
    {
        long long k; cin >> k;
        cout << "1 1" << endl;
        int px = 0, py = 0;
        for(int i = 1; i <= 2 * n - 3; ++i)
        {
            if((px ^ (k >> i)) & 1) ++px;
            else ++py;
            cout << px + 1 << ' ' << py + 1 << endl;
        }
        cout << n << ' ' << n << endl;
        cout.flush();
    }
}