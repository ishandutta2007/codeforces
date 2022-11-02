#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 2e5 + 5;

typedef long long LL;

LL b[maxn];
int n;

int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            scanf("%lld", &b[i]);    
        }
        LL ans = n;
        LL bestpow = -1;
        LL power = 1;
        for(int i = 0;i <= 60;i++){
            LL temp = 0;
            for(int i = 1;i <= n;i++){
                if(b[i] % power){
                    temp++;
                    continue;
                } 
                if((b[i] / power) % 2 == 0){
                    temp++;
                    continue;
                }
            }
            if(temp < ans){
                ans = temp;
                bestpow = power;
            }
            power *= 2;
        }
        cout << ans << endl;
        for(int i = 1;i <= n;i++){
            if(b[i] % bestpow){
                printf("%lld ", b[i]);
                continue;
            }
            if((b[i] / bestpow) % 2 == 0){
                printf("%lld ", b[i]);
                continue;
            }
        }
    }
    return 0;
}