#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

typedef long long db;

inline int sign(db a){
    return a < 0 ? -1 : a > 0;
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
        if(x == p.x)
            return y < p.y;
        else
            return x < p.x;
    }
    db dot(P p){return x*p.x + y*p.y;}
    db det(P p){return x*p.y - y*p.x;}
    db distTo(P p){return (*this-p).abs();}
    db abs(){return sqrt(abs2());}
    db abs2(){return x*x + y*y;}
    P rot90(){return P(-y, x);}
    void read(){cin >> x >> y;}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

vector<P> convexHull(vector<P> ps){
    int n = ps.size();
    if(n <= 1) return ps;
    sort(ps.begin(), ps.end());
    vector<P> qs(n*2); int k = 0;
    for(int i = 0;i < n;qs[k++] = ps[i++]){
        while(k > 1 && crossOp(qs[k-2], qs[k-1], ps[i]) <= 0) --k;
    }
    for(int i = n - 2, t = k;i >= 0;qs[k++] = ps[i--]){
        while(k > t && crossOp(qs[k-2], qs[k-1], ps[i]) <= 0) --k;
    }
    qs.resize(k-1);
    return qs;
}

int n, m;

vector<P> p, q;

const db offset = 1e18;

const int maxn = 1e6 + 5;

int fail[maxn];

db S[maxn], T[maxn];

void init(){
    for(int i = 0;i < n;i++){
        int j = (i + 1) % n;
        int k = (i + n - 1) % n;
        S[i*3] = (p[i] - p[k]).det(p[j] - p[i]);
        S[i*3+1] = (p[j] - p[i]).abs2() + offset;
        S[i*3+2] = (p[i] - p[k]).dot(p[j] - p[i]) + offset * 2;
        //cout << S[i * 2] << " " << S[i * 2 + 1] << " ";
        //cout << (p[i] - p[k]).x << " " << (p[i] - p[k]).y << " ";
        //cout << (p[j] - p[i]).x << " " << (p[j] - p[i]).y << " ";
        //cout << endl;
    }
    cout << endl;
    for(int i = 0;i < m;i++){
        int j = (i + 1) % n;
        int k = (i + n - 1) % n;
        T[i*3] = (q[i] - q[k]).det(q[j] - q[i]);
        T[i*3+1] = (q[j] - q[i]).abs2() + offset;
        T[i*3+2] = (q[i] - q[k]).dot(q[j] - q[i]) + offset * 2;
        //cout << T[i * 2] << " " << T[i * 2 + 1] << " ";
        //cout << (q[i] - q[k]).x << " " << (q[i] - q[k]).y << endl;
    }
    //cout << endl;
    for(int i = 3 * n;i < 6 * n;i++){
        S[i] = S[i - 3 * n];
    }
}

void cal_fail(){
    int len = 0;
    fail[0] = fail[1] = 0;
    for(int i = 1;i < 3 * n;i++){
        while(len > 0 and T[i] != T[len]){
            len = fail[len];
        }
        if(T[i] == T[len])
            len++;
        fail[i + 1] = len;
    }
}

bool search(){
    int len = 0;
    for(int i = 0;i < 6 * n;i++){
        while(len > 0 and S[i] != T[len])
            len = fail[len];
        if(S[i] == T[len])
            len++;
        if(len == 3 * n)
            return true;
    } 
    return false;
}

bool solve(){
    n = p.size(), m = q.size();
    if(n != m)
        return false;
    init();    
    cal_fail();
    return search();
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        P point;
        point.read();
        p.push_back(point);
    } 
    for(int i = 1;i <= m;i++){
        P point;
        point.read();
        q.push_back(point);
    }
    //cout << p.size() << " " << q.size() << endl;
    p = convexHull(p);
    q = convexHull(q);
    //for(int i = 0;i < p.size();i++){
    //    cout << p[i].x << " " << p[i].y << endl;
    //}
    //for(int i = 0;i < q.size();i++){
    //    cout << q[i].x << " " << q[i].y << endl;
    //}
    //cout << p.size() << " " << q.size() << endl;
    if(solve()){
        puts("YES");
    }else{
        puts("NO");
    }
    return 0;
}