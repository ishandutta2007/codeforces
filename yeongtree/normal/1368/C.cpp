#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ++n;
    cout << 1 + 3 * n << '\n';
    cout << "0 0\n";
    for(int i = 0; i < n; ++i)
    {
        cout << i + 1 << ' ' << i << '\n';
        cout << i << ' ' << i + 1 << '\n';
        cout << i + 1 << ' ' << i + 1 << '\n';
    }
}