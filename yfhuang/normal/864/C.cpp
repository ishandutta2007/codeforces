#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int a,b,f,k;

int main(){
    bool flag = true;
    int cnt = 0;
    cin >> a >> b >> f >> k;
    if(b < f){
        flag = false;
    }else{
        int now = b - f;
        for(int i = 1;i <= k;i++){
            if(i < k){
                if(i & 1){
                    if(now < (a - f) * 2){
                        now = b - 2 * (a - f);
                        cnt++;
                    }else{
                        now = now - 2 * (a - f);
                    }
                }else{
                    if(now < 2 * f){
                        now = b - 2 * f;
                        cnt++;
                    }else{
                        now = now - 2 * f;
                    }
                }
                if(now < 0) flag = false;
            }
            else{
                if(i & 1){
                    if(now < (a - f)){
                        now = b - (a - f);
                        cnt++;
                    }else{
                        now = now - (a - f);
                    }
                }else{
                    if(now < f){
                        now = b - f;
                        cnt++;
                    }else{
                        now = now - f;
                    }
                }
                if(now < 0) flag = false;
            }
        }
    }
    if(!flag) printf("-1\n");
    else{
        printf("%d\n",cnt);
    }
    return 0;
}