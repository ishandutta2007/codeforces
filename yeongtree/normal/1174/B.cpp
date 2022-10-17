#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    bool flag = false;
    for(int i = 0; i < n - 1; ++i)
    {
        if((arr[i] & 1) != (arr[i + 1] & 1))
        {
            flag = true; break;
        }
    }

    if(flag)
    {
        sort(arr, arr + n);
    }

    for(auto i : arr) cout << i << ' ';

    return 0;
}