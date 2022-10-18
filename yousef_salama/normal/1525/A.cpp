#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int k;
        scanf("%d", &k);

        printf("%d\n", 100 / __gcd(k, 100 - k));
    }
    return 0;
}