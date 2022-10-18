#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        array <int, 4> a;
        scanf("%d %d %d %d %d", &n, &a[0], &a[1], &a[2], &a[3], &a[4]);

        bool found = false;
        for(int mask = 0; mask < (1 << 4); mask++){
            bool ok = true;
            for(int i = 0; i < 4; i++){
                int cur = 0;
                if(mask & (1 << i))cur++;
                if(mask & (1 << ((i + 1) % 4)))cur++;

                if(cur > a[i] || a[i] - cur > n - 2){
                    ok = false;
                    break;
                }
            }
            if(ok){
                found = true;
                break;
            }
        }

        if(found)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}