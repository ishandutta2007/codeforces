#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        if(n % 2 == 1){
            printf("Bob\n");
            continue;
        }

        if((n & (n - 1)) == 0){
            int lg2 = 0;
            while(n % 2 == 0){
                lg2++;
                n >>= 1;
            }

            if(lg2 % 2 == 0){
                printf("Alice\n");
            }else{
                printf("Bob\n");
            }

            continue;
        }

        printf("Alice\n");
    }

    return 0;
}