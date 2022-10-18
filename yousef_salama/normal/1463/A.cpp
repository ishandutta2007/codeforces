#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int n = 7LL * (a + b + c);
        if(n % 9 != 0){
            printf("NO\n");
            continue;
        }
        n /= 9;

        if(a >= n / 7 && b >= n / 7 && c >= n / 7){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }    

    return 0;
}