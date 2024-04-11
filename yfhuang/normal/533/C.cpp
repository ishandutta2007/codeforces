#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long xp,yp,xv,yv;

int main(){
          cin >> xp >> yp >> xv >> yv;
          if(xp + yp <= max(xv,yv) || (xp <= xv && yp <= yv )) printf("Polycarp\n");
          else printf("Vasiliy");
          return 0;
}