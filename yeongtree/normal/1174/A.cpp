#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n; n *= 2;
    int arr[n]; for(auto &i : arr) cin >> i;
    sort(arr, arr + n);

    bool flag = false;
    for(int i = 0; i < n - 1; ++i)
    if(arr[i] != arr[i + 1]) {flag = true; break;}

    if(flag) for(auto i : arr) cout << i << ' ';
    else cout << "-1";

    return 0;
}