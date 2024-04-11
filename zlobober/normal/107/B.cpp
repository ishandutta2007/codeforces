#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, m, h;
    int s;
    cin >> n >> m >> h;
    --h;
    int S = 0, S1 = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (h == i)
            s--;
        S += s;
        if (h != i)
            S1 += s;
    }
    cerr << S1 << ' ' << S << endl;
    n--;
    #define double long double
    double ans = 1;
    if (S < n)
    {
        cout << "-1.0";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        ans *= (double)(S1 - i) / (S - i);
    }
    cout << fixed << setprecision(10) << 1 - ans;
}