//
//  main.cpp
//  A
//
//  Created by  on 2017/5/7.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int t;

long long x,y,p,q;

typedef long long LL;
void gcd(LL a,LL b,LL & d,LL &x,LL &y){
    if(!b) {d = a ; x = 1 ;y = 0;}
    else {gcd(b,a % b,d,y,x);y -= x * (a/b);}
}

int main(int argc, const char * argv[]) {
    //cout << __gcd(4,-2) << endl;
    cin >> t;
    while(t--){
        cin >> x >> y >> p >> q;
        if(p == q){
            if(y == x){
                printf("0\n");
                continue;
            }else{
                printf("-1\n");
                continue;
            }
        }else{
            if(p == 0){
                if(x == 0) printf("0\n");
                else printf("-1\n");
                continue;
            }
            if((p * y - q * x) % __gcd(q - p,p) == 0){
                LL a = p - x % p;
                a %= p;
                LL b = q * (a + x) / p - (a + y);
                if(b >= 0){
                    cout << a + b << endl;
                }else{
                    b = (b % (q - p) + q - p) % (q - p);
                    a = (p * y - q * x + p * b) / (q - p);
                    cout << a + b << endl;
                }
            }else{
                printf("-1\n");
                continue;
            }
        }
    }
    return 0;
}