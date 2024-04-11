#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; ++i) cin >> arr[i];

    int i = n - 2;
    for(; i >= 0; --i)
    {
        if(arr[i + 1] != arr[i]) break;
    }

    cout << i + 1;
}