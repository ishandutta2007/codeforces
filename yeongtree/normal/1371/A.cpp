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
        cout << (n +1) /2 << '\n';
    }
}