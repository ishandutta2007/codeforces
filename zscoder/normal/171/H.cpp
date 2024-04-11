#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int rx, ry;

void go(int lev, int b, int xa, int ya, int xv, int yv) {
    if(lev==0) {
        rx=xa; ry=ya;
        return;
    }
    --lev;
    int t=(b>>(lev*2))&3;
    if(t==0) {
        go(lev, b, xa, ya, yv, xv);
    } else if(t==1) {
        go(lev, b, xa+yv*(1<<(lev)), ya+xv*(1<<(lev)), xv, yv);
    } else if(t==2) {
        go(lev, b, xa+yv*(1<<(lev))+xv*(1<<(lev)),
                ya+xv*(1<<(lev))+yv*(1<<(lev)),
                xv, yv);
    } else if(t==3) {
        go(lev, b, xa+xv*((1<<(lev+1))-1)+yv*((1<<(lev))-1),
                ya+yv*((1<<(lev+1))-1)+xv*((1<<(lev))-1),
                -yv, -xv);
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    go(a, b, 0, 0, 1, 0);
    printf("%d %d\n", rx, ry);
    return 0;
}