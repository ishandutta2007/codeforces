#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> cnt(30, 0);
        for(int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);
            for(int j = 0; j < 30; j++){
                if(a & (1 << j))cnt[j]++;
            }
        }

        printf("1");
        for(int k = 2; k <= n; k++){
            bool ok = true;
            for(int j = 0; j < 30; j++){
                if(cnt[j] % k != 0){
                    ok = false;
                    break;
                }
            }

            if(ok)printf(" %d", k);
        }
        printf("\n");
    }
    return 0;
}