#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        int k;
        scanf("%d", &k);

        for(int i = 1; ; i++){
            if(k > 2 * i - 1){
                k -= 2 * i - 1;
                continue;
            }

            if(k <= i){
                printf("%d %d\n", k, i);
            }else{
                printf("%d %d\n", i, i - (k - i));
            }
            break;
        }
    }
    return 0;
}