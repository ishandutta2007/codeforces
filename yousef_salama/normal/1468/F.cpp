#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        map < pair <int, int>, int> mp;
        long long res = 0;

        for(int i = 0; i < n; i++){
            int x, y, u, v;
            scanf("%d %d %d %d", &x, &y, &u, &v);

            u = u - x;
            v = v - y;
            int g = __gcd(abs(u), abs(v));
            u /= g;
            v /= g;

            res += mp[make_pair(-u, -v)];
            mp[make_pair(u, v)]++;
        }
        printf("%lld\n", res);
    }
    return 0;
}