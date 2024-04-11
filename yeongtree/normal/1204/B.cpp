#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r; cin >> n >> l >> r;

    long long mn = 0;
    long long tmp = 1;
    for(int i = 0; i < l; ++i)
    {
        mn += tmp;
        tmp <<= 1;
    }
    mn += (n - l);

    long long mx = 0;
    tmp = 1;
    for(int i = 0; i < r - 1; ++i)
    {
        mx += tmp;
        tmp <<= 1;
    }
    mx += (n - r + 1) * tmp;

    cout << mn << ' ' << mx;
}