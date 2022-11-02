#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n;
const int maxn = 5005;
int x[maxn], y[maxn];

const double pi = acos(-1);

typedef long long db;

const db EPS = 0;

inline int sign(db a){
    return a < -EPS ? -1 : a > EPS;
}

inline int cmp(db a, db b){
    return sign(a-b);
}

struct P{
    db x, y;
    P(){}
    P(db _x, db _y):x(_x), y(_y){}
    P operator + (P p) {return P(x+p.x, y+p.y);}
    P operator - (P p) {return P(x-p.x, y-p.y);}
    P operator * (db d) {return P(x*d, y*d);}
    P operator / (db d) {return P(x/d, y/d);}
    bool operator < (P p) const{
        int c = cmp(x, p.x);
        if(c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    db dot(P p){return x*p.x + y*p.y;}
    db det(P p){return x*p.y - y*p.x;}
    db distTo(P p){return (*this-p).abs();}
    db abs(){return sqrt(abs2());}
    db abs2(){return x*x + y*y;}
    P rot90(){return P(-y, x);}
    void read(){cin >> x >> y;}
    db alpha(){return atan2(y, x);}
    int quad() const{
        return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0);
    }
    int sgn()const{
        return x ? x > 0 : y > 0;
    }
}p[maxn];

bool cmp1(P a, P b){
    if(a.sgn() != b.sgn()) return a.sgn() > b.sgn();
    else
        return a.det(b) > 0;
}


int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    long long ans = 0;
    long long tmp = 1LL * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    for(int i = 1;i <= n;i++){
        ans += tmp;
        int m = 0;
        for(int j = 1;j <= n;j++){
            if(j == i)
                continue;
            p[++m] = P(x[j] - x[i], y[j] - y[i]);
        } 
        sort(p + 1, p + 1 + m, cmp1);
        for(int j = 1;j <= m;j++){
            p[j + m] = p[j];
        }
        //if(i == 1){
        //    cout << "!!!" << endl;
        //    for(int j = 1;j <= m;j++){
        //        cout << p[j].x << " " << p[j].y << endl;
        //    }
        //}
        int l = 1;
        for(int j = 1;j <= 2 * m;j++){
            l = max(l, j - m + 1);
            while(p[j].det(p[l]) > 0){
                l++;
            } 
            if(j > m){
                int num = j - l + 1;
                //cout << j << " " << l << endl;
                ans -= 1LL * (num - 1) * (num - 2) * (num - 3) / 6;
            }
        }
    }
    cout << ans << endl;
    return 0;
}