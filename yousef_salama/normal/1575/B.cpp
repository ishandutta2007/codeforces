#include <bits/stdc++.h>
using namespace std;

double PI = acos(-1);

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector < pair <int, int> > v;
    for(int i = 0; i < n; i++){
        pair <int, int> p;
        scanf("%d %d", &p.first, &p.second);

        if(p.first == 0 && p.second == 0){
            k--;
        }else{
            v.push_back(p);
        }
    }

    auto check = [&](double r){
        if(k <= 0)return true;
        
        vector < pair <double, int> > evs;

        for(auto[x, y] : v){
            double d = sqrt(1.0 * x * x + 1.0 * y * y);
            double phi = atan2(y, x);

            if(d > 2.0 * r)continue;

            double z = acos(d / (2.0 * r));
            evs.push_back(make_pair(phi - z, 1));
            evs.push_back(make_pair(phi + z, -1));
            evs.push_back(make_pair(phi - z + 2.0 * PI, 1));
            evs.push_back(make_pair(phi + z + 2.0 * PI, -1));
        }
        sort(evs.begin(), evs.end());

        int cnt = 0;
        for(auto[angle, delta] : evs){
            cnt += delta;
            if(cnt >= k)return true;
        }
        return false;
    };

    double L = 0.0, R = 200005;
    while(fabs(R - L) > 1e-9){
        double mid = (L + R) / 2.0;

        if(check(mid))R = mid;
        else L = mid;
    }
    printf("%.10f\n", L);



    return 0;
}