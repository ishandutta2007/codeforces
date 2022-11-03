//
//  main.cpp
//  A
//
//  Created by  on 16/4/9.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool is_prime[10000];
int prime[10000];
int cnt;

void prime_table(){
    memset(is_prime,true,sizeof(is_prime));
    is_prime[1] = false;
    cnt = 0;
    for(int i = 2;i < 10000;i++) if(is_prime[i]){
        prime[cnt++] = i;
        for(int j = i * 2;j < 10000;j += i){
            is_prime[j] = false;
        }
    }
}

int n;

const int maxn = 1005;

int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a%b);
}

int a[maxn];
int b[maxn];

int main(int argc, const char * argv[]) {
    prime_table();
    cin >> n;
    for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
    memset(b,0,sizeof(b));
    int k = 0;
    for(int i = 1;i < n;i++){
        if(gcd(a[i],a[i + 1]) > 1){
            for(int j = 0;j < cnt;j++){
                if(a[i] % prime[j] != 0 && a[i + 1] % prime[j] != 0){
                    b[i] = prime[j];
                    k++;
                    break;
                }
            }
        }
    }
    cout << k << endl;
    for(int i = 1;i <= n;i++){
        printf("%d ",a[i]);
        if(b[i] > 0){
            printf("%d ",b[i]);
        }
    }
    return 0;
}