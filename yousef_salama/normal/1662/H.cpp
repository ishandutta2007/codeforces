#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        long long w, l;
        scanf("%lld %lld", &w, &l);

        long long b = 2 * (w + l - 2);

        auto can = [&](long long d) -> bool {
            if(d == 1 || d == 2)return true;

            if(w % d == 1 && l % d == 1)return true;

            if(w % d == 0 && l % d == 2)return true;

            if(w % d == 2 && l % d == 0)return true;

            return false;
        };

        vector <long long> v;

        for(long long d = 1; d * d <= b; d++)if(b % d == 0){
            if(can(d))v.push_back(d);
            if(b / d > d && can(b / d))v.push_back(b / d);
        }

        sort(v.begin(), v.end());

        printf("%d", (int)v.size());
        for(long long d : v)
            printf(" %lld", d);
        printf("\n");
    }

    return 0;
}