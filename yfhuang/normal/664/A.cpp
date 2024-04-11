//
//  main.cpp
//  A
//
//  Created by  on 16/4/17.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

string a,b;

int main(int argc, const char * argv[]) {
    cin >> a >> b;
    if( b.length() > a.length() || (a.length() == b.length() && b > a)){
        cout << 1 << endl;
    }else if(b == a){
        cout << a << endl;
    }
    return 0;
}