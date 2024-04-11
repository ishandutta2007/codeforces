//
//  main.cpp
//  A
//
//  Created by  on 16/4/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const double pi = acos(-1);

int d,v,e,h;

int main(int argc, const char * argv[]) {
    cin >> d >> h >> v >> e;
    if(pi * e * d * d / 4 >= v){
        cout << "NO" << endl;
    }else{
        cout << "YES"<< endl;
        double ans = h * 1.0 / (v * 4.0 / d / d / pi - e);
        printf("%.10lf\n",ans);
    }
    return 0;
}