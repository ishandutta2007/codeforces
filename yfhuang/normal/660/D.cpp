//
//  main.cpp
//  D
//
//  Created by  on 16/4/9.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int n;

const int maxn = 2005;

typedef long long ll;

map<pair<ll,double>,int> ma;

ll x[maxn],y[maxn];

long long sqr(long long r){
    return r * r;
}

int main(){
    int n;
    cin >> n;
    ma.clear();
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        cin >> x[i] >> y[i];
        for(int j = 1;j < i;j++){
            long long dis = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
            double k;
            if(x[i] == x[j]) k = 1e18;
            else k = 1.0 * (y[j] - y[i]) /  (x[j] - x[i]);
            ans += (long long)ma[make_pair(dis,k)];
            ma[make_pair(dis,k)]++;
        }
    }
    ans /= 2;
    cout << ans << endl;
    
}