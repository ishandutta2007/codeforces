#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const int MAXN = 2000000;

double normalize_angle(double angle){
    while(angle >= 2.0 * PI)angle -= 2.0 * PI;
    while(angle < 0.0)angle += 2.0 * PI;
    return angle;
}

int main(){
    int n, d;
    scanf("%d %d", &n, &d);

    vector < pair <double, int> > evs;

    for(int i = 0; i < n; i++){
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);

        double angle = normalize_angle(atan2(y, x));
        double len = sqrt(1.0 * x * x + 1.0 * y * y);
        int p = int(len);

        for(int j = -52; j <= 52; j++){
            if((p + j) < 0 || (p + j) % d != 0)continue;
            if(fabs(p + j - len) - eps > r)continue;

            double z = (1.0 * x * x + 1.0 * y * y + 1.0 * (p + j) * (p + j) - 1.0 * r * r) / (2.0 * len * (p + j));
            double intersection_angle = acos(clamp(z, -1.0, 1.0));

            double L = normalize_angle(-angle - intersection_angle);

            evs.push_back(make_pair(L, 1));
            evs.push_back(make_pair(L + 2.0 * intersection_angle + eps, -1));
            
            evs.push_back(make_pair(L + 2.0 * PI, 1));
            evs.push_back(make_pair(L + 2.0 * intersection_angle + 2.0 * PI + eps, -1));
        }
    }

    int res = 0, cur = 0;
    sort(evs.begin(), evs.end());

    for(pair <double, int> u : evs){
        cur += u.second;
        res = max(res, cur);
    }
    
    printf("%d\n", res);

    return 0;
}