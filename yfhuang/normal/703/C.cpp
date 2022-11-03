//
//  main.cpp
//  C
//
//  Created by  on 8/4/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 10005;

typedef long long ll;

int w;

int n;
int v,u;

ll x[maxn],y[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> w >> v >> u;
    for(int i = 1;i <= n;i++) cin >> x[i] >> y[i];
    long long minx = 1e9 + 5,maxx = -1e9 - 5;
    for(int i = 1;i <= n;i++) minx = min(minx,x[i]),maxx = max(maxx,x[i]);
    double ans = 0;
    
    if(minx < 0){//yy
        if(maxx <= 0){
            ans = 1.0 * w / (1.0 * u);
        }else{
            double mink = 1e9 + 5.0;
            int f = 0;
            for(int i = 1;i <= n;i++){
                if(x[i] > 0){
                    if(1.0 * y[i] / (1.0 * x[i]) < mink) mink = 1.0 * y[i] / (1.0 * x[i]),f = i;
                }
            }
            if(u * 1.0 / (1.0 * v) <= mink){
                ans = 1.0 * w / u;
            }else{
                double tmp = 0;
                tmp += 1.0 * x[f] / (1.0  * v);
                for(int i = f ;i < f + n;i++){
                    int num = i % n;
                    if(num == 0) num = n;
                    int num1 = (i + 1) % n;
                    if(num1 == 0) num1 = n;
                    if(x[num1] <= x[num] || 1.0 * (y[num1] - y[num]) / (1.0 * x[num1] - 1.0 * x[num]) >= 1.0 * u / (1.0 * v) ){tmp += 1.0 * (w - y[num]) / (1.0 * u);break;}
                    else{
                        tmp += 1.0 * (x[num1] - x[num]) / (1.0 * v);
                    }
                }
                ans = tmp;
            }
        }
    }else if(minx > 0){
        double mink = 1e9 + 5.0,maxk = -1e9 - 5.0;
        for(int i = 1;i <= n;i++){
            maxk = max(maxk,1.0 * y[i] / (1.0 * x[i]));
        }
        int f = 0;
        for(int i = 1;i <= n;i++){
            if(x[i] > 0){
                if(1.0 * y[i] / (1.0 * x[i]) < mink) mink = 1.0 * y[i] / (1.0 * x[i]),f = i;
            }
        }
        double tmp = 0;
        if(u * 1.0 / (1.0 * v) <= mink){
            tmp = 1.0 * w / u;
        }else{
            tmp = 0;
            tmp += 1.0 * x[f] / (1.0  * v);
            for(int i = f ;i < f + n;i++){
                int num = i % n;
                if(num == 0) num = n;
                int num1 = (i + 1) % n;
                if(num1 == 0) num1 = n;
                if(x[num1] <= x[num] || 1.0 * (y[num1] - y[num]) / (1.0 * x[num1] - 1.0 * x[num]) >= 1.0 * u / (1.0 * v) ){tmp += 1.0 * (w - y[num]) / (1.0 * u);break;}
                else{
                    tmp += 1.0 * (x[num1] - x[num]) / (1.0 * v);
                }
            }
        }
        //cout << tmp << endl;
        if(maxk <= 1.0 * u / (1.0 * v)){
            double t1 = 1.0 * w / u;
            ans = min(t1,tmp);
        }else{
            ans = tmp;
        }
    }else{
        bool flag = true;
        for(int i = 1;i <= n;i++){
            if(x[i] == 0 && y[i] != 0) flag = false;
        }
        if(flag) ans = (1.0 * w) / (1.0 * u);
        else{
            if(maxx <= 0){
                ans = 1.0 * w / (1.0 * u);
            }else{
                double mink = 1e9 + 5.0;
                int f = 0;
                for(int i = 1;i <= n;i++){
                    if(x[i] > 0){
                        if(1.0 * y[i] / (1.0 * x[i]) < mink) mink = 1.0 * y[i] / (1.0 * x[i]),f = i;
                    }
                }
                if(u * 1.0 / (1.0 * v) <= mink){
                    ans = 1.0 * w / u;
                }else{
                    double tmp = 0;
                    tmp += 1.0 * x[f] / (1.0  * v);
                    for(int i = f ;i < f + n;i++){
                        int num = i % n;
                        if(num == 0) num = n;
                        int num1 = (i + 1) % n;
                        if(num1 == 0) num1 = n;
                        if(x[num1] <= x[num] || 1.0 * (y[num1] - y[num]) / (1.0 * x[num1] - 1.0 * x[num]) >= 1.0 * u / (1.0 * v) ){tmp += 1.0 * (w - y[num]) / (1.0 * u);break;}
                        else{
                            tmp += 1.0 * (x[num1] - x[num]) / (1.0 * v);
                        }
                    }
                    ans = tmp;
                }
            }

        }
    }
    printf("%.10lf\n",ans);
    return 0;
}