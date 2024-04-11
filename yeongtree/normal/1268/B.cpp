#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] & 1)
        {
            if(i & 1) ++ans;
            else --ans;
        }
    }
    ans = (ans < 0 ? -ans : ans);
    long long sum = 0;
    for(auto i : arr) sum += i;
    cout << (sum - ans) / 2;
}