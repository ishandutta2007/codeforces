#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;

LL x[100], y[100];
LL ax, ay, bx, by;
LL xs, ys, t;


int main(){
    cin >> x[0] >> y[0];
    cin >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    int i;
    for(i = 1;;i++){
        x[i] = ax * x[i - 1] + bx;
        y[i] = ay * y[i - 1] + by;
        if(x[i] > xs + t or y[i] > ys + t){
            break;
        }
    } 
    LL ans = 0;
    for(int j = 0;j < i;j++){
        for(int k = 0;k < i;k++){
            LL len = abs(x[j] - xs) + abs(y[j] - ys);
            len += abs(x[k] - x[j]) + abs(y[k] - y[j]);
            if(len <= t){
                ans = max(ans, max(j, k) - min(j, k) + 1LL);
            }
        }
    }
    cout << ans << endl;
    return 0;
}