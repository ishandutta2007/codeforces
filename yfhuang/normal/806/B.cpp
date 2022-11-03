//
//  main.cpp
//  B
//
//  Created by  on 2017/5/8.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>


using namespace std;

int n;

int a[150][5];
int num[5];

int fen(int x,int y){
    if(2LL * x > y) return 500;
    if(4LL * x > y) return 1000;
    if(8LL * x > y) return 1500;
    if(16LL * x > y) return 2000;
    if(32LL * x > y) return 2500;
    return 3000;
}

long long check(int x){
    long long ret = 0;
    for(int i = 0;i < 5;i++){
        if(a[1][i] < a[2][i]){
            ret += fen(num[i],n + x) - fen(num[i],n + x) / 250 * a[1][i];
            if(a[2][i] != 1e9){
                ret -= fen(num[i],n + x) - fen(num[i],n + x) / 250 * a[2][i];
            }
        }else if(a[1][i] > a[2][i]){
            if(a[1][i] != 1e9){
                ret += fen(num[i] + x,n + x) - fen(num[i] + x,n + x) / 250 * a[1][i] - fen(num[i] + x,n + x) + fen(num[i] + x,n + x) / 250 * a[2][i];
            }else{
                ret -= fen(num[i],n + x) - fen(num[i],n + x) / 250 * a[2][i];
            }
        }
    }
    return ret ;
}


int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 5;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j] != -1) num[j]++;
            else a[i][j] = 1e9;
        }
    }
    for(int i = 0;i <= 5000;i++){
        if(check(i) > 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}