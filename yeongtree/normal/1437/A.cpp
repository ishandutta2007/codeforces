#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int a, b; cin >> a >> b;
        cout << (a * 2 >= (b + 1) ? "YES" : "NO") << '\n';
    }
}