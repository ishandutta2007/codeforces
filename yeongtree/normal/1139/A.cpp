#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i)
    {
        char a; cin >> a;
        arr[i] = a - 48;
    }

    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        if(arr[i] % 2 == 0) ans += i;

    cout << ans;
    return 0;
}