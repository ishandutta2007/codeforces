//
//  main.cpp
//  1512
//
//  Created by  on 10/19/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL x1,y1,x2,y2,x3,y3;

bool check(LL xd,LL yd){
    if(x3 == 0 && y3 == 0) return xd == 0 && yd == 0;
    LL s = xd * x3 + yd * y3;
    LL v = (x3 * x3 + y3 * y3);
    if(s % v) return 0;
    s = yd * x3 - xd * y3;
    if(s % v) return 0;
    return 1;
}

int main(int argc, const char * argv[]) {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(check(x1 + x2,y1 + y2) || check(x1 - x2,y1 - y2) || check(x1 + y2,y1 - x2) || check(x1 - y2,y1 + x2)) puts("YES");
    else puts("NO");
    return 0;
}