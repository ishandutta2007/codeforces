#include <bits/stdc++.h>
using namespace std;

typedef pair <long long, long long> point;

point operator-(const point& a, const point& b){
    return make_pair(a.first - b.first, a.second - b.second);
}
long long cross(const point& a, const point& b){
    return a.first * b.second - a.second * b.first;
}
double cross(const point& a, const pair <double, double>& b){
    return a.first * b.second - a.second * b.first;
}
double len(const point& a){
    return sqrt(a.first * a.first + a.second * a.second);
}

int main(){
    int n, H;
    scanf("%d %d", &n, &H);

    vector <point> v(n);
    for(int i = 0; i < n; i++)
        scanf("%lld %lld", &v[i].first, &v[i].second);

    double res = 0.0;
    point o = make_pair(v.back().first, v.back().second + H), r = v.back();

    for(int i = n - 2; i >= 0; i--){
        if(cross(r - o, v[i] - o) > 0)continue;

        if(cross(r - o, v[i] - o) == 0){
            if(cross(r - o, v[i + 1] - o) == 0)
                res += len(v[i] - v[i + 1]);
            continue;
        }

        point d = v[i] - v[i + 1];
        double dlen = len(d);
        pair <double, double> dnorm = make_pair(d.first / dlen, d.second / dlen);

        double c0 = cross(r - o, v[i + 1] - o);
        double cdelta = cross(r - o, dnorm);
        double t = -c0 / cdelta;
        res += dlen - t;

        r = v[i];
    }

    printf("%.10f\n", res);

    return 0;
}