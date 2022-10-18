#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

double zabat(double x){
    if(x < eps)return 0.0;
    else return x;
}
double solve(double c, double m, double p, double v){
    //printf("%.6f %.6f %.6f %.6f\n", c, m, p, v);
    
    if(c == 0.0 && m == 0.0){
        return 1.0;
    }else if(c == 0.0){
        return 1.0 + m * solve(c, zabat(m - v), p + min(v, m), v);
    }else if(m == 0.0){
        return 1.0 + c * solve(zabat(c - v), m, p + min(v, c), v);
    }else{
        double ret = 1.0;
        ret += c * solve(zabat(c - v), m + min(v, c) / 2.0, p + min(v, c) / 2.0, v);
        ret += m * solve(c + min(v, m) / 2.0, zabat(m - v), p + min(v, m) / 2.0, v);
        return ret;
    }
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        double c, m, p, v;
        cin >> c >> m >> p >> v;
        
        printf("%.12f\n", solve(c, m, p, v));
    }
    return 0;
}