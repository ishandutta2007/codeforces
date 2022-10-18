#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);

        if(k > (n - 1) / 2){
            printf("-1\n");
            continue;
        }

        printf("1");
        for(int i = 1; i < n; i += 2){
            if(i == n - 1){
                printf(" %d", i + 1);
            }else{
                if(k > 0){
                    k--;
                    printf(" %d %d", i + 2, i + 1);
                }else{
                    printf(" %d %d", i + 1, i + 2);
                }
            }
        }
        printf("\n");
    }
    return 0;
}