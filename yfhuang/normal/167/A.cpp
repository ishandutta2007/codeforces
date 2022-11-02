#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n;
double a, d;

int main(){
    cin >> n;
    cin >> a >> d;
    double pre = -1;
    for(int i = 1;i <= n;i++){
        double t, v;
        scanf("%lf%lf", &t, &v);
        double time = sqrt(d * 2 / a);
        double ans;
        if(time * a > v){
            time = v / a;
            double dis = time * v / 2;
            ans = (d - dis) / v + time + t;
        }else{
            ans = time + t;
        }
        if(pre == -1){
            pre = ans;
        }else{
            pre = max(pre, ans);
            ans = max(ans, pre);
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}