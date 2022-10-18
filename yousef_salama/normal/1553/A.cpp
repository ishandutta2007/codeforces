#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        printf("%d\n", n / 10 + (n % 10 == 9));
    }
    return 0;
}