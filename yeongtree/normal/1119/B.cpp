#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h; cin >> n >> h;
    int arr[n]; for(int &i : arr) cin >> i;

    for(int i = 0; i < n; ++i)
    {
        int tmp = arr[i];
        for(int j = 0; j < i; ++j)
            if(tmp < arr[j]) swap(tmp, arr[j]);
        arr[i] = tmp;

        int ans = 0;
        for(int j = i; j >= 0; j -= 2)
            ans += arr[j];

        if(ans > h){cout << i; return 0;}
    }

    cout << n; return 0;
}