#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        long long n; cin >> n;
        if(n < 15) cout << "NO\n";
        else
        {
            int t = n % 14;
            if(1 <= t && t <= 6) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}