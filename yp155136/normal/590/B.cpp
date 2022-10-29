#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long double ld;

int main ()
{
    ld x0,y0,x1,y1;
    cin >> x0 >>y0 >>x1 >>y1;
    ld v,t;
    cin >> v >>t;
    ld vx,vy,wx,wy;
    cin >>vx >> vy >>wx >>wy;
    ld L=0,R=1e15;
    int cnt=1000;
    while (cnt--)
    {
        ld mid = (L+R)/2;
        ld needx = x1-x0,needy=y1-y0;
        if (mid > t)
        {
            needx -= vx*t + wx*(mid-t);
            needy -= vy*t + wy*(mid-t);
        }
        else
        {
            needx -= vx*mid;
            needy -= vy*mid;
        }
        ld haha = powl(fabs(needx)/mid,2) + powl(fabs(needy)/mid,2);
        //cout << "mid = "<<mid<<" , haha = "<<haha<<endl;
        if (haha <= powl(v,2)) R=mid;
        else L=mid;
    }
    cout << fixed << setprecision(12) << L << endl;
}