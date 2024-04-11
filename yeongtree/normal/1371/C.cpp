#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        long long a, b, n, m; cin >> a >> b >>n >>m;
        if(a + b >= n + m && min(a, b) >= m) cout << "Yes\n";
        else cout << "No\n";
    }
}