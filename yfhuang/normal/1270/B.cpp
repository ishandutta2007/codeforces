#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int t;
int n;
const int maxn = 2e5 + 5;
int a[maxn];

int main(){
    cin >> t;
    while(t--){
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        bool flag = false;
        for(int i = 1;i < n;i++){
            if(abs(a[i] - a[i + 1]) > 1){
                puts("YES");
                printf("%d %d\n", i, i + 1);
                flag = true;
                break;
            }
        }
        if(!flag){
            puts("NO");
        }
    }
    return 0;
}