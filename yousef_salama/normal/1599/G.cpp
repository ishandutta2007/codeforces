#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y, index;
    point(){}
    bool operator<(const point& p) const{
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
    bool operator==(const point& p) const{
        return make_pair(x, y) == make_pair(p.x, p.y);
    }
};

double dist(const point& a, const point& b){
    return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
}
long long cross(long long x, long long y, const point& p){
    return x * p.y - y * p.x;
}
long long dot(long long x, long long y, const point& p){
    return x * p.x + y * p.y;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    k--;

    vector <point> v(n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &v[i].x, &v[i].y);
        v[i].index = i;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    if((int)v.size() == 1){
        printf("0.0\n");
        return 0;
    }
    if((int)v.size() == 2){
        printf("%.10f\n", dist(v[0], v[1]));
        return 0;
    }

    bool found = false;
    int dx, dy;

    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            int cx = v[j].x - v[i].x, cy = v[j].y - v[i].y;
            
            set <long long> s;
            for(int k = 0; k < (int)v.size(); k++){
                s.insert(cross(cx, cy, v[k]));
            }

            if((int)s.size() <= 2){
                dx = cx, dy = cy;
                found = true;
                break;
            }
        }
        if(found)break;
    }

    map <long long, int> mp; 
    for(int i = 0; i < (int)v.size(); i++)
        mp[cross(dx, dy, v[i])]++;

    point external = v[0];
    for(int i = 0; i < (int)v.size(); i++)
        if(mp[cross(dx, dy, v[i])] == 1)external = v[i];

    vector <point> line;
    for(int i = 0; i < (int)v.size(); i++)
        if(v[i].index != external.index)line.push_back(v[i]);

    sort(line.begin(), line.end(), [&](const point& a, const point& b){
        return dot(dx, dy, a) < dot(dx, dy, b);
    });

    auto calc_from_external = [&](int L, int R){
        if(L > R)return 0.0;
        return min(dist(external, line[L]) + dist(line[L], line[R]), dist(external, line[R]) + dist(line[R], line[L]));
    };

    if(external.index == k){
        printf("%.10f\n", calc_from_external(0, (int)line.size() - 1));
        return 0;
    }

    int st;
    for(int i = 0; i < (int)line.size(); i++)
        if(line[i].index == k)st = i;

    double res = dist(line[st], external) + calc_from_external(0, (int)line.size() - 1);

    for(int i = st; i < (int)line.size(); i++){
        double line_dist = min(dist(line[st], line[i]) + dist(line[i], line[0]) + dist(line[0], external), 
                                dist(line[st], line[0]) + dist(line[0], line[i]) + dist(line[i], external));
        res = min(res, line_dist + calc_from_external(i + 1, (int)line.size() - 1));
    }

    for(int i = st; i >= 0; i--){
        double line_dist = min(dist(line[st], line[i]) + dist(line[i], line.back()) + dist(line.back(), external), 
                                dist(line[st], line.back()) + dist(line.back(), line[i]) + dist(line[i], external));
        res = min(res, line_dist + calc_from_external(0, i - 1));
    }

    printf("%.10f\n", res);

    return 0;
}