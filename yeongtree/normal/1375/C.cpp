#include <iostream>

using namespace std;

int arr[303030];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        cout << (arr[0] < arr[n - 1] ? "YES" : "NO") << '\n';
    }
}