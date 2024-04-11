#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main () {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    if (abs(c-a)%e==0 && abs(d-b)%f==0) {
        if (abs(c-a)/e %2 == abs(d-b)/f%2)puts("YES");
        else puts("NO");
    }
    else puts("NO");
}