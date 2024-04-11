#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        long long a, b;
        scanf("%lld %lld", &a, &b);

        if(b == 1)printf("NO\n");
        else if(b == 2){
            printf("YES\n");
            printf("%lld %lld %lld\n", a, 3 * a, 4 * a);
        }else{
            printf("YES\n");
            printf("%lld %lld %lld\n", a, a * (b - 1), a * b);
        }
    }
    return 0;
}