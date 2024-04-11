#include <iostream>
#include <algorithm>
#include <cassert>
#include <set>
using namespace std;

int main()
{
    typedef long long llong;
    llong q;
    cin >> q;
    if (q == 1)
        cout << 1 << endl << 0;
    else
    {
        int was = 0;
        bool sq = false;
        llong div[1000000];
        int pt = 0;
        for (llong t = 2; t * t <= q; t++)
        {
            if (q % t == 0)
            {
                div[pt++] = t;
                if (t * t != q)
                    div[pt++] = q / t;
            }
            if (t * t == q)
                sq = true;
        }
        sort(div, div + pt);
        if (!pt)
        {
            cout << 1 << endl << 0;
        }
        else if (pt == 1)
        {
            cout << 2;
        }
        else
        {
            assert(pt >= 2);
            if (div[1] % div[0] == 0)
                cout << 1 << endl << div[1];
            else
            {
                if (div[1] * div[0] != q)
                    cout << 1 << endl << div[1] * div[0];
                else
                    cout << 2;
            }
        }
    }
    cout << endl;
}