#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
int num[105];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int a;
        scanf("%d",&a);
        num[a]++;
    }
    if(n & 1){
        puts("NO");
    }else{
        int ans = 0;
        for(int i = 1;i <= 100;i++){
            if(num[i] == n / 2) ans++;
        }
        if(ans == 2){
            printf("YES\n");
            for(int i = 1;i <= 100;i++){
                if(num[i] == n / 2) printf("%d ",i);
            }
        }else{
            puts("NO");
        }
    }
    return 0;
}