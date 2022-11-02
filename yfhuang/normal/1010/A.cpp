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

using namespace std;

int n;
int m;

const int maxn = 1005;

int a[maxn], b[maxn];

bool check(double fuel){
    for(int i = 0;i < n;i++){
        if(m + fuel > a[i] * fuel){
            return false;
        }
        double cost = (m + fuel) / a[i];
        fuel -= cost;
        int j = (i + 1) % n;
        if(m + fuel > b[j] * fuel){
            return false;
        }
        cost = (m + fuel) / b[j];
        fuel -= cost;
    }
    return true;
}

int main(){
    cin >> n;
    cin >> m;
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0;i < n;i++){
        scanf("%d", &b[i]);
    }
    double l = 0, r = 1e9 + 7;
    for(int i = 1;i <= 200;i++){
        double mid = (l + r) / 2;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    if(l <= 1e9){
        printf("%.10lf\n", l);
    }else{
        puts("-1");
    }
    return 0;
}