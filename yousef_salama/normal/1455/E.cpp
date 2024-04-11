#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        vector < pair <long long, long long> > v(4);
        for(int i = 0; i < 4; i++)scanf("%lld %lld", &v[i].first, &v[i].second);

        vector <int> p = {0, 1, 2, 3};
        long long res = 1LL << 50;

        do{
            auto[x1, x2, x3, x4] = make_tuple(v[p[0]].first, v[p[1]].first, v[p[2]].first, v[p[3]].first);
            auto[y1, y2, y3, y4] = make_tuple(v[p[0]].second, v[p[2]].second, v[p[1]].second, v[p[3]].second);

            long long cur = abs(x1 - x2) + abs(x3 - x4) + abs(y1 - y2) + abs(y3 - y4);

            if(x2 < x1)swap(x1, x2);
            if(x4 < x3)swap(x3, x4);
            if(y2 < y1)swap(y1, y2);
            if(y4 < y3)swap(y3, y4);

            long long lx, rx, ly, ry;
            
            if(x2 < x3 || x4 < x1){
                if(x2 < x3){
                    lx = x3 - x2;
                    rx = x4 - x1;
                }else{
                    lx = x1 - x4;
                    rx = x2 - x3;
                }
            }else{
                lx = 0;
                rx = max(x4 - x1, x2 - x3);
            }
            
            if(y2 < y3 || y4 < y1){
                if(y2 < y3){
                    ly = y3 - y2;
                    ry = y4 - y1;
                }else{
                    ly = y1 - y4;
                    ry = y2 - y3;
                }
            }else{
                ly = 0;
                ry = max(y4 - y1, y2 - y3);
            }

            if(ry < lx || rx < ly){
                if(ry < lx)cur += 2LL * (lx - ry);
                else cur += 2LL * (ly - rx);
            }

            res = min(res, cur);
        }while(next_permutation(p.begin(), p.end()));

        printf("%lld\n", res);
    }
    return 0;
}