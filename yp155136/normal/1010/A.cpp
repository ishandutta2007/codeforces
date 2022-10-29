#include <bits/stdc++.h>
using namespace std;

int a[1006],b[1006];

int main ()
{
    int n,m;
    cin >> n >> m;
    for (int i=1;n>=i;i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i=1;n>=i;i++)
    {
        cin >> b[i];
        if (b[i] == 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    double L=0,R = 1e9;
    int cnt = 100;
    b[n+1] = b[1];
    while (cnt--)
    {
        double mid = (L+R)/2;
        bool can = true;
        double w = mid + m;
        for (int i=1;n>=i;i++)
        {
            w -= w/a[i];

            if (w < m)
            {
                can = false;
                break;
            }
            w -= w/(b[ i+1 ]);

            if (w < m)
            {
                can = false;
                break;
            }
        }
        if (can) R= mid;
        else L = mid;
    }
    cout << fixed << setprecision(12) << R << endl;
}