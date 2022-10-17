#include <iostream>

using namespace std;

int arr[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        long long t = 0;
        for(int i = 1; i < n; ++i) t += max(arr[i] - arr[i - 1], 0);
        if(t <= arr[n - 1]) cout << "YES\n";
        else cout << "NO\n";
    }
}