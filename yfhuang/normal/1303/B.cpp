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
#include <queue>

using namespace std;

int T;

typedef long long LL;
LL n, g, b;

bool check(LL mid){
    LL t = mid / (g + b);
    LL t1 = mid - t * (g + b);
    LL t2 = min(g, t1);
    t1 -= t2;
    LL G = t * g + t2;
    LL B = t * b + t1;
    if(G + B >= n and G * 2 >= n){
        return true;
    }
    return false;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> g >> b;
        LL l = 0, r = 1e18;
        while(l < r){
            LL mid = (l + r) / 2;
            if(check(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}