#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for(int i = 0; i < n; i++)scanf("%d", &a[i]);

        long long res = 0;
        for(int i = 0; i + 1 < n; i++)
            res = max(res, 1LL * max(a[i], a[i + 1]) * min(a[i], a[i + 1]));
        printf("%lld\n", res);
    }

    return 0;
}