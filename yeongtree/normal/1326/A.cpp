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
        if(n == 1) cout << "-1\n";
        else
        {
            for(int i = 0; i < n - 2; ++i) cout << 2;
            if(n % 9 == 1)
            {
                cout << 4;
            }
            else cout << 2;
            cout << "9\n";
        }
    }
}