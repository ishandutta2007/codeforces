//
//  main.cpp
//  A
//
//  Created by  on 9/8/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a,b;

typedef long long ll;

void print(char x,int num){
    for(int i = 1;i <= num;i++){
        printf("%c",x);
    }
}

int main(int argc, const char * argv[]) {
    cin >> a >> b;
    long long ans = -1e18;
    int t = 0;
    if(a == 0){
        cout << -1 * (ll) b * (ll) b << endl;
        print('x',b);
        return 0;
    }
    if(b == 0 || b == 1){
        cout << (ll) a * (ll) a - b * b << endl;
        print('o',a);
        print('x',b);
        return 0;
    }
    for(int i = 1;i <= a;i++){
        long long tmp = (ll) (a - (i - 1)) * (ll) (a - (i - 1)) + (i - 1);
        ll num = i + 1;
        if(num > b) break;
        ll x = (ll) b / num;
        ll y = b - x * (ll) num;
        tmp -= y * (ll) (x + 1) * (x + 1) + (num - y) * x * x;
        if(tmp > ans){
            ans = tmp;
            t = i;
        }
    }
    cout << ans << endl;
   // cout << t << endl;
    for(int i = 1;i <= t * 2 + 1;i++){
        if(i & 1){
            int x = (i + 1) / 2;
            ll num = t + 1;
            ll xx = (ll)b / num;
            ll yy = b - xx * num;
            if(x <= yy) print('x',xx + 1);
            else print('x',xx);
        }else{
            if(i == 2){
                print('o',a - t + 1);
            }else{
                print('o',1);
            }
        }
    }
    return 0;
}