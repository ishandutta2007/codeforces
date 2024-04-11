#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        if(n < (long long)k * k || (n ^ k) & 1) cout << "NO\n";
        else cout << "YES\n";
    }
}