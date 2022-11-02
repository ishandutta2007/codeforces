#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int ans[30];

int main(){
    int q;
    cin >> q;
    for(int i = 2;i <= 25;i++){
        int tmp = (1 << i) - 1;
        ans[i] = 1;
        for(int j = 2;j * j <= tmp;j++){
            if(tmp % j == 0){
                ans[i] = max(ans[i], j);
                ans[i] = max(ans[i], tmp / j);
            }
        }
    }
    while(q--){
        int a;
        cin >> a;
        int b0 = 0, b1 = 0;
        int tmp = a;
        while(tmp > 0){
            if(tmp & 1)
                b1++;
            else
                b0++;
            tmp >>= 1;
        }
        if(b0 > 0){
            cout << (1 << (b0 + b1)) - 1 << endl;
        }else{
            cout << ans[b1] << endl;
        }
    }
    return 0;
}