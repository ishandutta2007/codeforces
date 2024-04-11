//#include <algorithm>
#include <iostream>
//#include <vector>
#include <cstdio>
//#include <cstdint>
//#include <conio.h>
//#include <ctime>
//#include <cctype>
//#include <cstdlib>
//#include <random>
//#include <iomanip>
//#include <cmath>
//#include <cstring>
//#include <string>
//#include <queue>
//#include <set>
//#include <chrono>
//#include <functional>

using namespace std;

int main()
{
    long long x; cin >> x; --x;
    if(x == 0) {cout << "NO"; return 0;}

    long long ev = 1, od = x;
    while(~od & 1) {ev <<= 1; od >>= 1;}
    if(ev == 1) {cout << "NO"; return 0;}

    long long di = 1;
    while(di * di <= od)
    {
        if(od % di == 0)
        {
            break;
        }
        di += 2;
    }
    if(di * di > od) di = od;

    long long mn, mx;
    if(ev < di) mn = ev, mx = od;
    else mn = di, mx = x / di;

    if(mx < mn + 3) {cout << "NO"; return 0;}
    cout << mn << ' ' << (mx - mn - 1) / 2;
    return 0;
}