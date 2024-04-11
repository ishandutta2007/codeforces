#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        int r = 0, w = 0;
        while(m--){
            int ri, wi;
            scanf("%d %d", &ri, &wi);

            r = max(r, ri);
            w = max(w, wi);
        }

        if(r + w > n){
            printf("IMPOSSIBLE\n");
            continue;
        }

        r += n - r - w;

        while(r--)printf("R");
        while(w--)printf("W");
        printf("\n");
    }

    return 0;
}