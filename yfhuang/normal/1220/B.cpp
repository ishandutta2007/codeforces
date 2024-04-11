#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

int n;
const int maxn = 1005;

LL a[maxn][maxn];

int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                scanf("%lld", &a[i][j]);
            }
        }
        for(int i = 3;i <= n;i++){
            a[i][i] = a[i - 1][i] * a[i][1] / a[i - 1][1];
        }
        a[2][2] = a[3][2] * a[2][1] / a[3][1];
        a[1][1] = a[3][1] * a[1][2] / a[3][2];
        for(int i = 1;i <= n;i++){
            printf("%d ", (int)sqrt(a[i][i] + 0.5));
        }
    }
    return 0;
}