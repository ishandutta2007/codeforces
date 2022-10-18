#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        int c[] = {0, 0};

        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            c[a[i] % 2]++;
        }

        if(abs(c[0] - c[1]) >= 2){
            printf("-1\n");
            continue;
        }

        long long res = 1LL << 60;

        for(int st = (c[1] > c[0]); st <= 1 - (c[0] > c[1]); st++){
            long long cur = 0;
            for(int i = 0, j = st; i < n; i++)if(a[i] % 2 == 0){
                cur += abs(i - j);
                j += 2;
            }
            res = min(res, cur);
        }
        printf("%lld\n", res);
    }
    return 0;
}