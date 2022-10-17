#include <iostream>
#include <algorithm>

using namespace std;

long long f(int* arr, int b, int e, int l, int r, const long long& A, const long long& B)
{
    if(l == r) return A;
    if(b + 1 == e) return (r - l) * B;

    int m = (b + e) / 2;
    int _l = l, _r = r;

    if(arr[_l] >= m) _r = _l;

    while(_l + 1 < _r)
    {
        int mid = (_l + _r) / 2;
        if(arr[mid] >= m) _r = mid;
        else _l = mid;
    }

    return min(B * (r - l) * (e - b), f(arr, b, m, l, _r, A, B) + f(arr, m, e, _r, r, A, B));
}

int main()
{
    int n, k; long long A, B; cin >> n >> k >> A >> B; int N = (1 << n);
    int arr[k]; for(int i = 0; i < k; ++i) {cin >> arr[i]; --arr[i];}
    sort(arr, arr + k);

    cout << f(arr, 0, N, 0, k, A, B) << '\n';
    return 0;
}