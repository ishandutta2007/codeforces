#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s; cin >> s;

    int pow[10]; pow[0] = 1; for(int i = 1; i < 10; ++i) pow[i] = pow[i - 1] * 9;

    int n = s.size();
    int arr[n]; for(int i = 0; i < n; ++i) arr[i] = s[i] - 48;

    int ans = arr[n - 1];
    for(int i = n - 2; i >= 0; --i)
    {
        ans = max(ans * (arr[i] == 0 ? 1 : arr[i]), pow[n - i - 1] * (arr[i] == 1 ? 1 : arr[i] - 1));
    }

    cout << ans;
    return 0;
}