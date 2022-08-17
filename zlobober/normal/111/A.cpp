#include <iostream>
using namespace std;

int main()
{
    int n;
    long long x, y;
    cin >> n >> x >> y;
    /*long long ssq = 0;
    int A[100005];
    for (int i = 0; i < n; i++)
        A[i] = x / n;
    for (int i = 0; i < n; i++)
        A[i] += (i < x % n);
    for (int i = 0; i < n; i++)
        ssq += A[i] * A[i];
    if (ssq
*/
    if (n > y)
    {
        cout << -1;
        return 0;
    }
    long long ssq = (n - 1) + (long long)(y - n + 1) * (y - n + 1);
    if (ssq >= x)
    {
        for (int i = 0; i < n - 1; i++)
            cout << 1 << endl;
        cout << y - n + 1 << endl;
    }
    else
        cout << -1;

}