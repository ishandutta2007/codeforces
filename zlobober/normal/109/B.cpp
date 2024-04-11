#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 5000;

int arr[N];
int pt = 0;

long long cc(int l, int r, int p, int q)
{
    return max(0, min(q, r) - max(p, l) + 1);
}

int main()
{
    for (int l = 1; l <= 9; l++)
    {
        for (int msk = 0; msk < (1 << l); msk++)
        {
            int q = 0;
            for (int i = 0; i < l; i++)
                q = 10 * q + 4 + ((msk >> i) & 1) * 3;
            arr[pt++] = q;
        }
    }
    arr[pt++] = -1;
    arr[pt++] = 2e9;
    sort(arr, arr + pt);
    cerr << pt << endl;

    int l1, r1, l2, r2, n;
    cin >> l1 >> r1 >> l2 >> r2 >> n;

    long long cnt = 0;

    for (int i = 1; i + n < pt; i++)
    {
        cnt += cc(l1, r1, arr[i - 1] + 1, arr[i]) * cc(l2, r2, arr[i + n - 1], arr[i + n] - 1);
        cnt += cc(l2, r2, arr[i - 1] + 1, arr[i]) * cc(l1, r1, arr[i + n - 1], arr[i + n] - 1);
        if (n == 1)
        {
            cnt -= cc(l1, r1, arr[i], arr[i]) * cc(l2, r2, arr[i], arr[i]);
        }
    }
    cout << fixed << setprecision(10);
    cout << (long double)cnt / ((long long)(r1 - l1 + 1) * (long long)(r2 - l2 + 1));
}