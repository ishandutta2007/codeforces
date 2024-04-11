#include <iostream>

using namespace std;

int main()
{
    int m; cin >> m;
    int arr[m]; for(int i = 0; i < m; ++i) cin >> arr[i];
    int p = 0, n = 0;
    for(int i = 0; i < m; ++i)
    {
        if(arr[i] > 0) ++p;
        if(arr[i] < 0) ++n;
    }
    int k = (m + 1) / 2;
    if(p >= k){cout << "1" ; return 0;}
    if(n >= k) {cout << "-1"; return 0;}
    cout << '0'; return 0;
}