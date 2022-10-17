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
        cout << a + b + c << ' ' << b + c << ' ' << c << '\n';
    }
}