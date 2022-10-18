#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        bool ok = true;
        for(int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);
        
            if(a < 0){
                ok = false;
            }
        }

        if(!ok){
            printf("NO\n");
            continue;
        }

        printf("YES\n%d\n", 101);
        for(int i = 0; i <= 100; i++){
            if(i > 0)printf(" ");
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}