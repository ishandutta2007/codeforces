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
#include <random>
#include <chrono>
using namespace std;

int n, k;

typedef long long LL;
LL a[40];
LL bit[40];

LL cal(LL num, LL k){
    LL res = 0;
    for(int i = 0;i < 60;i++){
        if(num == 0)
           break; 
        LL mod = num % k;
        num /= k;
        if(mod > 1){
            return -1;
        }else{
            if(mod == 1)
                res |= (1LL << i);
        }
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        bool flag = true;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
            bit[i] = cal(a[i], k);
            if(bit[i] == -1){
                flag = false;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(bit[i] & bit[j]){
                    flag = false;
                }
            }
        }
        if(flag){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}