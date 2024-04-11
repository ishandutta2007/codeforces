#include <iostream>

using namespace std;

int arr[202020];

void f(int n)
{
    int mx = arr[0];
    for(int i = 0; i < n; ++i) mx = max(mx, arr[i]);
    for(int i = 0; i < n; ++i) arr[i] = mx - arr[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; long long k; cin >> n >> k;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        if(k == 0) for(int i = 0; i < n; ++i) cout << arr[i] << ' ';
        else
        {
            f(n);
            if(k & 1) for(int i = 0; i < n; ++i) cout << arr[i] << ' ';
            else
            {
                f(n);
                for(int i = 0; i < n; ++i) cout << arr[i] << ' ';
            }
        }
        cout << '\n';
    }
}