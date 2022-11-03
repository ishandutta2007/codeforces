//
//  main.cpp
//  C
//
//  Created by  on 16/4/17.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long p;
long long base;
char s[20];
long long a;
long long d;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--){
        base = 1989;d = 10;
        scanf("%s",s);
        int i;
        for(i = 0,a = 0;s[i + 4] >= '0' && s[i + 4] <= '9';i++) a = a * 10 + (long long) (s[i + 4] - '0');
        for(int j = 2;j <= i;j++){
            base += d;
            d *= 10;
        }
        //cout << base <<endl<< d  << endl<< a << endl ;
        for(i = 0;i * d + a < base;i++);
        cout << i * d + a << endl;
    }
    return 0;
}