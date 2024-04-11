#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> perm(n), val(n);
        
        iota(perm.begin(), perm.end(), 1);
        shuffle(perm.begin(), perm.end(), rng);

        auto query_max = [&](int i, int j, int x){
            printf("? 1 %d %d %d\n", i, j, x);
            fflush(stdout);

            int r;
            scanf("%d", &r);
            return r;
        };

        auto query_min = [&](int i, int j, int x){
            printf("? 2 %d %d %d\n", i, j, x);
            fflush(stdout);

            int r;
            scanf("%d", &r);
            return r;
        };
        

        int l = 1, r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;

            if(query_max(perm[1], perm[0], mid - 1) == mid)l = mid;
            else r = mid - 1;
        }
        val[0] = l;

        int c = 0;
        for(int i = 1; i < n; i++){
            int r = query_max(perm[c], perm[i], n - 1);
            if(r > val[c]){
                val[i] = r;
            }else{
                val[i] = query_min(perm[i], perm[c], 1);
                c = i;
            }
        }
        
        vector <int> res(n);
        for(int i = 0; i < n; i++)res[perm[i] - 1] = val[i];

        printf("!");
        for(int i = 0; i < n; i++)printf(" %d", res[i]);
        printf("\n");
        
        fflush(stdout);
    }
    return 0;
}