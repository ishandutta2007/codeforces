#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int T; cin >> T;
    while(T--)
    {
        int a, b, c; cin >> a >> b >> c;
        int m = min(b, c / 2);
        b -= m;
        int n = min(a, b / 2);
        cout << 3 * (n + m) << '\n';
    }
}