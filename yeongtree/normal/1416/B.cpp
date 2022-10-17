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
        int arr[n]; long long sum = 0; for(int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];
        if(sum % n != 0) { cout << "-1\n"; continue; }
        cout << 3 * n - 3 << '\n';
        for(int i = 1; i < n; ++i)
        {
            cout << "1 " << i + 1 << ' ' << ( arr[i] % (i + 1) == 0 ? 0 : i + 1 - arr[i] % (i + 1) ) << '\n';
            cout << i + 1 << ' ' << "1 " << ( arr[i] % (i + 1) == 0 ? arr[i] / (i + 1) : arr[i] / (i + 1) + 1 ) << '\n';
        }
        for(int i = 1; i < n; ++i)
        {
            cout << "1 " << i + 1 << ' ' << sum / n << '\n';
        }
    }
}