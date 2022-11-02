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

int n;
const int maxn = 1e5 + 5;
int x[maxn * 2], y[maxn * 2];

typedef long long LL;

LL dis(LL x1, LL y1, LL x2, LL y2){
    return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2);
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d%d", &x[i], &y[i]);
        x[i + n] = x[i];
        y[i + n] = y[i];
    }
    if(n & 1){
        cout << "NO" << endl;
    }else{
        bool flag = true;
        for(int i = 0;i < n / 2;i++){
            if(1LL * (x[i + 1] - x[i]) * (y[i + n / 2 + 1] - y[i + n / 2]) - 1LL * (x[i + n / 2 + 1] - x[i + n / 2]) * (y[i + 1] - y[i]) == 0){
                if(dis(x[i + 1], y[i + 1], x[i], y[i]) != dis(x[i + 1 + n / 2], y[i + 1 + n / 2], x[i + n / 2], y[i + n / 2])){
                    flag = false;
                }else{

                }
            }else{
                flag = false;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}