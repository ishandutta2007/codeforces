#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);

        vector <int> a(n);
        for(int i = 0; i < n; i++)scanf("%d", &a[i]);

        long long res = -1LL << 60;
        for(int i = max(0, n - 110); i < n; i++)
        for(int j = i + 1; j < n; j++)
            res = max(res, 1LL * (i + 1) * (j + 1) - 1LL * k * (a[i] | a[j]));

        printf("%lld\n", res);
    }

    return 0;
}