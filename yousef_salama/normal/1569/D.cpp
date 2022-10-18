#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        vector <int> x(n);
        for(int i = 0; i < n; i++)scanf("%d", &x[i]);

        vector <int> y(m);
        for(int i = 0; i < m; i++)scanf("%d", &y[i]);

        long long res = 0;
        map <int, int> cnt_x, cnt_y;
        map < pair <int, int>, int> sub_x, sub_y;

        for(int i = 0; i < k; i++){
            int xp, yp;
            scanf("%d %d", &xp, &yp);

            int xi = *lower_bound(x.begin(), x.end(), xp);
            int yi = *lower_bound(y.begin(), y.end(), yp);

            if(xi == xp && yi == yp)continue;

            if(xi == xp){
                res += cnt_y[yi];
                res -= sub_y[make_pair(yi, xp)];

                cnt_y[yi]++;
                sub_y[make_pair(yi, xp)]++;
            }else{
                res += cnt_x[xi];
                res -= sub_x[make_pair(xi, yp)];

                cnt_x[xi]++;
                sub_x[make_pair(xi, yp)]++;
            }
        }

        printf("%lld\n", res);
    }

    return 0;
}