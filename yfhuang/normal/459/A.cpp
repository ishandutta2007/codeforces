//
//  main.cpp
//  A
//
//  Created by  on 10/9/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int X1,Y1,X2,Y2;

int main(int argc, const char * argv[]) {
    cin >> X1 >> Y1 >> X2 >> Y2;
    if(X1 == X2){
        int len = abs(Y1 - Y2);
        printf("%d %d %d %d\n",X1 + len,Y1,X2 + len,Y2);
        return 0;
    }
    if(Y1 == Y2){
        int len = abs(X1 - X2);
        printf("%d %d %d %d\n",X1,Y1 + len,X2,Y2 + len);
        return 0;
    }
    if(abs(X1 - X2) != abs(Y1 - Y2)) printf("-1\n");
    else printf("%d %d %d %d\n",X1,Y2,X2,Y1);
    return 0;
}