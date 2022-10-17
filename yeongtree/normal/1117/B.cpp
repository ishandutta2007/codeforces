#include <iostream>

using namespace std;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int arr[n]; for(int i = 0; i < n; ++i) cin >> arr[i];

    int m1 = 0;
    for(int i = 1; i < n; ++i)
    {
        if(arr[m1] < arr[i]) m1 = i;
    }

    int m2 = (m1 + 1) % n;
    for(int i = 0; i < n; ++i)
    {
        if(arr[m2] < arr[i] && m1 != i) m2 = i;
    }

    cout << ((long long)arr[m1] * k + (long long)arr[m2]) * (long long)(m / (k + 1))
            + (long long)arr[m1] * (long long)(m % (k + 1));
    return 0;
}